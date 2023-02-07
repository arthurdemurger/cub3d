/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:29:17 by ademurge          #+#    #+#             */
/*   Updated: 2023/02/07 14:22:47 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	rotate_left(t_cub *cub)
{
	circle(cub, 1, LIGHT_RED);
	if (cub->angle >= 0 && cub->angle < 15)
		cub->angle += 360;
	cub->angle -= 15;
	draw(cub);
}

void	rotate_right(t_cub *cub)
{
	circle(cub, 1, LIGHT_RED);
	if (cub->angle < 360 && cub->angle >= 345)
		cub->angle -= 360;
	cub->angle += 15;
	draw(cub);
}

void	rotate(t_cub *cub, int key)
{
	clean_map(cub);
	if (key == KEY_LEFT)
		rotate_left(cub);
	else if (key == KEY_RIGHT)
		rotate_right(cub);
}
