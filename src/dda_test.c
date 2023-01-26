/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:29:17 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/24 18:38:25 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"


// void    check_walls_h(int x, int y, t_ray *ray)
// {
// 	if ()
// 		ray->x1_x = x;
// 	if ()
// 		ray->x2_x = x;
// 	if (i == 2)
// 	{
		
// 	}
// }

// void    check_walls_v(int x, int y, t_ray *ray)
// {
// 	if (i == 0 && !(y % SIZE))
// 		ray->x1_x = x;
// 	if (i == 1 && !(y % SIZE))
// 		ray->x2_x = x;
// 	if (i == 2)
// 	{
		
// 	}
// }

int abs(int n)
{
	if (n > 0)
		return (n);
	return (-n);
}

float	hypo(t_cub *cub, int x, int y)
{
	int	h;
	int	v;

	h = abs(x - cub->plr.real_x);
	v = abs(y - cub->plr.real_y);
	return (sqrt((h * h) + (v * v)));
}

float	check_walls_h(int x, int y, t_cub *cub, t_ray *ray)
{
	static int	i = 1;
	
	if (!ray->x1 && ray->dir < SE && !((y - 1) % SIZE))
		ray->x1 = x;
	else if (!ray->x1 && ray->dir > NE && !(y % SIZE))
		ray->x1 = x;
	if (ray->x1 && ray->dir < SE && !((y - 1) % SIZE))
		ray->x2 = x;
	else if (ray->x1 && ray->dir > NE && !(y % SIZE))
		ray->x2 = x;
	if (ray->x1 && ray->x2 && (!(y - 1) % SIZE || !(y % SIZE)))
	{
		if (!ray->xa)
			ray->xa = ray->x2 - ray->x1;
		else if (ray->dir < SE && cub->map.map[(cub->plr.y - i)][(ray->x2 * (int)ray->xa) / SIZE] == '1')
			return (hypo(cub, cub->plr.real_x + (ray->xa * i), cub->plr.real_y - (SIZE * i) + (cub->plr.real_y % SIZE)));
		else if (ray->dir > NE && cub->map.map[(cub->plr.y + i)][(ray->x2 * (int)ray->xa) / SIZE] == '1')
			return (hypo(cub, cub->plr.real_x + (ray->xa * i), cub->plr.real_y + (SIZE * i) - (cub->plr.real_y % SIZE)));
		i++;
	}
	return (0);
}

float	check_walls_v(int x, int y, t_cub *cub, t_ray *ray)
{
	static int	i = 0;
	
	if (!ray->y1 && (ray->dir == NO || ray->dir == SO) && !((y - 1) % SIZE))
		ray->y1 = x;
	else if (!ray->y1 && (ray->dir == NE || ray->dir == SE) && !(y % SIZE))
		ray->y1 = x;
	if (ray->y1 && (ray->dir == NO || ray->dir == SO) && !((y - 1) % SIZE))
		ray->y2 = x;
	else if (ray->y1 && (ray->dir == NE || ray->dir == SE) && !(y % SIZE))
		ray->y2 = x;
	if (ray->y1 && ray->y2)
	{
		if (!ray->ya)
			ray->ya = ray->y2 - ray->y1;
		else if ((ray->dir == NO || ray->dir == SO) && cub->map.map[(ray->y2 * (int)ray->ya) / SIZE][cub->plr.x - i] == '1')
			return (hypo(cub, cub->plr.real_x - (SIZE * i) + (cub->plr.real_x % SIZE), cub->plr.real_y + (ray->ya * i)));
		else if ((ray->dir == NE || ray->dir == SE) && cub->map.map[(ray->y2 * (int)ray->ya) / SIZE][cub->plr.x + i] == '1')
			return (hypo(cub, cub->plr.real_x + (SIZE * i) - (cub->plr.real_x % SIZE), cub->plr.real_y + (ray->ya * i)));
	}
	return (0);
}

float	ft_fl_min(float a, float b, t_ray *ray)
{
	(void)ray;
	if (a <= b)
	{
		return (a);
	}
	return (b);
}
 
float dda(t_cub *cub, int x, int y, int color, int ray, int draw)
{
	int		delta[2];
	int		i;
	int 	steps;
	float	floats[2];

	(void)draw;
	delta[0] = x - cub->plr.real_x;
	delta[1] = y - cub->plr.real_y;
	if (abs(delta[0]) > abs(delta[1]))
		steps = abs(delta[0]);
	else
		steps = abs(delta[1]);
	floats[0] = cub->plr.real_x;
	floats[1] = cub->plr.real_y;
	i = 0;
	while (i++ <= steps)
	{
		if (!cub->rays[ray].l_h)
			cub->rays[ray].l_h = check_walls_h(round(floats[0]), round(floats[1]), cub, &cub->rays[ray]);
		if (!cub->rays[ray].l_v)
			cub->rays[ray].l_v = check_walls_v(round(floats[0]), round(floats[1]), cub, &cub->rays[ray]);
		if (cub->rays[ray].l_h && cub->rays[ray].l_v)
			return (ft_fl_min(cub->rays[ray].l_h, cub->rays[ray].l_v, &cub->rays[ray]));
		my_mlx_pixel_put(&cub->img_map, round(floats[0]), round(floats[1]), color);
        floats[0] += (delta[0] / (float)steps);
        floats[1] += (delta[1] / (float)steps);
    }
	return (0);
}
