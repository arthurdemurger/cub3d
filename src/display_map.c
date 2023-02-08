/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:40:59 by gponcele          #+#    #+#             */
/*   Updated: 2023/02/08 12:21:05 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	draw_col_darker(t_cub *cub, t_ray ray, int col, t_img *img)
{
	int		ints[2];
	float	height;
	float	line;
	int		*pix;
	float	multi;

	height = ((SIZE * SIZE) / floorf(ray.l)) * 25;
	multi = height / 256.000;
	ints[0] = (768.000 - (int)floorf(height)) / 2;
	ints[1] = ints[0];
	if (ints[1] < 0)
		ints[1] = 0;
	line = 0;
	if (height > 768)
		line += (height - 768.000) / 2;
	while (ints[1] < (768.000 - ints[0]) && ints[1] < 768)
	{
		pix = (int *)img->addr + ((int)floorf(line / multi) * (img->line_length
					/ 4) + (int)floorf(ray.col) * (img->bits_per_pixel / 32));
		my_mlx_pixel_put(&cub->img_col, 0, ints[1],
			(mlx_get_color_value(cub->mlx, *pix) >> 1) & 8355711);
		line += 1.000;
		ints[1]++;
	}
	mlx_put_image_to_window(cub->mlx, cub->win_game, cub->img_col.img, col, 0);
}

void	get_color_darker(t_cub *cub, t_ray ray, int col)
{
	int	i;

	i = -1;
	while (++i < WIN_HEIGHT / 2)
		my_mlx_pixel_put(&cub->img_col, 0, i, (cub->txtr.c >> 1) & 8355711);
	while (++i < 768)
		my_mlx_pixel_put(&cub->img_col, 0, i, (cub->txtr.f >> 1) & 8355711);
	if (ray.side == NORTH)
		draw_col_darker(cub, ray, col, &cub->txtr.north);
	else if (ray.side == SOUTH)
		draw_col_darker(cub, ray, col, &cub->txtr.south);
	else if (ray.side == EAST)
		draw_col_darker(cub, ray, col, &cub->txtr.east);
	else if (ray.side == WEST)
		draw_col_darker(cub, ray, col, &cub->txtr.west);
}

void	draw_game_darker(t_cub *cub)
{
	int	i;

	i = -1;
	while (++i < NB_RAYS)
		get_color_darker(cub, cub->rays[i], i);
}

void	draw_map_edge(t_cub *cub, int x, int y, int cy)
{
	int	cx;

	while (++cy < y)
	{
		cx = x - 4;
		while (++cx < x + (((cub->map.w * SIZE) / MAP_DIV) + 3))
			mlx_pixel_put(cub->mlx, cub->win_game, cx, cy, 0x8E8E8E);
	}
	cy--;
	while (++cy < (y + ((cub->map.h * SIZE) / MAP_DIV)) - 1)
	{
		cx = x - 4;
		while (++cx < x)
			mlx_pixel_put(cub->mlx, cub->win_game, cx, cy, 0x8E8E8E);
		cx = x + ((cub->map.w * SIZE) / MAP_DIV) + 3;
		while (--cx >= x + ((cub->map.w * SIZE) / MAP_DIV))
			mlx_pixel_put(cub->mlx, cub->win_game, cx, cy, 0x8E8E8E);
	}
	cy--;
	while (++cy < (y + ((cub->map.h * SIZE) / MAP_DIV)) + 3)
	{
		cx = x - 4;
		while (++cx < x + (((cub->map.w * SIZE) / MAP_DIV) + 3))
			mlx_pixel_put(cub->mlx, cub->win_game, cx, cy, 0x8E8E8E);
	}
}

void	display_map(t_cub *cub, int a)
{
	int	x;
	int	y;

	if (a == 1)
	{
		draw_game_darker(cub);
		// grid(cub);
		x = (1024.000 / 2) - (((cub->map.w * SIZE) / MAP_DIV) / 2);
		y = (768.000 / 2) - (((cub->map.h * SIZE) / MAP_DIV) / 2);
		mlx_put_image_to_window(cub->mlx,
			cub->win_game, cub->scroll.img, 225, 165);
		mlx_put_image_to_window(cub->mlx, cub->win_game,
			cub->map_title.img, 160, 40);
		mlx_put_image_to_window(cub->mlx,
			cub->win_game, cub->img_map.img, x, y);
		// draw_map_edge(cub, x, y, y - 4);
	}
	else
		draw(cub);
	cub->display_map = a;
}
