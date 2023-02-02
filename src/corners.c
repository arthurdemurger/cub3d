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

int	north_west(t_vector plr, float *floats)
{
    if ((plr.real_x / SIZE < floats[0] / SIZE) && (plr.real_y / SIZE >= floats[1] / SIZE))
		return (WEST);
	else if ((plr.real_y / SIZE < floats[1] / SIZE) && (plr.real_x / SIZE >= floats[0] / SIZE))
		return (NORTH);
    if (floats[3] / SIZE < floats[1] / SIZE || floats[2] / SIZE == floats[0] / SIZE)
        return (NORTH);
    return (WEST);
}

int	north_east(t_vector plr, float *floats)
{
    if ((plr.real_x / SIZE > floats[0] / SIZE) && (plr.real_y / SIZE >= floats[1] / SIZE))
		return (EAST);
	else if ((plr.real_y / SIZE < floats[1] / SIZE) && (plr.real_x / SIZE <= floats[0] / SIZE))
		return (NORTH);
    if (floats[3] / SIZE < floats[1] / SIZE || floats[2] / SIZE == floats[0] / SIZE)
        return(NORTH);
    return (EAST);
}

int	south_west(t_vector plr, float *floats)
{
    if ((plr.real_x / SIZE < floats[0] / SIZE) && (plr.real_y / SIZE <= floats[1] / SIZE))
		return (WEST);
	else if ((plr.real_y / SIZE > floats[1] / SIZE) && (plr.real_x / SIZE >= floats[0] / SIZE))
		return (SOUTH);
    if (floats[3] / SIZE > floats[1] / SIZE || floats[2] / SIZE == floats[0] / SIZE)
        return (SOUTH);
    return (WEST);
}

int	south_east(t_vector plr, float *floats)
{
    if ((plr.real_x / SIZE > floats[0] / SIZE) && (plr.real_y / SIZE <= floats[1] / SIZE))
		return (WEST);
	else if ((plr.real_y / SIZE > floats[1] / SIZE) && (plr.real_x / SIZE <= floats[0] / SIZE))
		return (SOUTH);
    if (floats[3] / SIZE > floats[1] / SIZE || floats[2] / SIZE == floats[0] / SIZE)
        return (SOUTH);
    return (EAST);
}
