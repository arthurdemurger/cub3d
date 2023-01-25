/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:29:17 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/24 18:03:37 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	directions_plus(int ray, t_cub *cub, int demi)
{
	if (cub->angle < 90 || cub->angle > 270)
	{
		if (i < (NB_RAYS / 2))
		{
			if 
				ray->dir = NO;
		}
		else
		{
			ray->dir = NE;
		}
	}
	else if (cub->angle >= 90 && cub->angle <= 270)
	{
		if (i < (NB_RAYS / 2))
			ray->dir = SE;
		else
			ray->dir = SO;
	}
}

int	directions_x(int ray, t_cub *cub, int demi)
{

}