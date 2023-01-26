/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:29:17 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/26 11:16:05 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	draw_col(t_cub *cub, t_ray ray, int col, int color)
{
	int		i;
	float	height;

	i = WIN_HEIGHT / 2;
	height = (cub->rays[NB_RAYS / 2].l * SIZE) / ray.l;
	my_mlx_pixel_put(&cub->img_game, col, i, color);
	while (++i <= (WIN_HEIGHT / 2) + ((int)height / 2))
		my_mlx_pixel_put(&cub->img_game, col, i, color);
	i = WIN_HEIGHT / 2;
	while (--i >= (WIN_HEIGHT / 2) - ((int)height / 2))
		my_mlx_pixel_put(&cub->img_game, col, i, color);
}

void	get_color(t_cub *cub, t_ray ray, int col)
{
	if (ray.face % 2)
		draw_col(cub, ray, col, LIGHT_GREEN);
	else if (!(ray.face % 2))
		draw_col(cub, ray, col, DARK_GREEN);
}

void	draw_floor(t_cub *cub)
{
	int	x;
	int	y;

	y = (WIN_HEIGHT / 2) - 1;
	while (++y < WIN_HEIGHT)
	{
		x = -1;
		while (++x < WIN_WIDTH)
			my_mlx_pixel_put(&cub->img_game, x, y, FLOOR);
	}
}

void	draw_ceiling(t_cub *cub)
{
	int	x;
	int	y;

	y = (WIN_HEIGHT / 2) - 1;
	while (--y > 0)
	{
		x = -1;
		while (++x < WIN_WIDTH)
			my_mlx_pixel_put(&cub->img_game, x, y, BLACK);
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
