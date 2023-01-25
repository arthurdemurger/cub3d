/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:29:17 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/25 12:12:26 by gponcele         ###   ########.fr       */
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
	    x = cub->plr.real_x + r * cos(rad);
	    y = cub->plr.real_y + r * sin(rad);
		my_mlx_pixel_put(&cub->img_map, x, y, color);
	}
}

t_ray intersection(t_cub *cub, int cx, int cy, int r, float angle) 
{
	t_ray		dir;
	float		rad;
	int			x;
	int			y;

	(void)cub;
	rad = angle * (M_PI / 180);
    x = cx + r * cos(rad);
    y = cy + r * sin(rad);
	dir.real_x = x;
	dir.real_y = y;
	// if (dir.real_x < 0)
	// 	dir.real_x = 0;
	// if (dir.real_y < 0)
	// 	dir.real_y = 0;
	return (dir);
}
