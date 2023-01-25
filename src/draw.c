/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:29:17 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/25 13:21:23 by gponcele         ###   ########.fr       */
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

void	draw_spot(t_cub *cub, t_ray ray, int col, int color)
{
	int	i;

	i = -1;
	// if (ray.face == 5)
	// {
	// 	if (color)
	// 		draw_col(cub, ray.l, col + i, BLUE);
	// 	else
	// 		draw_col(cub, ray.l, col + i, WHITE);
	// }
	if (ray.face == 1 || ray.face == 3)
	{
		if (color)
			draw_col(cub, ray.l, col + i, LIGHT_GREEN);
		else
			draw_col(cub, ray.l, col + i, WHITE);
	}
	else if (ray.face == 2 || ray.face == 4)
	{
		if (color)
			draw_col(cub, ray.l, col + i, DARK_GREEN);
		else
			draw_col(cub, ray.l, col + i, WHITE);
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

void	draw_ceiling(t_cub *cub)
{
	int	x;
	int	y;

	y = 383;
	while (--y > 0)
	{
		x = -1;
		while (++x < 1024)
			my_mlx_pixel_put(&cub->img_game, x, y, 0x000000);
	}
}

void	draw(t_cub *cub, int color)
{
	int	i;
	
	i = -1;
	draw_floor(cub);
	draw_ceiling(cub);
	while (++i <= (NB_RAYS / 2) - 1)
		draw_spot(cub, cub->rays[i], i, color);	
	draw_spot(cub, cub->rays[i], i, color);
	while (++i <= NB_RAYS - 1)
		draw_spot(cub, cub->rays[i], i, color);
	mlx_put_image_to_window(cub->mlx, cub->win_game, cub->img_game.img, 0, 0);
}