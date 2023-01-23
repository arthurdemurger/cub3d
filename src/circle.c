/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:29:17 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/23 12:46:01 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// void drawCircle(t_cub *cub, int xc, int yc, int x, int y)
// {
//     mlx_pixel_put(cub->mlx, cub->win_main, xc+x, yc+y, RED);
//     mlx_pixel_put(cub->mlx, cub->win_main, xc-x, yc+y, RED);
//     mlx_pixel_put(cub->mlx, cub->win_main, xc+x, yc-y, RED);
//     mlx_pixel_put(cub->mlx, cub->win_main, xc-x, yc-y, RED);
//     mlx_pixel_put(cub->mlx, cub->win_main, xc+y, yc+x, RED);
//     mlx_pixel_put(cub->mlx, cub->win_main, xc-y, yc+x, RED);
//     mlx_pixel_put(cub->mlx, cub->win_main, xc+y, yc-x, RED);
//     mlx_pixel_put(cub->mlx, cub->win_main, xc-y, yc-x, RED);
// }
 
// // Function for circle-generation
// // using Bresenham's algorithm
// t_vector circle(t_cub *cub, int xc, int yc, int r, int color)
// {
//     int 		x = 0, y = r;
//     int 		d = 3 - 2 * r;
// 	t_vector	dir;

// 	(void)color;
//     drawCircle(cub, xc, yc, x, y);
//     while (y >= x)
//     {
//         // for each pixel we will
//         // draw all eight pixels
         
//         x++;
 
//         // check for decision parameter
//         // and correspondingly
//         // update d, x, y
//         if (d > 0)
//         {
//             y--;
//             d = d + 4 * (x - y) + 10;
//         }
//         else
//             d = d + 4 * x + 6;
//         drawCircle(cub, xc, yc, x, y);
//     }
// 	return (dir);
// }

// void	circle(t_cub *cub, int r, int color)
// {	
// 	float		i;
// 	t_vector	dir;
	
// 	i = 0;
// 	dir.x = 0;
// 	// draw_square(cub, cub->plr.real_x + round(r * cos(i)), cub->plr.real_y + round(r * sin(i)), color);
// 	while (i <= 360)
// 	{
// 		mlx_pixel_put(cub->mlx, cub->win_main, cub->plr.real_x + round((r * (3.14 / 180)) * cos(i)), cub->plr.real_y + round((r * (3.14 / 180)) * sin(i)), color);
// 		if (i == cub->angle)
// 		{
// 			dir.real_x = round(cub->plr.real_x + ((r * (3.14 / 180)) * cos(i)));
// 			dir.real_y = round(cub->plr.real_y + ((r * (3.14 / 180)) * sin(i)));
// 		}
// 		i += 0.1;
// 	}
// 	// printf("Real X : %d\nReal Y : %d\n", dir.real_x, dir.real_y);
// 	return (dir);
// }

void	circle(t_cub *cub, int r, int color)
{
	float		rad;
	int			x, y;

	for (float angle = 0; angle <= 360; angle += 0.1) 
	{
	    rad = angle * (M_PI / 180);
	    x = cub->plr.real_x + r * cos(rad);
	    y = cub->plr.real_y + r * sin(rad);
		mlx_pixel_put(cub->mlx, cub->win_main, x, y, color);
	}
}

t_vector intersection(int cx, int cy, int r, float angle) 
{
	t_vector dir;

    float rad = angle * (M_PI / 180);
    int x = cx + r * cos(rad);
    int y = cy + r * sin(rad);
	dir.real_x = x;
	dir.real_y = y;
	return (dir);
}