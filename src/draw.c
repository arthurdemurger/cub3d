/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:29:17 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/25 17:52:08 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	draw_col(t_cub *cub, float l, int col, int color)
{
	int		i;
	float	height;

	i = 384;
	height = (cub->r * SIZE) / l;
	my_mlx_pixel_put(&cub->img_game, col, i, color);
	while (++i <= 384 + ((int)height / 2))
		my_mlx_pixel_put(&cub->img_game, col, i, color);
	i = 384;
	while (--i >= 384 - ((int)height / 2))
		my_mlx_pixel_put(&cub->img_game, col, i, color);
}

void	get_color(t_cub *cub, t_ray ray, int col)
{
	if (ray.face % 2)
		draw_col(cub, ray.l, col, LIGHT_GREEN);
	else if (!ray.face % 2)
		draw_col(cub, ray.l, col, DARK_GREEN);
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

void	draw(t_cub *cub)
{
	int	i;
	
	i = -1;
	draw_floor(cub);
	draw_ceiling(cub);
	while (++i < NB_RAYS)
		get_color(cub, cub->rays[i], i);	
	mlx_put_image_to_window(cub->mlx, cub->win_game, cub->img_game.img, 0, 0);
}