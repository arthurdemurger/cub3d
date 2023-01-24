/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:29:17 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/24 12:44:50 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"


int	check_walls(int x, int y, t_cub *cub)
{
	int	i;

	i = -1;
	// if (cub->map.map[y / SIZE][x / SIZE] == '1')
	// 	return (1);
	if ((cub->map.map[y / SIZE][x / SIZE] == '1') && x % SIZE != 0 && (cub->angle < 90 || cub->angle > 270))
		return (3);
	if ((cub->map.map[y / SIZE][x / SIZE] == '1') && x % SIZE != 0 && (cub->angle > 90 && cub->angle < 270))
		return (1);
	if ((cub->map.map[y / SIZE][x / SIZE] == '1') && y % SIZE != 0 && (cub->angle > 0 && cub->angle < 180))
		return (4);
	if ((cub->map.map[y / SIZE][x / SIZE] == '1') && y % SIZE != 0 && (cub->angle <= 359 || cub->angle > 180))
		return (2);
	return (0);
}

int abs(int n)
{
	if (n > 0)
		return (n);
	return (-n);
}
 
int dda(t_cub *cub, int x, int y, int color, int ray, int draw)
{
	t_pos	delta;
	int		i;
	int 	steps;
	float	fl_x;
	float	fl_y;

	delta.x = x - cub->plr.real_x;
	delta.y = y - cub->plr.real_y;
	if (abs(delta.x) > abs(delta.y))
		steps = abs(delta.x);
	else
		steps = abs(delta.y);
	fl_x = cub->plr.real_x;
	fl_y = cub->plr.real_y;
	i = 0;
	while (i++ <= steps)
	{
		cub->rays[ray].face = check_walls(round(fl_x), round(fl_y), cub);
		if (cub->rays[ray].face)
			break ;
		if (draw)
		{
			if (ray == 1000)
				my_mlx_pixel_put(&cub->img_map, round(fl_x), round(fl_y), BLUE);
			else
				my_mlx_pixel_put(&cub->img_map, round(fl_x), round(fl_y), color);
		}
        fl_x += (delta.x / (float)steps);
        fl_y += (delta.y / (float)steps);
    }
	return (i);
}
