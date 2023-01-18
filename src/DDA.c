/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:29:17 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/16 15:00:38 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"


int abs(int n) 
{ 
    return ((n > 0) ? n : (n * (-1))); 
}
 
void DDA_ray0(t_cub *cub)
{
    int dx; 
    int dy;
    int steps;
    float X;
    float Y;

    dx = cub->dir->x - cub->hero->x;
    dy = cub->dir->y - cub->hero->y;
    steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    X = cub->hero->x;
    Y = cub->hero->y;
    for (int i = 0; i <= steps; i++) 
    {
        mlx_pixel_put(cub->mlx, cub->win, round(X), round(Y),
                 0xFFFFFF);
        X += (dx / (float)steps);
        Y += (dy / (float)steps);
        usleep(100);
    }
}

void DDA_plane(t_cub *cub)
{
    int px; 
    int py;
    int steps;
    float X;
    float Y;

    px = cub->plane->x - cub->dir->x;
    py = cub->plane->y - cub->dir->y;
    steps = abs(px) > abs(py) ? abs(px) : abs(py);
    X = cub->dir->x;
    Y = cub->dir->y;
    for (int i = 0; i <= steps; i++) 
    {
        mlx_pixel_put(cub->mlx, cub->win, round(X), round(Y),
                 0xFFFFFF);
        X += (px / (float)steps);
        Y += (py / (float)steps);
        usleep(100);
    }
}
