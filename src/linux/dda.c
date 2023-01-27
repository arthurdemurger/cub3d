/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:29:17 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/27 11:26:18 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	corner(int x, int y)
{
	if (!(x % SIZE) && !(x % (SIZE - 1)) && !(y % SIZE) && !(y % (SIZE - 1)))
		return (2);
	else if ((x % SIZE) && !(x % (SIZE - 1)) && !(y % SIZE) && !(y % (SIZE - 1)))
		return (1);
	else if (!(y % SIZE) && !(y % (SIZE - 1)) && !(x % SIZE) && !(x % (SIZE - 1)))
		return (1);
	else if ((x % SIZE) && (y % SIZE) && !(x % (SIZE - 1)) && !(y % (SIZE - 1)))
		return (1);
	return (0);
}

void	check_walls(int x, int y, t_ray *ray)
{
	if (corner(x, y) == 2)
		ICI
	if (corner(x, y))
		ray->face = 5;
	else if (!(y % SIZE) && !(y % (SIZE - 1)) && (x % (SIZE - 1)))
		ray->face = NORTH;
	else if (!(x % SIZE) && !(x % (SIZE - 1)) && (y % (SIZE - 1)))
		ray->face = WEST;
	else if (!(x % (SIZE - 1)) && (x % SIZE) && (y % (SIZE - 1)))
		ray->face = EAST;
	else if (!(y % SIZE - 1) && (y % SIZE) && (x % (SIZE - 1)))
		ray->face = SOUTH;
	// if (cub->map.map[y / SIZE][x / SIZE] == '1')
	// {
	// 	if (!(x % SIZE) && !(y % SIZE))
	// 		return (5);
	// 	if (cub->angle >= 270.00000000 && cub->angle <= 360.00000000)
	// 	{
	// 		if (!(x % SIZE))
	// 			return (WEST);
	// 		else if (!((y + 1) % SIZE))
	// 			return (SOUTH);
	// 	}
	// 	if (cub->angle >= 180.00000000 && cub->angle <= 270.00000000)
	// 	{
	// 		if (!((x + 1) % SIZE))
	// 			return (EAST);
	// 		else if (!((y + 1) % SIZE))
	// 			return (SOUTH);
	// 	}
	// 	if (cub->angle >= 90.00000000 && cub->angle <= 180.00000000)
	// 	{
	// 		if (!((x + 1) % SIZE))
	// 			return (EAST);
	// 		else if (!(y % SIZE))
	// 			return (NORTH);
	// 	}
	// 	if (cub->angle >= 0.00000000 && cub->angle <= 90.00000000)
	// 	{
	// 		if (!(x % SIZE))
	// 			return (WEST);
	// 		else if (!(y % SIZE))
	// 			return (NORTH);
	// 	}
	// }
	// return (0);
}

int abs(int n)
{
	if (n > 0)
		return (n);
	return (-n);
}

// void dda(t_cub *cub, int x, int y, int color, int ray)
// {
// 	t_pos	delta;
// 	int		i;
// 	int 	steps;
// 	float	fl_x;
// 	float	fl_y;

// 	(void)ray;
// 	delta.x = x - cub->plr.real_x;
// 	delta.y = y - cub->plr.real_y;
// 	if (abs(delta.x) > abs(delta.y))
// 		steps = abs(delta.x);
// 	else
// 		steps = abs(delta.y);
// 	fl_x = cub->plr.real_x;
// 	fl_y = cub->plr.real_y;
// 	i = 0;
// 	while (i++ <= steps)
// 	{
// 		cub->rays[ray].face = check_walls(round(fl_x), round(fl_y), cub);
// 		if (cub->rays[ray].face)
// 			break ;
// 		my_mlx_pixel_put(&cub->img_map, round(fl_x), round(fl_y), color);
//         fl_x += (delta.x / (float)steps);
//         fl_y += (delta.y / (float)steps);
//     }
// }

float	distance(int x1, int y1, int x2, int y2)
{
	int dx;
	int dy;

	dx = x2 - x1;
	dy = y2 - y1;
	return (sqrtf(pow(dx, 2) + pow(dy, 2)));
}

float	angle(float a, float b)
{
	float	c;
	float	right;

	right = 90;
	c = (atan(a / b)) * (180 / M_PI);
	if (c < 0)
		c = 360 - c;
	return (right - c);
}

float expand_ray(t_cub *cub, t_ray *ray)
{
	double	rad;
	int		i;
	int		x;
	int		y;

	rad = ray->angle * (M_PI / 180);
	i = 0;
	while (1)
	{
		x = cub->plr.real_x + (i * cos(rad));
		y = cub->plr.real_y + (i * sin(rad));
		if (cub->map.map[y / SIZE][x / SIZE] == '1')
		{
			check_walls(x, y, ray);
			break ;
		}
		my_mlx_pixel_put(&cub->img_map, round(x) / 4, round(y) / 4, GREEN);
		i++;
	}
	return (distance(cub->plr.real_x, cub->plr.real_y, x, y));
}