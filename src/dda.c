/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:29:17 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/20 16:55:05 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"


int	check_walls(int x, int y, t_cub *cub)
{
	if (cub->map.map[y / SIZE][x / SIZE] == '1')
		return (1);
	return (0);
}

int abs(int n)
{
	if (n > 0)
		return (n);
	return (-n);
}

void dda_ray0(t_cub *cub, int x, int y)
{
	int		delta[2];
	int		counters[2];
	float	floats[2];

	delta[0] = x - cub->plr.real_x;
	delta[1] = y - cub->plr.real_y;
	if (abs(delta[0]) > abs(delta[1]))
		counters[0] = abs(delta[0]);
	else
		counters[0] = abs(delta[1]);
	floats[0] = cub->plr.real_x;
	floats[1] = cub->plr.real_y;
	counters[1] = -1;
	while (++counters[1] <= counters[0])
	{
		if (check_walls(round(floats[0]), round(floats[1]), cub))
			break ;
		mlx_pixel_put(cub->mlx, cub->win_main, round(floats[0]), round(floats[1]),
			GREEN);
		floats[0] += (delta[0] / (float)counters[0]);
		floats[1] += (delta[1] / (float)counters[0]);
		// usleep(100);
	}
}



// void DDA_plane(t_cub *cub)
// {
//     int px; 
//     int py;
//     int steps;
//     float X;
//     float Y;

//     px = cub->plane->x - cub->dir->x;
//     py = cub->plane->y - cub->dir->y;
//     steps = abs(px) > abs(py) ? abs(px) : abs(py);
//     X = cub->dir->x;
//     Y = cub->dir->y;
//     for (int i = 0; i <= steps; i++) 
//     {
//         mlx_pixel_put(cub->mlx, cub->win, round(X), round(Y),
//                  0xFFFFFF);
//         X += (px / (float)steps);
//         Y += (py / (float)steps);
//         usleep(100);
//     }
// }