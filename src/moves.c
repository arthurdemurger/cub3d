/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:29:17 by ademurge          #+#    #+#             */
/*   Updated: 2023/02/07 12:24:45 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

float	abs_angle(float angle)
{
	if (angle >= 0)
		return (angle);
	return (360 + angle);
}

void	is_wall_move2(t_vector *plr, float x, float y)
{
	plr->real_x = x;
	plr->real_y = y;
}

int	is_wall_move(float *floats, t_vector *plr, char **map, float angle)
{
	if (map[(int)floorf(floats[1]) / SIZE]
		[(int)floorf(floats[0] / SIZE)] == '1')
	{
		if (angle >= 315 && angle < 45)
			is_wall_move2(plr, floats[0] - 10, floats[1]);
		else if (angle >= 45 && angle < 135)
			is_wall_move2(plr, floats[0], floats[1] - 10);
		else if (angle >= 135 && angle < 225)
			is_wall_move2(plr, floats[0] + 10, floats[1]);
		else if (angle >= 225 && angle < 315)
			is_wall_move2(plr, floats[0], floats[1] + 10);
		return (1);
	}
	return (0);
}

void	move(t_cub *cub, t_vector *plr, float angle)
{
	float	floats[2];
	float	rad;

	rad = angle * (M_PI / 180);
	circle(cub, 1, WHITE);
	floats[0] = plr->real_x + (PIX_MOVE * cos(rad));
	floats[1] = plr->real_y + (PIX_MOVE * sin(rad));
	if (cub->map.map[(int)floorf(floats[1]) / SIZE]
		[(int)floorf(floats[0]) / SIZE] != '1')
	{
		plr->real_x = floats[0];
		plr->real_y = floats[1];
		plr->x = floats[0] / SIZE;
		plr->y = floats[1] / SIZE;
	}
	draw(cub);
	circle(cub, 1, LIGHT_RED);
}

void	get_move(t_cub *cub, int key)
{
	clean_map(cub);
	if (key == 13)
		move(cub, &cub->plr, cub->angle);
	else if (key == 0)
		move(cub, &cub->plr, abs_angle(cub->angle - 90));
	else if (key == 1)
		move(cub, &cub->plr, abs_angle(cub->angle - 180));
	else if (key == 2)
		move(cub, &cub->plr, abs_angle(cub->angle - 270));
	mlx_put_image_to_window(cub->mlx, cub->win_game, cub->img_map.img, 0, 0);
}
