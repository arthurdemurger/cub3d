/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 10:27:36 by ademurge          #+#    #+#             */
/*   Updated: 2023/02/07 12:34:38 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	get_color(t_cub *cub, t_ray ray, int col)
{
	int	i;

	i = -1;
	while (++i < WIN_HEIGHT / 2)
		my_mlx_pixel_put(&cub->img_col, 0, i, cub->txtr.c);
	while (++i < 768)
		my_mlx_pixel_put(&cub->img_col, 0, i, cub->txtr.f);
	if (ray.side == NORTH)
		draw_col(cub, ray, col, &cub->txtr.north);
	else if (ray.side == SOUTH)
		draw_col(cub, ray, col, &cub->txtr.south);
	else if (ray.side == EAST)
		draw_col(cub, ray, col, &cub->txtr.east);
	else if (ray.side == WEST)
		draw_col(cub, ray, col, &cub->txtr.west);
}

float	distance(t_cub cub, float *floats)
{
	float	dx;
	float	dy;

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

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x
			* (img->bits_per_pixel / MAP_DIV));
	*(unsigned int *)dst = color;
}
