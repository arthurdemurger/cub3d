/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_windows.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:29:17 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/24 12:46:55 by gponcele         ###   ########.fr       */
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
				y_copy = y * SIZE;
				while (y_copy < ((y * SIZE) + SIZE)
					|| x_copy < ((x * SIZE) + SIZE))
				{
					x_copy = x * SIZE;
					while (x_copy < ((x * SIZE) + SIZE))
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
	while (x < (SIZE * cub->map.w) || y < (SIZE * cub->map.h))
	{
		x = 0;
		while (x < (SIZE * cub->map.w))
		{
			if ((y > 0 && ((x % SIZE) == 0)) || (y % SIZE) == 0)
				my_mlx_pixel_put(&cub->img_map, x, y, BLACK);
			x++;
		}
		y++;
	}
}

void	draw_square(t_cub *cub, int x, int y, int color)
{
	int x_copy;
	int y_copy;

	x_copy = 0;
	y_copy = y - 3;
	while (x_copy < (x + 3) || y_copy < (y + 3))
	{
		x_copy = x - 3;
		while (x_copy < (x + 3))
		{
			my_mlx_pixel_put(&cub->img_map, x_copy, y_copy, color);
			x_copy++;
		}
		y_copy++;
	}
}

void create_window_main(t_cub *cub)
{
	int x;
	int y;
	
	x = 0;
	y = 0;
	cub->win_main = mlx_new_window(cub->mlx, cub->map.w * SIZE, cub->map.h * SIZE, "Cub3D - Test");
	while (x < (SIZE * cub->map.w) || y < (SIZE * cub->map.h))
	{
		x = 0;
		while (x < (SIZE * cub->map.w))
		{
			my_mlx_pixel_put(&cub->img_map, x, y, WHITE);
			x++;
		}
		y++;
	}
	fill_squares(cub);
	circle(cub, 5, RED);
	display_pov(cub, GREEN);
	grid(cub);
	mlx_put_image_to_window(cub->mlx, cub->win_main, cub->img_map.img, 0, 0);
}
void	create_window_data(t_cub *cub)
{
	char	*data;

	cub->win_data = mlx_new_window(cub->mlx, 450, 165, "Cub3D - Data");
    // mlx_string_put(cub->mlx, cub->win_data, 10, 15, WHITE, "Player position :");
    // mlx_string_put(cub->mlx, cub->win_data, 10, 40, WHITE, "Dir last position :");
    // mlx_string_put(cub->mlx, cub->win_data, 10, 65, WHITE, "Ray0 length :");
    // mlx_string_put(cub->mlx, cub->win_data, 10, 90, WHITE, "Wall encountered :");
	// mlx_string_put(cub->mlx, cub->win_data, 10, 115, WHITE, "Wall_face displayed :");
	mlx_string_put(cub->mlx, cub->win_data, 10, 140, WHITE, "Angle :");
	data = ft_strjoin(ft_strdup("x : "), ft_itoa(cub->plr.real_x));
	data = ft_strjoin(data, " | y : ");
	data = ft_strjoin(data, ft_itoa(cub->plr.real_y));
	update_data(cub, 1, data);
	update_data(cub, 6, ft_itoa(cub->angle));
	data = ft_strjoin(ft_strdup("X : "), ft_itoa(cub->plr.x));
	data = ft_strjoin(data, " | Y : ");
	data = ft_strjoin(data, ft_itoa(cub->plr.y));
	update_data(cub, 1, data);
	free (data);
}

void	create_window_game(t_cub *cub)
{
	cub->win_game = mlx_new_window(cub->mlx, 1024, 768, "Cub3D - Game");
	draw(cub, 1);
	mlx_put_image_to_window(cub->mlx, cub->win_game, cub->img_game.img, 0, 0);
}