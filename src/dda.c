/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:29:17 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/23 12:51:20 by gponcele         ###   ########.fr       */
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
 
void dda_ray0(t_cub *cub, int x, int y, int color)
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
		if (check_walls(round(fl_x), round(fl_y), cub))
			break ;
        mlx_pixel_put(cub->mlx, cub->win_main, round(fl_x), round(fl_y),
                 color);
        fl_x += (delta.x / (float)steps);
        fl_y += (delta.y / (float)steps);
        usleep(100);
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