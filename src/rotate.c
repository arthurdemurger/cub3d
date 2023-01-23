/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:29:17 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/23 12:51:27 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	rotate_left(t_cub *cub)
{
	dda_ray0(cub, cub->dir.real_x, cub->dir.real_y, WHITE);
	grid(cub);
	if (cub->angle == 0 || cub->angle == 1 || cub->angle == 2)
		cub->angle += 360;
	cub->angle -= 3;
	update_data(cub, 6, ft_itoa(cub->angle));
	circle(cub, 5, RED);
	cub->dir = intersection(cub->plr.real_x, cub->plr.real_y, cub->r, cub->angle - 90);
	dda_ray0(cub, cub->dir.real_x, cub->dir.real_y, GREEN);
}

void	rotate_right(t_cub *cub)
{
	dda_ray0(cub, cub->dir.real_x, cub->dir.real_y, WHITE);
	grid(cub);
	if (cub->angle == 359 || cub->angle == 358 || cub->angle == 357)
		cub->angle -= 360;
	cub->angle += 3;
	update_data(cub, 6, ft_itoa(cub->angle));
	circle(cub, 5, RED);
	cub->dir = intersection(cub->plr.real_x, cub->plr.real_y, cub->r, cub->angle - 90);
	dda_ray0(cub, cub->dir.real_x, cub->dir.real_y, GREEN);
}

void	rotate(t_cub *cub, int key)
{
	if (key == KEY_LEFT)
		rotate_left(cub);
	else if (key == KEY_RIGHT)
		rotate_right(cub);
}
