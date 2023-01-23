/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:29:17 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/23 17:27:37 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	move_up(t_cub *cub, int y)
{
	int		i;
	char	*data;

	i = 0;
	circle(cub, 5, WHITE);
	display_pov(cub,WHITE);
	grid(cub);
	while (i < 4 && ((y - i) % SIZE) != 0)
		i++;
	if (cub->map.map[(y / SIZE) - 1][cub->plr.x] == '1')
		cub->plr.real_y -= i;
	else
	{
		cub->plr.real_y -= 3;
		if (cub->plr.real_y % SIZE > SIZE - 3)
		{
			cub->plr.y -= 1;
			data = ft_strjoin(ft_strdup("X : "), ft_itoa(cub->plr.x));
			data = ft_strjoin(data, " | Y : ");
			data = ft_strjoin(data, ft_itoa(cub->plr.y));
			update_data(cub, 1, data);
		}
	}
	display_pov(cub, GREEN);
	circle(cub, 5, RED);
}

void	move_right(t_cub *cub, int x)
{
	int		i;
	char	*data;

	i = 0;
	circle(cub, 5, WHITE);
	display_pov(cub,WHITE);
	grid(cub);
	while (i < 4 && ((x + i) % SIZE) != 0)
		i++;
	if (cub->map.map[cub->plr.y][(x / SIZE) + 1] == '1')
		cub->plr.real_x += i;
	else
	{
		cub->plr.real_x += 3;
		if (cub->plr.real_x % SIZE < 3)
		{
			cub->plr.x += 1;
			data = ft_strjoin(ft_strdup("X : "), ft_itoa(cub->plr.x));
			data = ft_strjoin(data, " | Y : ");
			data = ft_strjoin(data, ft_itoa(cub->plr.y));
			update_data(cub, 1, data);
		}
	}
	display_pov(cub, GREEN);
	circle(cub, 5, RED);
}

void	move_down(t_cub *cub, int y)
{
	int		i;
	char	*data;

	i = 0;
	circle(cub, 5, WHITE);
	display_pov(cub,WHITE);
	grid(cub);
	while (i < 4 && ((y + i) % SIZE) != 0)
		i++;
	if (cub->map.map[(y / SIZE) + 1][cub->plr.x] == '1')
		cub->plr.real_y += i;
	else
	{
		cub->plr.real_y += 3;
		if (cub->plr.real_y % SIZE < 3)
		{
			cub->plr.y += 1;
			data = ft_strjoin(ft_strdup("X : "), ft_itoa(cub->plr.x));
			data = ft_strjoin(data, " | Y : ");
			data = ft_strjoin(data, ft_itoa(cub->plr.y));
			update_data(cub, 1, data);
		}
	}
	display_pov(cub, GREEN);
	circle(cub, 5, RED);
}

void	move_left(t_cub *cub, int x)
{
	int		i;
	char	*data;

	i = 0;
	circle(cub, 5, WHITE);
	display_pov(cub,WHITE);
	grid(cub);
	while (i < 4 && ((x - i) % SIZE) != 0)
		i++;
	if (cub->map.map[cub->plr.y][(x / SIZE) - 1] == '1')
		cub->plr.real_x -= i;
	else
	{
		cub->plr.real_x -= 3;
		if (cub->plr.real_x % SIZE > SIZE - 3)
		{
			cub->plr.x -= 1;
			data = ft_strjoin(ft_strdup("X : "), ft_itoa(cub->plr.x));
			data = ft_strjoin(data, " | Y : ");
			data = ft_strjoin(data, ft_itoa(cub->plr.y));
			update_data(cub, 1, data);
		}
	}
	display_pov(cub, GREEN);
	circle(cub, 5, RED);
}

void    move(t_cub *cub, int key)
{
    if (key == 13)
		move_up(cub, cub->plr.real_y);
    else if (key == 0)
		move_left(cub, cub->plr.real_x);
    else if (key == 1)
		move_down(cub, cub->plr.real_y);
    else if (key == 2)
		move_right(cub, cub->plr.real_x);
	grid(cub);
	mlx_put_image_to_window(cub->mlx, cub->win_main, cub->img.img, 0, 0);
}