/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:29:17 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/27 16:36:29 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	circle(t_cub *cub, int r, int color)
{
	float		rad;
	int			x, y;

	for (float angle = 0; angle <= 360; angle += 0.1)
	{
		rad = angle * (M_PI / 180);
		x = (cub->plr.real_x / 4) + r * cos(rad);
		y = (cub->plr.real_y / 4) + r * sin(rad);
		my_mlx_pixel_put(&cub->img_map, x, y, color);
	}
}

void	init_ray(t_ray *ray)
{
	ray->angle = 0;
	ray->dir = 0;
	ray->side = 0;
	ray->l = 0;
	ray->real_x = 0;
	ray->real_y = 0;
}

t_ray intersection(int cx, int cy, float r, float angle)
{
	t_ray		dir;
	float		rad;
	int			x;
	int			y;

	init_ray(&dir);
	rad = angle * (M_PI / 180);
	x = roundf(cx + (r * cos(rad)));
	y = roundf(cy + (r * sin(rad)));
	dir.real_x = x;
	dir.real_y = y;
	return (dir);
}
