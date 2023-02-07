/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:29:17 by ademurge          #+#    #+#             */
/*   Updated: 2023/02/07 12:40:24 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	is_corner(int x, int y)
{
	if (y % SIZE == 0 && x % SIZE == 0)
		return (1);
	else if (y % SIZE == 0 && (x + 1) % SIZE == 0)
		return (2);
	else if (x % SIZE == 0 && (y + 1) % SIZE == 0)
		return (3);
	else if ((x + 1) % SIZE == 0 && (y + 1) % SIZE == 0)
		return (4);
	return (0);
}

int	check_walls(t_cub *cub, float *floats, float angle)
{
	int	corner;
	int	x;
	int	y;

	x = (int)floorf(floats[0]);
	y = (int)floorf(floats[1]);
	corner = is_corner(x, y);
	if (corner == 1)
		return (north_west(cub->plr, floats, cub->map.map, angle));
	else if (corner == 2)
		return (north_east(cub->plr, floats, cub->map.map, angle));
	else if (corner == 3)
		return (south_west(cub->plr, floats, cub->map.map, angle));
	else if (corner == 4)
		return (south_east(cub->plr, floats, cub->map.map, angle));
	if (x % SIZE == 0)
		return (WEST);
	else if ((x + 1) % SIZE == 0)
		return (EAST);
	else if (y % SIZE == 0)
		return (NORTH);
	return (SOUTH);
}

float	distance(t_cub cub, float *floats)
{
	float 	dx;
	float 	dy;

	dx = cub.plr.real_x - floorf(floats[0]);
	dy = cub.plr.real_y - floorf(floats[1]);
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

int	get_col(t_ray ray, float x, float y)
{
	float	pos;

	if (ray.side == WEST || ray.side == EAST)
		pos = y - (floorf(floorf(y) / SIZE) * SIZE);
	else
		pos = x - (floorf(floorf(x) / SIZE) * SIZE);
	return (pos * 4);
}

int	is_wall(int *ints, char **map, float angle)
{
	if (map[ints[1] / SIZE][ints[0] / SIZE] == '1')
		return (1);
	else if (angle > 180 && angle < 270 && map[ints[1] / SIZE][(ints[0] + 1) / SIZE] && map[(ints[1] + 1) / SIZE][ints[0] / SIZE] == '1')
		return (1);
	else if (angle > 270 && map[ints[1] / SIZE][(ints[0] - 1) / SIZE] && map[(ints[1] + 1) / SIZE][ints[0] / SIZE] == '1')
		return (1);
	else if (angle > 90 && angle < 180 && map[ints[1] / SIZE][(ints[0] + 1) / SIZE] && map[(ints[1] - 1) / SIZE][ints[0] / SIZE] == '1')
		return (1);
	else if (angle < 90 && map[ints[1] / SIZE][(ints[0] - 1) / SIZE] && map[(ints[1] - 1) / SIZE][ints[0] / SIZE] == '1')
		return (1);
	return (0);
}

void expand_ray(t_cub *cub, t_ray *ray)
{
	float	rad;
	int		i;
	float	floats[2];
	int		ints[2];

	rad = ray->angle * (M_PI / 180);
	i = 0;
	while (1)
	{
		floats[0] = cub->plr.real_x + (i * cos(rad));
		floats[1] = cub->plr.real_y + (i * sin(rad));
		ints[0] = (int)floorf(floats[0]);
		ints[1] = (int)floorf(floats[1]);
		if (is_wall(ints, cub->map.map, ray->angle))
		{
			ray->l = distance(*cub, floats);
			ray->side = check_walls(cub, floats, ray->angle);
			ray->col = get_col(*ray, floats[0], floats[1]);
			break ;
		}
		my_mlx_pixel_put(&cub->img_map, round(floats[0]) / MAP_DIV, round(floats[1]) / MAP_DIV, GREEN);
		i++;
	}
}
