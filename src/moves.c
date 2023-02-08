/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:29:17 by ademurge          #+#    #+#             */
/*   Updated: 2023/02/08 11:51:22 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

float	abs_angle(float angle)
{
	if (angle >= 0)
		return (angle);
	return (360 + angle);
}

void	move(t_cub *cub, t_vector *plr, float angle)
{
	float	floats[2];
	float	rad;

	rad = angle * (M_PI / 180);
	circle(cub, 1, 0xf3ddc1);
	floats[0] = plr->real_x + (PIX_MOVE * cos(rad));
	floats[1] = plr->real_y + (PIX_MOVE * sin(rad));
	if (cub->map.map[(int)floorf(floats[1]) / SIZE]
		[(int)floorf(floats[0]) / SIZE] != '1')
	{
		plr->real_x = floats[0];
		plr->real_y = floats[1];
		plr->x = floats[0] / SIZE;
		plr->y = floats[1] / SIZE;
	}
	draw(cub);
	circle(cub, 1, LIGHT_RED);
}

void	get_move(t_cub *cub, int key)
{
	clean_map(cub);
	if (key == W)
		move(cub, &cub->plr, cub->angle);
	else if (key == A)
		move(cub, &cub->plr, abs_angle(cub->angle - 90));
	else if (key == S)
		move(cub, &cub->plr, abs_angle(cub->angle - 180));
	else if (key == D)
		move(cub, &cub->plr, abs_angle(cub->angle - 270));
}

void	deal_key(int key, t_cub *cub)
{
	if (key == ESC)
		ft_close(cub);
	if (key == TAB)
	{
		if (cub->display_map == 0)
			display_map(cub, 1);
		else
			display_map(cub, 0);
	}
	if (cub->display_map == 0)
	{
		if (key == W || key == A || key == S || key == D)
			get_move(cub, key);
		else if (key == KEY_LEFT || key == KEY_RIGHT)
			rotate(cub, key);
	}
}
