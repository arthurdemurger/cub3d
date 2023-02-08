/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_windows.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:29:17 by ademurge          #+#    #+#             */
/*   Updated: 2023/02/08 11:55:48 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	fill_squares(t_cub *cub, int x, int y)
{
	t_pos	copy;

	while (cub->map.map[++y])
	{
		x = -1;
		while (cub->map.map[y][++x])
		{
			if (cub->map.map[y][x] == '1')
			{
				copy.y = y * (SIZE / MAP_DIV);
				while (copy.y < ((y * (SIZE / MAP_DIV)) + (SIZE / MAP_DIV))
					|| copy.x < ((x * (SIZE / MAP_DIV)) + (SIZE / MAP_DIV)))
				{
					copy.x = x * (SIZE / MAP_DIV);
					while (copy.x < ((x * (SIZE / MAP_DIV)) + (SIZE / MAP_DIV)))
					{
						my_mlx_pixel_put(&cub->img_map, copy.x, copy.y,
							0x1C1B1B);
						copy.x++;
					}
					copy.y++;
				}
			}
		}
	}
}

void	grid(t_cub *cub)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < ((SIZE * cub->map.w)) / MAP_DIV
		|| y < ((SIZE * cub->map.h)) / MAP_DIV)
	{
		x = 0;
		while (x < ((SIZE * cub->map.w)) / MAP_DIV)
		{
			if ((y > 0 && ((x % (SIZE / MAP_DIV)) == 0))
				|| (y % (SIZE / MAP_DIV)) == 0)
				my_mlx_pixel_put(&cub->img_map, x, y, BLACK);
			x++;
		}
		y++;
	}
}

void	clean_map(t_cub *cub)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < ((SIZE * cub->map.w) / MAP_DIV) + 6
		|| y < ((SIZE * cub->map.h) / MAP_DIV) + 6)
	{
		x = 0;
		while (x < (SIZE * cub->map.w) / MAP_DIV + 6)
		{
			my_mlx_pixel_put(&cub->img_map, x, y, 0xf3ddc1);
			x++;
		}
		y++;
	}
	fill_squares(cub, -1, -1);
}

void	create_window_main(t_cub *cub)
{
	cub->win_game = mlx_new_window(cub->mlx, WIN_WIDTH, WIN_HEIGHT,
			"Cub3D - Game");
	clean_map(cub);
	circle(cub, 1, LIGHT_RED);
	draw(cub);
}
