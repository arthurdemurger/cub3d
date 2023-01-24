/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:29:17 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/24 13:29:55 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	draw_col(t_cub *cub, int l, int col, int color)
{
	int		i;
	float	height;

	i = 384;
	height = (cub->r * SIZE) / l;
	my_mlx_pixel_put(&cub->img_game, col, i, color);
	while (++i <= 384 + ((int)height / 2))
	{
		// printf("[x : %d; y : %d]\n", col, i);
		my_mlx_pixel_put(&cub->img_game, col, i, color);
	}
	i = 384;
	while (--i >= 384 - ((int)height / 2))
	{
		// printf("[x : %d; y : %d]\n", col, i);
		my_mlx_pixel_put(&cub->img_game, col, i, color);
	}
}

void	draw_spot(t_cub *cub, t_vector ray, int col, int color)
{
	int	i;

	i = -1;
	if (ray.face == 1 || ray.face == 3)
	{
		while (++i < 4)
		{
			if (color)
				draw_col(cub, ray.l, col + i, LIGHT_GREEN);
			else
				draw_col(cub, ray.l, col + i, WHITE);
		}
	}
	else if (ray.face == 2 || ray.face == 4)
	{
		while (++i < 4)
		{
			if (color)
				draw_col(cub, ray.l, col + i, DARK_GREEN);
			else
				draw_col(cub, ray.l, col + i, WHITE);
		}
	}
}

void	draw_floor(t_cub *cub)
{
	int	x;
	int	y;

	y = 383;
	while (++y < 768)
	{
		x = -1;
		while (++x < 1024)
			my_mlx_pixel_put(&cub->img_game, x, y, 0xCAA472);
	}
}

void	draw(t_cub *cub, int color)
{
	int	i;
	
	i = -1;
	// cub->rays[128] = intersection(cub->plr.real_x, cub->plr.real_y, cub->r, cub->angle - 90);
	draw_floor(cub);
	while (++i <= 127)
	{
		// cub->rays[i] = intersection(cub->rays[128].real_x, cub->rays[128].real_y, (cub->plane / 128) * (128 - i), cub->angle - 180);
		// cub->rays[i].l = dda(cub, cub->rays[i].real_x, cub->rays[i].real_y, 0, i, 0);
		draw_spot(cub, cub->rays[i], i * 4, color);
	}
	cub->rays[i].l = dda(cub, cub->rays[128].real_x, cub->rays[128].real_y, 0, i, 0);
	draw_spot(cub, cub->rays[i], i * 4, color);
	while (++i <= 255)
	{
		// cub->rays[i] = intersection(cub->rays[128].real_x, cub->rays[128].real_y, (cub->plane / 128) * (i - 128), cub->angle);
		// cub->rays[i].l = dda(cub, cub->rays[i].real_x, cub->rays[i].real_y, 0, i, 0);
		draw_spot(cub, cub->rays[i], i * 4, color);
	}
	mlx_put_image_to_window(cub->mlx, cub->win_game, cub->img_game.img, 0, 0);
}