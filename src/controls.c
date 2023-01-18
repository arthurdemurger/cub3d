/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:39:34 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/16 15:02:53 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	ft_close(t_cub *cub)
{
	(void) cub;
	exit(EXIT_SUCCESS);
}

int	is_input_linux(int key)
{
	if (key == 122)
		return (1);
	else if (key == 113)
		return (1);
	else if (key == 115)
		return (1);
	else if (key == 100)
		return (1);
	else if (key == 65361)
		return (1);
	else if (key == 65363)
		return (1);
	return (0);
}

// int	is_input_mac(int key)
// {
// 	if (key == )
// 		return (1);
// 	else if (key == )
// 		return (1);
// 	else if (key == )
// 		return (1);
// 	else if (key == )
// 		return (1);
// 	else if (key == )
// 		return (1);
// 	else if (key == )
// 		return (1);
// 	return (0);
// }

/*
LINUX KEYS
Z = 122
Q = 113
S = 115
D = 100
< = 65361
> = 65363
ESC = 65307
=================
MAC KEYS
W = 13
A = 0
S = 1
D = 2
< = 123
> = 124
ESC = 53
*/

int	deal_key(int key, t_cub *cub)
{
	if (key == ESC)
		ft_close(cub);
	else if (key == W)
		ICI
	return (key);
}

void	controls(t_cub *cub)
{
	mlx_hook(cub->win, DESTROY_BUTTON, 0, ft_close, &cub);
	mlx_key_hook(cub->win, deal_key, &cub);
	mlx_loop(cub->mlx);
}
