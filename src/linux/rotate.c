/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:29:17 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/27 11:14:49 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

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
	if (key == 65361)
		rotate_left(cub);
	else if (key == 65363)
		rotate_right(cub);
	// grid(cub);
	mlx_put_image_to_window(cub->mlx, cub->win_game, cub->img_map.img, 0, 0);
}
