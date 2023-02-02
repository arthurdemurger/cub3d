/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:29:17 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/27 18:05:55 by ademurge         ###   ########.fr       */
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

// int	get_side(float x, float y, int corner)
// {
// 	float	x_dec;
// 	float	y_dec;

// 	printf("x : %f | y : %f\n", x, y);
// 	x_dec = x - floorf(x);
// 	y_dec = y - floorf(y);
// 	if (corner == 1)
// 	{
// 		if (x_dec > y_dec)
// 			return (WEST);
// 		return (NORTH);
// 	}
// 	else if (corner == 2)
// 	{
// 		if (100 - x_dec > y_dec)
// 			return (EAST);
// 		return (NORTH);
// 	}
// 	else if (corner == 3)
// 	{
// 		if (100 - y_dec > x_dec)
// 			return (SOUTH);
// 		return (WEST);
// 	}
// 	if (100 - x_dec > 100 - y_dec)
// 		return (SOUTH);
// 	return (EAST);
// }

// void	display_wall(int side)
// {
// 	if (side == 1)
// 		printf("NORTH\n");
// 	else if (side == 2)
// 		printf("EAST\n");
// 	else if (side == 3)
// 		printf("SOUTH\n");
// 	else if (side == 4)
// 		printf("WEST\n");
// }

