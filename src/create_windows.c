/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_windows.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:29:17 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/27 12:55:37 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	fill_squares(t_cub *cub)
{
	int	x;
	int	y;
	int	x_copy;
	int	y_copy;

	y = -1;
	while (cub->map.map[++y])
	{
		x = -1;
		while (cub->map.map[y][++x])
		{
			if (cub->map.map[y][x] == '1')
			{
				y_copy = y * (SIZE / MAP_DIV);
				while (y_copy < ((y * (SIZE / MAP_DIV)) + (SIZE / MAP_DIV))
					|| x_copy < ((x * (SIZE / MAP_DIV)) + (SIZE / MAP_DIV)))
				{
					x_copy = x * (SIZE / MAP_DIV);
					while (x_copy < ((x * (SIZE / MAP_DIV)) + (SIZE / MAP_DIV)))
					{
						my_mlx_pixel_put(&cub->img_map, x_copy, y_copy,
							BLUE);
						x_copy++;
					}
					y_copy++;
				}
			}
		}
	}
}

void	grid(t_cub *cub)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x < ((SIZE * cub->map.w)) / MAP_DIV || y < ((SIZE * cub->map.h)) / MAP_DIV)
	{
		x = 0;
		while (x < ((SIZE * cub->map.w)) / MAP_DIV)
		{
			if ((y > 0 && ((x % (SIZE / MAP_DIV)) == 0)) || (y % (SIZE / MAP_DIV)) == 0)
				my_mlx_pixel_put(&cub->img_map, x, y, BLACK);
			x++;
		}
		y++;
	}
}

void	clean_map(t_cub *cub)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x < ((SIZE * cub->map.w)) / MAP_DIV || y < ((SIZE * cub->map.h)) / MAP_DIV)
	{
		x = 0;
		while (x < ((SIZE * cub->map.w)) / MAP_DIV)
		{
			my_mlx_pixel_put(&cub->img_map, x, y, WHITE);
			x++;
		}
		y++;
	}
	fill_squares(cub);
}

void create_window_main(t_cub *cub)
{
	cub->win_game = mlx_new_window(cub->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D - Game");
	clean_map(cub);
	circle(cub, 1, LIGHT_RED);
	draw(cub);
	// grid(cub);
	mlx_put_image_to_window(cub->mlx, cub->win_game, cub->img_map.img, 0, 0);
}
