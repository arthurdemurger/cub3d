/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:29:17 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/26 12:32:16 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	rotate_left(t_cub *cub)
{
	display_pov(cub, WHITE);
	grid(cub);
	circle(cub, 5, RED);
	if (cub->angle >= 0 && cub->angle < ROT_ANGLE)
		cub->angle += 360;
	cub->angle -= ROT_ANGLE;
	draw(cub);
	update_data(cub, 6, ft_itoa(cub->angle));
	display_pov(cub, GREEN);
}

void	rotate_right(t_cub *cub)
{
	display_pov(cub, WHITE);
	grid(cub);
	circle(cub, 5, RED);
	if (cub->angle < 360 && cub->angle >= 360 - ROT_ANGLE)
		cub->angle -= 360;
	cub->angle += ROT_ANGLE;
	display_pov(cub, GREEN);
	draw(cub);
	update_data(cub, 6, ft_itoa(cub->angle));
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
	int		i;

	i = -1;
	cub->rays[MID_RAY].face = 0;
	cub->rays[MID_RAY] = intersection(cub, cub->plr.real_x, cub->plr.real_y, cub->r, cub->angle);
	cub->rays[MID_RAY].angle = cub->angle;
	cub->rays[MID_RAY].l = expand_ray(cub, MID_RAY, cub->rays[MID_RAY].angle, color);
	while (++i < MID_RAY)
	{
		cub->rays[i].face = 0;
		cub->rays[i] = intersection(cub, cub->rays[MID_RAY].real_x, cub->rays[MID_RAY].real_y, (cub->plane / (MID_RAY)) * (MID_RAY - i), cub->angle + 90);
		cub->rays[i].angle = cub->angle - angle(SIZE, (cub->plane / (MID_RAY)) * ((MID_RAY ) - i));
		if (cub->rays[i].angle < 0)
			cub->rays[i].angle = 360 + cub->rays[i].angle;
		cub->rays[i].l = expand_ray(cub, i, cub->rays[i].angle, color);
	}
	while (++i < NB_RAYS)
	{
		cub->rays[i].face = 0;
		cub->rays[i] = intersection(cub, cub->rays[MID_RAY].real_x, cub->rays[MID_RAY].real_y, (cub->plane / (MID_RAY)) * (i - (MID_RAY)), cub->angle - 90);
		cub->rays[i].angle = cub->angle + angle(SIZE, (cub->plane / (MID_RAY)) * (i - (MID_RAY)));
		if (cub->rays[i].angle >= 360)
			cub->rays[i].angle -= 360;
		cub->rays[i].l = expand_ray(cub, i, cub->rays[i].angle, color);
	}
}