int	check_walls_cardinal(int angle)
{
	if (angle == 90)
		return (NORTH);
	else if (angle == 180)
		return (EAST);
	else if (angle == 0)
		return (WEST);
	return (SOUTH);
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

float	absf(float n)
{
	if (n > 0)
		return (n);
	return (-n);
}

float	check_walls_h(t_cub *cub, t_ray *ray, int index, float x, float y)
{
	if (ray->copy_y == -1)
		ray->copy_y = y;
	else if (absf(floorf(y) - floorf(ray->copy_y)) >= 1 && ray->x1 == -1)
	{
		ray->x1 = x;
		ray->copy_y = y;
	}
	else if (absf(floor(y) - floor(ray->copy_y)) >= SIZE)
	{
		ray->x2 = x;
		ray->xa = ray->x2 - ray->x1;
		ray->real_x_h = x;
		ray->real_y_h = y;
		while (cub->map.map[(int)ray->real_y_h / SIZE][(int)ray->real_x_h / SIZE] != '1')
		{
			if (cub->rays[index].angle > 0 && cub->rays[index].angle < 180)
				ray->real_y_h -= SIZE;
			else
				ray->real_y_h += SIZE;
			ray->real_x_h += ray->xa;
			if (ray->real_x_h < 0 || ray->real_x_h >= (cub->map.w * SIZE) || ray->real_y_h < 0 || ray->real_y_h >= (cub->map.h * SIZE))
				return (-1);
		}
		return (distance(cub->plr.real_x, cub->plr.real_y, ray->real_x_h, ray->real_y_h));
	}
	return (0);
}

float	check_walls_v(t_cub *cub, t_ray *ray, int index, float x, float y)
{
	if (ray->copy_x == -1)
		ray->copy_x = x;
	else if ((absf(floor(x) - floor(ray->copy_x)) >= 1) && ray->y1 == -1)
	{
		ray->y1 = y;
		ray->copy_x = x;
	}
	else if (absf(floor(x) - floor(ray->copy_x)) >= SIZE)
	{
		ray->y2 = y;
		ray->ya = ray->y2 - ray->y1;
		ray->real_x_v = x;
		ray->real_y_v = y;
		while (cub->map.map[(int)floorf(ray->real_y_v) / SIZE][(int)floorf(ray->real_x_v) / SIZE] != '1')
		{
			if (cub->rays[index].angle > 90 && cub->rays[index].angle < 270)
				ray->real_x_v -= SIZE;
			else
				ray->real_x_v += SIZE;
			ray->real_y_v += ray->ya;
			if (ray->real_x_v < 0 || ray->real_x_v >= (cub->map.w * SIZE) || ray->real_y_v < 0 || ray->real_y_v >= (cub->map.h * SIZE))
				return (-1);
		}
		return (distance(cub->plr.real_x, cub->plr.real_y, ray->real_x_v, ray->real_y_v));
	}
	return (0);
}

int	get_side(t_ray *ray)
{
	if (!ray->l_h || ray->l_h == -1)
		ray->l_h = INT_MAX;
	if (!ray->l_v || ray->l_v == -1)
		ray->l_v = INT_MAX;
	if (ray->l_h < ray->l_v)
	{
		ray->real_x = ray->real_x_h;
		ray->real_y = ray->real_y_h;
		if (ray->angle > 0 && ray->angle < 180)
			return (NORTH);
		return (SOUTH);
	}
	else if (ray->l_v < ray->l_h)
	{
		ray->real_x = ray->real_x_v;
		ray->real_y = ray->real_y_v;
		if (ray->angle > 90 && ray->angle < 270)
			return (EAST);
	}
	return (WEST);
	
}

void	cardinal(t_cub *cub, t_ray *ray)
{
	double	rad;
	int		i;
	float	x;
	float	y;

	rad = ray->angle * (M_PI / 180);
	i = 0;
	while (1)
	{
		x = cub->plr.real_x + (i * cos(rad));
		y = cub->plr.real_y + (i * sin(rad));
		if (cub->map.map[(int)y / SIZE][(int)x / SIZE] == '1')
		{
			ray->side = check_walls_cardinal(ray->angle);
			ray->l = distance(cub->plr.real_x, cub->plr.real_y, x, y);
			break ;
		}
		my_mlx_pixel_put(&cub->img_map, round(x) / MAP_DIV, round(y) / MAP_DIV, GREEN);
		i++;
	}
}

void	init_rays(t_ray *ray)
{
	ray->side = 0;
	ray->l_h = 0;
	ray->l_v = 0;
	ray->l = 0;
	ray->x1 = -1;
	ray->x2 = 0;
	ray->xa = 0;
	ray->y1 = -1;
	ray->y2 = 0;
	ray->ya = 0;
	ray->copy_x = -1;
	ray->copy_y = -1;
	ray->draw = 0;
}

float	get_distance(t_ray ray)
{
	if (ray.l_h < ray.l_v)
		return (ray.l_h);
	return (ray.l_v);
}

void	draw_ray(t_cub cub, t_ray ray)
{
	double	rad;
	int		i;
	float	floats[2];

	rad = ray.angle * (M_PI / 180);
	i = 1;
	floats[0] = cub.plr.real_x + cos(rad);
	floats[1] = cub.plr.real_y + sin(rad);
	my_mlx_pixel_put(&cub.img_map, (int)floorf(floats[0]) / MAP_DIV, (int)floorf(floats[1]) / MAP_DIV, GREEN);
	while (floorf(distance(cub.plr.real_x, cub.plr.real_y, floats[0], floats[1])) <= floorf(ray.l))
	{
		my_mlx_pixel_put(&cub.img_map, (int)floorf(floats[0]) / MAP_DIV, (int)floorf(floats[1]) / MAP_DIV, GREEN);
		floats[0] = cub.plr.real_x + (i * cos(rad));
		floats[1] = cub.plr.real_y + (i * sin(rad));
		i++;
	}
}

void expand_ray(t_cub *cub, int index, t_ray *ray)
{
	double	rad;
	int		i;
	float	floats[2];

	init_rays(ray);
	if (!((int)floorf(ray->angle) % 90))
		cardinal(cub, ray);
	else
	{
		rad = ray->angle * (M_PI / 180);
		i = 0;
		while (!ray->l_h)
		{
			floats[0] = cub->plr.real_x + (i * cos(rad));
			floats[1] = cub->plr.real_y + (i * sin(rad));
			if (cub->map.map[(int)floorf(floats[1]) / SIZE][(int)floorf(floats[0]) / SIZE] == '1')
				ray->l_h = distance(cub->plr.real_x, cub->plr.real_y, floats[0], floats[1]);
			else if (floats[0] < 0 || floats[0] >= (cub->map.w * SIZE) || floats[1] < 0 || floats[1] >= (cub->map.h * SIZE))
				break ;
			else if ((!((int)floorf(floats[1]) % SIZE) || !((int)(floorf(floats[1]) + 1) % SIZE)) && !ray->l_h)
				ray->l_h = check_walls_h(cub, ray, index, floats[0], floats[1]);
			i++;
		}
		// if (index == 511)
		// 	printf("%f\n", ray->l_h);
		i = 0;
		while (!ray->l_v)
		{
			floats[0] = cub->plr.real_x + (i * cos(rad));
			floats[1] = cub->plr.real_y + (i * sin(rad));
			if (cub->map.map[(int)floorf(floats[1]) / SIZE][(int)floorf(floats[0]) / SIZE] == '1')
				ray->l_v = distance(cub->plr.real_x, cub->plr.real_y, floats[0], floats[1]);
			else if (floats[0] < 0 || floats[0] >= (cub->map.w * SIZE) || floats[1] < 0 || floats[1] >= (cub->map.h * SIZE))
				break ;
			else if ((!((int)floorf(floats[0]) % SIZE) || !((int)(floorf(floats[0]) + 1) % SIZE)) && !ray->l_v)
				ray->l_v = check_walls_v(cub, ray, index, floats[0], floats[1]);
			i++;
		}
		ray->side = get_side(ray);
		ray->l = get_distance(*ray);
		draw_ray(*cub, *ray);
	}
}
