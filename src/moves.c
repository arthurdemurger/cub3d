/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:29:17 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/26 13:48:41 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	move_up(t_cub *cub)
{
	int		i;
	t_ray	pos;

	i = 1;
	circle(cub, 1, RED);
	while (i <= PIX_MOVE)
	{
		printf("angle : %f\n", cub->angle);
		pos = intersection(cub, cub->plr.real_x, cub->plr.real_y, i, cub->angle);
		if (cub->map.map[pos.real_y / SIZE][pos.real_x / SIZE] == '1')
			break ;
		i++;
	}
	cub->plr.real_x = pos.real_x;
	cub->plr.real_y = pos.real_y;
	cub->plr.x = pos.real_x / SIZE;
	cub->plr.y = pos.real_y / SIZE;
	draw(cub);
	circle(cub, 1, RED);
}

void	move_right(t_cub *cub)
{
	int		i;
	t_ray	pos;

	i = 1;
	circle(cub, 1, RED);
	while (i <= PIX_MOVE)
	{
		printf("angle : %f\n", cub->angle);
		pos = intersection(cub, cub->plr.real_x, cub->plr.real_y, i, cub->angle + 90);
		if (cub->map.map[pos.real_y / SIZE][pos.real_x / SIZE] == '1')
			break ;
		i++;
	}
	cub->plr.real_x = pos.real_x;
	cub->plr.real_y = pos.real_y;
	cub->plr.x = pos.real_x / SIZE;
	cub->plr.y = pos.real_y / SIZE;
	draw(cub);
	circle(cub, 1, RED);
}

void	move_down(t_cub *cub)
{
int		i;
	t_ray	pos;

	i = 1;
	circle(cub, 1, RED);
	while (i <= PIX_MOVE)
	{
		printf("angle : %f\n", cub->angle);
		pos = intersection(cub, cub->plr.real_x, cub->plr.real_y, i, cub->angle - 180);
		if (cub->map.map[pos.real_y / SIZE][pos.real_x / SIZE] == '1')
			break ;
		i++;
	}
	cub->plr.real_x = pos.real_x;
	cub->plr.real_y = pos.real_y;
	cub->plr.x = pos.real_x / SIZE;
	cub->plr.y = pos.real_y / SIZE;
	draw(cub);
	circle(cub, 1, RED);
}

void	move_left(t_cub *cub)
{
	int		i;
	t_ray	pos;

	i = 1;
	circle(cub, 1, RED);
	while (i <= PIX_MOVE)
	{
		printf("angle : %f\n", cub->angle);
		pos = intersection(cub, cub->plr.real_x, cub->plr.real_y, i, cub->angle - 90);
		if (cub->map.map[pos.real_y / SIZE][pos.real_x / SIZE] == '1')
			break ;
		i++;
	}
	cub->plr.real_x = pos.real_x;
	cub->plr.real_y = pos.real_y;
	cub->plr.x = pos.real_x / SIZE;
	cub->plr.y = pos.real_y / SIZE;
	draw(cub);
	circle(cub, 1, RED);
}

void	move(t_cub *cub, int key)
{
	clean_map(cub);
	if (key == W)
		move_up(cub);
	else if (key == A)
		move_left(cub);
	else if (key == S)
		move_down(cub);
	else if (key == D)
		move_right(cub);
	grid(cub);
	mlx_put_image_to_window(cub->mlx, cub->win_game, cub->img_map.img, 0, 0);
}
