/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:29:17 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/20 16:49:21 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	update_pos(t_cub *cub)
{
	char	*data;

	data = ft_strjoin(ft_strdup("x : "), ft_itoa(cub->plr.real_x));
	data = ft_strjoin(data, " | y : ");
	data = ft_strjoin(data, ft_itoa(cub->plr.real_y));
	update_data(cub, 1, data);
}

void	move_up(t_cub *cub, int x, int y)
{
	if ((y - 3) % SIZE != 0)
	{
		draw_square(cub, x, y, WHITE);
		grid(cub);
		cub->plr.real_y -= 3;
		draw_square(cub, x, cub->plr.real_y, RED);
		update_pos(cub);
	}
}

void	move_right(t_cub *cub, int x, int y)
{
	if ((x + 3) % SIZE != 0)
	{
		draw_square(cub, x, y, WHITE);
		grid(cub);
		cub->plr.real_x += 3;
		draw_square(cub, cub->plr.real_x , y, RED);
		update_pos(cub);
	}
}

void	move_down(t_cub *cub, int x, int y)
{
	if ((y + 3) % SIZE != 0)
	{
		draw_square(cub, x, y, WHITE);
		grid(cub);
		cub->plr.real_y += 3;
		draw_square(cub, x, cub->plr.real_y, RED);
		update_pos(cub);
	}
}

void	move_left(t_cub *cub, int x, int y)
{
	if ((x - 3) % SIZE != 0)
	{
		draw_square(cub, x, y, WHITE);
		grid(cub);
		cub->plr.real_x -= 3;
		draw_square(cub, cub->plr.real_x, y, RED);
		update_pos(cub);
	}
}

void    move(t_cub *cub, int key)
{
    if (key == 13)
		move_up(cub, cub->plr.real_x, cub->plr.real_y);
    else if (key == 0)
		move_left(cub, cub->plr.real_x, cub->plr.real_y);
    else if (key == 1)
		move_down(cub, cub->plr.real_x, cub->plr.real_y);
    else if (key == 2)
		move_right(cub, cub->plr.real_x, cub->plr.real_y);
}