/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:29:17 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/20 16:12:05 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	rotate_left(t_cub *cub)
{
	if (cub->angle == 0 || cub->angle == 1 || cub->angle == 2)
		cub->angle += 360;
	cub->angle -= 3;
	update_data(cub, 6, ft_itoa(cub->angle));
}

void	rotate_right(t_cub *cub)
{
	if (cub->angle == 359 || cub->angle == 358 || cub->angle == 357)
		cub->angle -= 360;
	cub->angle += 3;
	update_data(cub, 6, ft_itoa(cub->angle));
}

void	rotate(t_cub *cub, int key)
{
	if (key == KEY_LEFT)
		rotate_left(cub);
	else if (key == KEY_RIGHT)
		rotate_right(cub);
}