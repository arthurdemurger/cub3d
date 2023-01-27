/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 10:27:36 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/27 11:05:06 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	draw_cursor(t_cub *cub)
{
	int		x;
	int		y;
	float	mid_x;
	float	mid_y;

	mid_x = (WIN_WIDTH / 2) - 3;
	mid_y = (WIN_HEIGHT / 2) - 3;
	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
		{
			my_mlx_pixel_put(&cub->img_game, mid_x + x, mid_y + y, RED);
		}
	}
}

float	add_angle(float a, float b)
{
	if (a + b > 360)
		return (a + b - 360);
	return (a + b);
}

float	min_angle(float a, float b)
{
	if (a - b < 0)
		return (a - b + 360);
	return (a - b);
}