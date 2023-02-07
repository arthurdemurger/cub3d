/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_windows.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:29:17 by ademurge          #+#    #+#             */
/*   Updated: 2023/02/07 15:39:50 by ademurge         ###   ########.fr       */
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
			if (cub->map.map[y][x] == '1' || cub->map.map[y][x] == ' ')
			{
				copy.y = y * (SIZE / MAP_DIV);
				while (copy.y < ((y * (SIZE / MAP_DIV)) + (SIZE / MAP_DIV))
					|| copy.x < ((x * (SIZE / MAP_DIV)) + (SIZE / MAP_DIV)))
				{
					copy.x = x * (SIZE / MAP_DIV);
					while (copy.x < ((x * (SIZE / MAP_DIV)) + (SIZE / MAP_DIV)))
					{
						my_mlx_pixel_put(&cub->img_map, copy.x, copy.y,
							0x6E4B07);
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
			my_mlx_pixel_put(&cub->img_map, x, y, 0xABABAB);
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
