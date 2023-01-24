/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:29:17 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/24 12:43:03 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	rotate_left(t_cub *cub)
{
	dda(cub, cub->rays[90].real_x, cub->rays[90].real_y, WHITE, 0, 1);
	display_pov(cub, WHITE);
	draw(cub, 0);
	grid(cub);
	circle(cub, 5, RED);
	if (cub->angle == 0 || cub->angle == 1 || cub->angle == 2)
		cub->angle += 360;
	cub->angle -= 15;
	update_data(cub, 6, ft_itoa(cub->angle));
	display_pov(cub, GREEN);
}

void	rotate_right(t_cub *cub)
{
	dda(cub, cub->rays[90].real_x, cub->rays[90].real_y, WHITE, 0, 1);
	display_pov(cub, WHITE);
	draw(cub, 0);
	grid(cub);
	circle(cub, 5, RED);
	if (cub->angle == 359 || cub->angle == 358 || cub->angle == 357)
		cub->angle -= 360;
	cub->angle += 15;
	update_data(cub, 6, ft_itoa(cub->angle));
	display_pov(cub, GREEN);
}

void	rotate(t_cub *cub, int key)
{
	if (key == KEY_LEFT)
		rotate_left(cub);
	else if (key == KEY_RIGHT)
		rotate_right(cub);
	grid(cub);
	mlx_put_image_to_window(cub->mlx, cub->win_main, cub->img_map.img, 0, 0);
}

void	display_pov(t_cub *cub, int color)
{
	int	i;
	
	i = -1;
	cub->rays[128] = intersection(cub->plr.real_x, cub->plr.real_y, cub->r, cub->angle - 90);
	while (++i <= 127)
	{
		cub->rays[i].face = 0;
		cub->rays[i] = intersection(cub->rays[128].real_x, cub->rays[128].real_y, (cub->plane / 128) * (128 - i), cub->angle - 180);
		cub->rays[i].l = dda(cub, cub->rays[i].real_x, cub->rays[i].real_y, color, i, 1);
	}
	cub->rays[128].l = dda(cub, cub->rays[128].real_x, cub->rays[128].real_y, color, i, 1);
	while (++i <= 255)
	{
		cub->rays[i].face = 0;
		cub->rays[i] = intersection(cub->rays[128].real_x, cub->rays[128].real_y, (cub->plane / 128) * (i - 128), cub->angle);
		cub->rays[i].l = dda(cub, cub->rays[i].real_x, cub->rays[i].real_y, color, i, 1);
	}
}