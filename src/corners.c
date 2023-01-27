/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corners.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:29:17 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/27 12:52:38 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	north_west(t_vector plr, int x, int y)
{
	if ((plr.real_x / SIZE < x / SIZE) && (plr.real_y / SIZE == y / SIZE))
		return (WEST);
	else if ((plr.real_y / SIZE < y / SIZE) && (plr.real_x / SIZE == x / SIZE))
		return (NORTH);
	return (5);
}

int	north_east(t_vector plr, int x, int y)
{
	if ((plr.real_x / SIZE > x / SIZE) && (plr.real_y / SIZE == y / SIZE))
		return (EAST);
	else if ((plr.real_y / SIZE < y / SIZE) && (plr.real_x / SIZE == x / SIZE))
		return (NORTH);
	return (5);
}

int	south_west(t_vector plr, int x, int y)
{
	if ((plr.real_x / SIZE < x / SIZE) && (plr.real_y / SIZE == y / SIZE))
		return (WEST);
	else if ((plr.real_y / SIZE > y / SIZE) && (plr.real_x / SIZE == x / SIZE))
		return (SOUTH);
	return (5);
}

int	south_east(t_vector plr, int x, int y)
{
	if ((plr.real_x / SIZE > x / SIZE) && (plr.real_y / SIZE == y / SIZE))
		return (WEST);
	else if ((plr.real_y / SIZE > y / SIZE) && (plr.real_x / SIZE == x / SIZE))
		return (SOUTH);
	return (5);
}
