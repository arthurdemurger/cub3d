/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:29:17 by ademurge          #+#    #+#             */
/*   Updated: 2023/02/06 10:29:52 by gponcele         ###   ########.fr       */
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
	if (key == 123)
		rotate_left(cub);
	else if (key == 124)
		rotate_right(cub);
	// grid(cub);
	mlx_put_image_to_window(cub->mlx, cub->win_game, cub->img_map.img, 0, 0);
}
