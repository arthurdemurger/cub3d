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

void	move_up(t_cub *cub, t_vector *plr, float angle)
{
	int		i;
	float	floats[2];
	float	rad;

	i = 1;
	rad = angle * (M_PI / 180);
	circle(cub, 1, WHITE);
	while (i <= PIX_MOVE)
	{
		floats[0] = plr->real_x + (i * cos(rad));
		floats[1] = plr->real_y + (i * sin(rad));
		if (cub->map.map[(int)floorf(floats[1]) / SIZE][(int)floorf(floats[0]) / SIZE] == '1')
			break ;
		plr->real_x = floats[0];
		plr->real_y = floats[1];
		plr->x = floats[0] / SIZE;
		plr->y = floats[1] / SIZE;
		i++;
	}
	draw(cub);
	circle(cub, 1, RED);
}

void	move_right(t_cub *cub, t_vector *plr, float angle)
{
	int		i;
	float	floats[2];
	float	rad;

	if (angle < 0)
		angle += 360;
	i = 1;
	rad = angle * (M_PI / 180);
	circle(cub, 1, WHITE);
	while (i <= PIX_MOVE)
	{
		floats[0] = plr->real_x + (i * cos(rad));
		floats[1] = plr->real_y + (i * sin(rad));
		if (cub->map.map[(int)floorf(floats[1]) / SIZE][(int)floorf(floats[0]) / SIZE] == '1')
			break ;
		plr->real_x = floats[0];
		plr->real_y = floats[1];
		plr->x = floats[0] / SIZE;
		plr->y = floats[1] / SIZE;
		i++;
	}
	draw(cub);
	circle(cub, 1, RED);
}

void	move_down(t_cub *cub, t_vector *plr, float angle)
{
	int		i;
	float	floats[2];
	float	rad;

	if (angle >= 360)
		angle -= 360;
	i = 1;
	rad = angle * (M_PI / 180);
	circle(cub, 1, WHITE);
	while (i <= PIX_MOVE)
	{
		floats[0] = plr->real_x + (i * cos(rad));
		floats[1] = plr->real_y + (i * sin(rad));
		if (cub->map.map[(int)floorf(floats[1]) / SIZE][(int)floorf(floats[0]) / SIZE] == '1')
			break ;
		plr->real_x = floats[0];
		plr->real_y = floats[1];
		plr->x = floats[0] / SIZE;
		plr->y = floats[1] / SIZE;
		i++;
	}
	draw(cub);
	circle(cub, 1, RED);
}

void	move_left(t_cub *cub, t_vector *plr, float angle)
{
	int		i;
	float	floats[2];
	float	rad;

	if (angle >= 360)
		angle -= 360;
	i = 1;
	rad = angle * (M_PI / 180);
	circle(cub, 1, WHITE);
	while (i <= PIX_MOVE)
	{
		floats[0] = plr->real_x + (i * cos(rad));
		floats[1] = plr->real_y + (i * sin(rad));
		if (cub->map.map[(int)floorf(floats[1]) / SIZE][(int)floorf(floats[0]) / SIZE] == '1')
			break ;
		plr->real_x = floats[0];
		plr->real_y = floats[1];
		plr->x = floats[0] / SIZE;
		plr->y = floats[1] / SIZE;
		i++;
	}
	draw(cub);
	circle(cub, 1, RED);
}

void	move(t_cub *cub, int key)
{
	clean_map(cub);
	if (key == 122)
		move_up(cub, &cub->plr, cub->angle);
	else if (key == 113)
		move_left(cub, &cub->plr, cub->angle - 90);
	else if (key == 115)
		move_down(cub, &cub->plr, cub->angle + 180);
	else if (key == 100)
		move_right(cub, &cub->plr, cub->angle + 90);
	// grid(cub);
	mlx_put_image_to_window(cub->mlx, cub->win_game, cub->img_map.img, 0, 0);
	// printf("%d | %d\n", cub->plr.real_x / SIZE, cub->plr.real_y / SIZE);
}
