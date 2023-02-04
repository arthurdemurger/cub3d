/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corners.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:29:17 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/27 16:36:51 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	north_west(t_vector plr, float *floats, char **map)
{
    int   x;
    int   y;

    x = (int)floorf(floats[0]);
    y = (int)floorf(floats[1]);
    if ((plr.x < x / SIZE) && (plr.y >= y / SIZE))
		return (WEST);
	else if ((plr.y < y / SIZE) && (plr.x >= x / SIZE))
		return (NORTH);
    y -= 1;
    if (map[y / SIZE][x / SIZE] == '1')
        return (WEST);
    return (NORTH);
}

int	north_east(t_vector plr, float *floats, char **map)
{
    int   x;
    int   y;

    x = (int)floorf(floats[0]);
    y = (int)floorf(floats[1]);
    if ((plr.x > x / SIZE) && (plr.y >= y / SIZE))
		return (EAST);
	else if ((plr.y < y / SIZE) && (plr.x <= x / SIZE))
		return (NORTH);
    y -= 1;
    if (map[y / SIZE][x / SIZE] == '1')
        return (EAST);
    return (NORTH);
}

int	south_west(t_vector plr, float *floats, char **map)
{
    int   x;
    int   y;

    x = (int)floorf(floats[0]);
    y = (int)floorf(floats[1]);
    if ((plr.x < x / SIZE) && (plr.y <= y / SIZE))
		return (WEST);
	else if ((plr.y > y / SIZE) && (plr.x >= x / SIZE))
		return (SOUTH);
    y += 1;
    if (map[y / SIZE][x / SIZE] == '1')
        return (WEST);
    return (SOUTH);
}

int	south_east(t_vector plr, float *floats, char **map)
{
    int   x;
    int   y;

    x = (int)floorf(floats[0]);
    y = (int)floorf(floats[1]);
    if (plr.x > x / SIZE && plr.y <= y / SIZE)
		return (EAST);
	else if ((plr.y > y / SIZE) && (plr.x <= x / SIZE))
		return (SOUTH);
    y += 1;
    if (map[y / SIZE][x / SIZE] == '1')
        return (EAST);
    return (SOUTH);
}
