/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:29:17 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/23 12:43:48 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	move_up(t_cub *cub, int y)
{
	if ((y - 3) % SIZE != 0)
	{
		circle(cub, 5, WHITE);
		dda_ray0(cub, cub->dir.real_x, cub->dir.real_y, WHITE);
		grid(cub);
		cub->plr.real_y -= 3;
		cub->dir = intersection(cub->plr.real_x, cub->plr.real_y, cub->r, cub->angle - 90);
		dda_ray0(cub, cub->dir.real_x, cub->dir.real_y, GREEN);
		circle(cub, 5, RED);
	}
}

void	move_right(t_cub *cub, int x)
{
	if ((x + 3) % SIZE != 0)
	{
		circle(cub, 5, WHITE);
		dda_ray0(cub, cub->dir.real_x, cub->dir.real_y, WHITE);
		grid(cub);
		cub->plr.real_x += 3;
		cub->dir = intersection(cub->plr.real_x, cub->plr.real_y, cub->r, cub->angle - 90);
		dda_ray0(cub, cub->dir.real_x, cub->dir.real_y, GREEN);
		circle(cub, 5, RED);
	}
}

void	move_down(t_cub *cub, int y)
{
	if ((y + 3) % SIZE != 0)
	{
		circle(cub, 5, WHITE);
		dda_ray0(cub, cub->dir.real_x, cub->dir.real_y, WHITE);
		grid(cub);
		cub->plr.real_y += 3;
		cub->dir = intersection(cub->plr.real_x, cub->plr.real_y, cub->r, cub->angle - 90);
		dda_ray0(cub, cub->dir.real_x, cub->dir.real_y, GREEN);
		circle(cub, 5, RED);
	}
}

void	move_left(t_cub *cub, int x)
{
	if ((x - 3) % SIZE != 0)
	{
		circle(cub, 5, WHITE);
		dda_ray0(cub, cub->dir.real_x, cub->dir.real_y, WHITE);
		grid(cub);
		cub->plr.real_x -= 3;
		cub->dir = intersection(cub->plr.real_x, cub->plr.real_y, cub->r, cub->angle - 90);
		dda_ray0(cub, cub->dir.real_x, cub->dir.real_y, GREEN);
		circle(cub, 5, RED);
	}
}

void    move(t_cub *cub, int key)
{
    if (key == 13)
		move_up(cub, cub->plr.real_y);
    else if (key == 0)
		move_left(cub, cub->plr.real_x);
    else if (key == 1)
		move_down(cub, cub->plr.real_y);
    else if (key == 2)
		move_right(cub, cub->plr.real_x);
}