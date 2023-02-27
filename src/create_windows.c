/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_windows.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:29:17 by ademurge          #+#    #+#             */
/*   Updated: 2023/02/27 11:42:48 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	create_window_main(t_cub *cub)
{
	cub->win_game = mlx_new_window(cub->mlx, WIN_WIDTH, WIN_HEIGHT,
			"Cub3D - Game");
	circle(cub, 1, LIGHT_RED);
	draw(cub);
}
