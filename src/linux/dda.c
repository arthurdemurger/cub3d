/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:29:17 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/27 12:41:54 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	is_corner(int x, int y)
{
	if (!(y % SIZE) && !(x % SIZE))
		return (1);
	else if (!(y % SIZE) && !((x + 1) % SIZE))
		return (2);
	else if (!(x % SIZE) && !((y + 1) % SIZE))
		return (3);
	else if (!((x + 1) % SIZE) && !((y + 1) % SIZE))
		return (4);
	return (0);
}

int	check_walls(t_vector plr, float *floats)
{
	int	corner;

	corner = is_corner(floorf(floats[0]), floorf(floats[1]));
	if (corner == 1)
		return (north_west(plr, floats));
	else if (corner == 2)
		return (north_east(plr, floats));
	else if (corner == 3)
		return (south_west(plr, floats));
	else if (corner == 4)
		return (south_east(plr, floats));
	if (!((int)floorf(floats[1]) % SIZE))
		return (NORTH);
	else if (!((int)floorf(floats[0]) % SIZE))
		return (WEST);
	else if (!((int)(floorf(floats[0]) + 1) % SIZE))
		return (EAST);
	return (SOUTH);
}

float	distance(t_cub cub, float *floats)
{
	float 	dx;
	float 	dy;

	dx = cub.plr.real_x - floats[0];
	dy = cub.plr.real_y - floats[1];
	return (sqrt(pow(dx, 2) + pow(dy, 2)));
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

void expand_ray(t_cub *cub, t_ray *ray)
{
	float	rad;
	int		i;
	float	floats[4];

	rad = ray->angle * (M_PI / 180);
	i = 0;
	while (1)
	{
		floats[0] = cub->plr.real_x + (i * cos(rad));
		floats[1] = cub->plr.real_y + (i * sin(rad));
		if (cub->map.map[(int)(floats[1] / SIZE)][(int)(floats[0] / SIZE)] == '1')
		{
			ray->side = check_walls(cub->plr, floats);
			ray->l = distance(*cub, floats);
			break ;
		}
		floats[2] = floats[0];
		floats[3] = floats[1];
		my_mlx_pixel_put(&cub->img_map, round(floats[0]) / MAP_DIV, round(floats[1]) / MAP_DIV, GREEN);
		i++;
	}
}
