/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:29:17 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/27 12:57:22 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

float	abs_angle(float angle)
{
	if (angle >= 0)
		return (angle);
	return (360 + angle);
}

int	is_wall_move(float *floats, t_vector *plr, char **map, float angle)
{
	if (map[(int)floorf(floats[1]) / SIZE][(int)floorf(floats[0] / SIZE)] == '1')
	{
		if (angle >= 315 && angle < 45)
		{
			plr->real_x = floats[0] - 10;
			plr->real_y = floats[1];
		}
		else if (angle >= 45 && angle < 135)
		{
			plr->real_x = floats[0];
			plr->real_y = floats[1] - 10;
		}
		else if (angle >= 135 && angle < 225)
		{
			plr->real_x = floats[0] + 10;
			plr->real_y = floats[1];
		}
		else if (angle >= 225 && angle < 315)
		{
			plr->real_x = floats[0];
			plr->real_y = floats[1] + 10;
		}
		return (1);
	}
	return (0);
}

void	move(t_cub *cub, t_vector *plr, float angle)
{
	int		i;
	float	floats[2];
	float	rad;

	i = 0;
	rad = angle * (M_PI / 180);
	circle(cub, 1, WHITE);
	while (++i <= PIX_MOVE)
	{
		floats[0] = plr->real_x + (i * cos(rad));
		floats[1] = plr->real_y + (i * sin(rad));
		if (is_wall_move(floats, plr, cub->map.map, angle))
			break ;
		plr->real_x = floats[0];
		plr->real_y = floats[1];
	}
	plr->x = floats[0] / SIZE;
	plr->y = floats[1] / SIZE;
	draw(cub);
	circle(cub, 1, RED);
}

void	get_move(t_cub *cub, int key)
{
	clean_map(cub);
	if (key == 122)
		move(cub, &cub->plr, cub->angle);
	else if (key == 113)
		move(cub, &cub->plr, abs_angle(cub->angle - 90));
	else if (key == 115)
		move(cub, &cub->plr, abs_angle(cub->angle - 180));
	else if (key == 100)
		move(cub, &cub->plr, abs_angle(cub->angle - 270));
	// grid(cub);
	mlx_put_image_to_window(cub->mlx, cub->win_game, cub->img_map.img, 0, 0);
	// printf("%d | %d\n", cub->plr.real_x / SIZE, cub->plr.real_y / SIZE);
}
