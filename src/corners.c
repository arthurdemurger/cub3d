/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corners.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:29:17 by ademurge          #+#    #+#             */
/*   Updated: 2023/02/07 11:44:51 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	north_west(t_vector plr, float *floats, char **map, float angle)
{
	int	x;
	int	y;

	x = (int)floorf(floats[0]);
	y = (int)floorf(floats[1]);
	if ((plr.x < x / SIZE) && (plr.y >= y / SIZE))
		return (WEST);
	else if ((plr.y < y / SIZE) && (plr.x >= x / SIZE))
		return (NORTH);
	if (map[(y - 1) / SIZE][x / SIZE] == '1')
		return (WEST);
	if (map[y / SIZE][(x - 1) / SIZE] == '1')
		return (NORTH);
	if (angle > 45 && angle <= 90)
		return (NORTH);
	return (WEST);
}

int	north_east(t_vector plr, float *floats, char **map, float angle)
{
	int	x;
	int	y;

	x = (int)floorf(floats[0]);
	y = (int)floorf(floats[1]);
	if ((plr.x > x / SIZE) && (plr.y >= y / SIZE))
		return (EAST);
	else if ((plr.y < y / SIZE) && (plr.x <= x / SIZE))
		return (NORTH);
	if (map[(y - 1) / SIZE][x / SIZE] == '1')
		return (EAST);
	if (map[y / SIZE][(x + 1) / SIZE] == '1')
		return (NORTH);
	if (angle > 90 && angle <= 135)
		return (NORTH);
	return (EAST);
}

int	south_west(t_vector plr, float *floats, char **map, float angle)
{
	int	x;
	int	y;

	x = (int)floorf(floats[0]);
	y = (int)floorf(floats[1]);
	if ((plr.x < x / SIZE) && (plr.y <= y / SIZE))
		return (WEST);
	else if ((plr.y > y / SIZE) && (plr.x >= x / SIZE))
		return (SOUTH);
	if (map[(y + 1) / SIZE][x / SIZE] == '1')
		return (WEST);
	if (map[y / SIZE][(x - 1) / SIZE] == '1')
		return (SOUTH);
	if (angle > 270 && angle <= 315)
		return (SOUTH);
	return (WEST);
}

int	south_east(t_vector plr, float *floats, char **map, float angle)
{
	int	x;
	int	y;

	x = (int)floorf(floats[0]);
	y = (int)floorf(floats[1]);
	if (plr.x > x / SIZE && plr.y <= y / SIZE)
		return (EAST);
	else if ((plr.y > y / SIZE) && (plr.x <= x / SIZE))
		return (SOUTH);
	if (map[(y + 1) / SIZE][x / SIZE] == '1')
		return (EAST);
	if (map[y / SIZE][(x + 1) / SIZE] == '1')
		return (SOUTH);
	if (angle > 180 && angle <= 225)
		return (EAST);
	return (SOUTH);
}
