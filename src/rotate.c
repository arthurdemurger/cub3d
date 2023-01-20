/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:29:17 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/20 16:59:10 by ademurge         ###   ########.fr       */
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
