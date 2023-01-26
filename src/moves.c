/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:29:17 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/26 12:51:31 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	move_up(t_cub *cub, int y)
{
	int		i;
	char	*data;

	i = 0;
	circle(cub, 5, WHITE);
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
	circle(cub, 5, RED);
}

void	move_right(t_cub *cub, int x)
{
	int		i;
	char	*data;

	i = 0;
	circle(cub, 5, WHITE);
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
	circle(cub, 5, RED);
}

void	move_down(t_cub *cub, int y)
{
	int		i;
	char	*data;

	i = 0;
	circle(cub, 5, WHITE);
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
	circle(cub, 5, RED);
}

void	move_left(t_cub *cub, int x)
{
	int		i;
	char	*data;

	i = 0;
	circle(cub, 5, WHITE);
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
	circle(cub, 5, RED);
}

void    move(t_cub *cub, int key)
{
    if (key == W)
		move_up(cub, cub->plr.real_y);
    else if (key == A)
		move_left(cub, cub->plr.real_x);
    else if (key == S)
		move_down(cub, cub->plr.real_y);
    else if (key == D)
		move_right(cub, cub->plr.real_x);
	grid(cub);
	mlx_put_image_to_window(cub->mlx, cub->win_main, cub->img_map.img, 0, 0);
}
