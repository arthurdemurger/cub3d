/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:29:17 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/20 16:59:18 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void update_data(t_cub *cub, int line, char *data)
{
	int	x = 250;
	int	y = 0;

	if (line == 1)
	{
		y = 15;
		while (x < 430 || y < 40)
		{
			x = 250;
			while (x < 430)
			{
				mlx_pixel_put(cub->mlx, cub->win_data, x, y, 0x000000);
				x++;
			}
			y++;
		}
		mlx_string_put(cub->mlx, cub->win_data, 250, 15, 0xFFFFFF, data);
	}
	else if (line == 2)
	{
		y = 40;
		while (x < 400 || y < 60)
		{
			x = 250;
			while (x < 400)
			{
				mlx_pixel_put(cub->mlx, cub->win_data, x, y, 0x000000);
				x++;
			}
			y++;
		}
		mlx_string_put(cub->mlx, cub->win_data, 250, 40, 0xFFFFFF, data);
	}
	else if (line == 3)
	{
		y = 65;
		while (x < 400 || y < 85)
		{
			x = 250;
			while (x < 400)
			{
				mlx_pixel_put(cub->mlx, cub->win_data, x, y, 0x000000);
				x++;
			}
			y++;
		}
		mlx_string_put(cub->mlx, cub->win_data, 250, 65, 0xFFFFFF, data);
	}
	else if (line == 4)
	{
		y = 90;
		while (x < 400 || y < 110)
		{
			x = 250;
			while (x < 400)
			{
				mlx_pixel_put(cub->mlx, cub->win_data, x, y, 0x000000);
				x++;
			}
			y++;
		}
		mlx_string_put(cub->mlx, cub->win_data, 250, 90, 0xFFFFFF, data);
	}
	else if (line == 5)
	{
		y = 115;
		while (x < 400 || y < 135)
		{
			x = 250;
			while (x < 400)
			{
				mlx_pixel_put(cub->mlx, cub->win_data, x, y, 0x000000);
				x++;
			}
			y++;
		}
		mlx_string_put(cub->mlx, cub->win_data, 250, 115, 0xFFFFFF, data);
	}
	else if (line == 6)
	{
		y = 140;
		while (x < 400 || y < 160)
		{
			x = 250;
			while (x < 400)
			{
				mlx_pixel_put(cub->mlx, cub->win_data, x, y, 0x000000);
				x++;
			}
			y++;
		}
		mlx_string_put(cub->mlx, cub->win_data, 250, 140, 0xFFFFFF, data);
	}
}