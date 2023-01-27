/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:29:17 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/27 17:52:34 by gponcele         ###   ########.fr       */
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

int	check_walls(int angle)
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

float	check_walls_h(t_cub *cub, t_vector *inter, int index, int x)
{
	if (!inter->x1)
		inter->x1 = x;
	else
	{
		inter->x2 = x;
		inter->xa = inter->x2 - inter->x1;
		while (cub->map.map[inter->real_y / SIZE][inter->real_x / SIZE] != '1')
		{
			if (cub->rays[index].angle > 0 && cub->rays[index].angle < 180)
			{
				ICI
				inter->real_x += inter->xa;
				inter->real_y -= SIZE;
			}
			else
			{
				inter->real_x += inter->xa;
				inter->real_y += SIZE;
			}
		}
		return (distance(cub->plr.real_x, cub->plr.real_y, inter->real_x, inter->real_y));
	}
	return (0);
}

float	check_walls_v(t_cub *cub, t_vector *inter, int index, int y)
{
	if (!inter->y1)
		inter->y1 = y;
	else
	{
		inter->y2 = y;
		inter->ya = inter->y2 - inter->y1;
		while (cub->map.map[inter->real_y / SIZE][inter->real_x / SIZE] != '1')
		{
			if (cub->rays[index].angle > 90 && cub->rays[index].angle < 270)
			{
				inter->real_x -= SIZE;
				inter->real_y += inter->ya;
			}
			else
			{
				inter->real_x += SIZE;
				inter->real_y += inter->ya;
			}
		}
		return (distance(cub->plr.real_x, cub->plr.real_y, inter->real_x, inter->real_y));
	}
	return (0);
}

int	get_side(int angle, t_ray ray)
{
	if (ray.l_h < ray.l_v && (angle > 0 && angle < 180))
		return (SOUTH);
	else if (ray.l_h < ray.l_v)
		return (NORTH);
	else if (ray.l_v < ray.l_h && (angle > 90 && angle < 270))
		return (WEST);
	return (EAST);
}

void	cardinal(t_cub *cub, int index)
{
	double	rad;
	int		i;
	float	floats[2];

	rad = cub->rays[index].angle * (M_PI / 180);
	i = 0;
	while (1)
	{
		floats[0] = cub->plr.real_x + (i * cos(rad));
		floats[1] = cub->plr.real_y + (i * sin(rad));
		if (cub->map.map[(int)floats[1] / SIZE][(int)floats[0] / SIZE] == '1')
		{
			cub->rays[index].side = check_walls(cub->rays[index].angle);
			cub->rays[index].l = distance(cub->plr.real_x, cub->plr.real_y, floats[0], floats[1]);
			break ;
		}
		my_mlx_pixel_put(&cub->img_map, round(floats[0]) / 4, round(floats[1]) / 4, GREEN);
		i++;
	}
}

void	init_rays(t_ray *ray)
{
	ray->side = 0;
	ray->l_h = 0;
	ray->l_v = 0;
	ray->l = 0;
}

void expand_ray(t_cub *cub, int index, t_ray *ray)
{
	double		rad;
	int			i;
	float		floats[2];

	// printf("%d : ", index);
	init_rays(ray);
	if (!((int)ray->angle % 90))
		cardinal(cub, index);
	else
	{
		rad = ray->angle * (M_PI / 180);
		i = 0;
		while (!ray->l_h || !ray->l_v)
		{
			floats[0] = cub->plr.real_x + (i * cos(rad));
			floats[1] = cub->plr.real_y + (i * sin(rad));
			if ((!((int)floats[1] % SIZE) || !((int)(floats[1] + 1) % SIZE)) && !ray->l_h)
			{
				if (cub->map.map[(int)floats[1] / SIZE][(int)floats[0] / SIZE])
					ray->l_h = distance(cub->plr.real_x, cub->plr.real_y, floats[0], floats[1]);
				else
					ray->l_h = check_walls_h(cub, &ray->inter, index, floats[0]);
			}
			if ((!((int)floats[0] % SIZE) || !((int)(floats[0] + 1) % SIZE)) && !ray->l_v)
			{
				if (cub->map.map[(int)floats[1] / SIZE][(int)floats[0] / SIZE])
					ray->l_v = distance(cub->plr.real_x, cub->plr.real_y, floats[0], floats[1]);
				else
					ray->l_v = check_walls_v(cub, &ray->inter, index, floats[1]);
			}
			my_mlx_pixel_put(&cub->img_map, round(floats[0]) / 4, round(floats[1]) / 4, GREEN);
			i++;
		}
		ray->side = get_side(ray->angle, *ray);
		ray->l = distance(cub->plr.real_x, cub->plr.real_y, floats[0], floats[1]);
	}
}
