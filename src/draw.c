/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:29:17 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/27 18:04:56 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	draw_col(t_cub *cub, t_ray ray, int col, int color)
{
	int		i;
	float	height;

	i = WIN_HEIGHT / 2;
	height = ((cub->r * SIZE) / ray.real_l) * 7;
	my_mlx_pixel_put(&cub->img_game, col, i, color);
	while (++i <= (WIN_HEIGHT / 2) + ((int)height / 2) && i < 768)
		my_mlx_pixel_put(&cub->img_game, col, i, color);
	i = WIN_HEIGHT / 2;
	while (--i >= (WIN_HEIGHT / 2) - ((int)height / 2) && i >= 0)
		my_mlx_pixel_put(&cub->img_game, col, i, color);
}

void	get_color(t_cub *cub, t_ray ray, int col)
{
	// if (ray.face == 5)
	// 	draw_col(cub, ray, col, BLACK);
	if (ray.side % 2)
		draw_col(cub, ray, col, LIGHT_GREEN);
	else if (!(ray.side % 2))
		draw_col(cub, ray, col, DARK_GREEN);
}

void	draw_game(t_cub *cub)
{
	int	i;

	i = -1;
	while (++i < NB_RAYS)
		get_color(cub, cub->rays[i], i);
	printf("=====\n");
	draw_cursor(cub);
	mlx_put_image_to_window(cub->mlx, cub->win_game, cub->img_game.img, 0, 0);
}

void	init_draw(t_cub *cub)
{
	// int	i;
	int	x;
	int	y;

	// i = -1;
	// while (++i < NB_RAYS)
	// {
	// 	cub->rays[i].side = 0;
	// 	cub->rays[i].l_h = 0;
	// 	cub->rays[i].l_v = 0;
	// }
	y = (WIN_HEIGHT / 2) - 1;
	while (--y > 0)
	{
		x = -1;
		while (++x < WIN_WIDTH)
			my_mlx_pixel_put(&cub->img_game, x, y, BLACK);
	}
	y = (WIN_HEIGHT / 2) - 1;
	while (++y < WIN_HEIGHT)
	{
		x = -1;
		while (++x < WIN_WIDTH)
			my_mlx_pixel_put(&cub->img_game, x, y, FLOOR);
	}
}

t_pos	find_angle(t_pos point1, t_pos point2, int side)
{
	float	angle;
	t_pos	pos;

	angle = atan2(point2.y - point1.y, point2.x - point1.x);
	if (side == 1)
		angle += M_PI_2;
	else
		angle -= M_PI_2;
	pos.x = point2.x + cos(angle);
	pos.y = point2.y + sin(angle);
	return (pos);
}

void	fish_eye_corr(t_cub *cub, int index)
{
	float	angle;
	float	radian;

	if (index < MID_RAY)
		angle = min_angle(cub->angle, cub->rays[index].angle);
	else
		angle = add_angle(cub->angle, cub->rays[index].angle);
	radian = angle * (M_PI / 180);
	cub->rays[index].real_l = cub->rays[index].l * cos(radian);
	printf("real length : %f\n     length : %f\n=====\n", cub->rays[index].real_l, cub->rays[index].l);
}

void	draw(t_cub *cub)
{
	int		i;

	i = -1;
	init_draw(cub);
	cub->rays[MID_RAY] = intersection(cub->plr.real_x, cub->plr.real_y, cub->r, cub->angle);
	cub->rays[MID_RAY].angle = cub->angle;
	expand_ray(cub, MID_RAY, &cub->rays[MID_RAY]);
	while (++i < MID_RAY)
	{
		cub->rays[i] = intersection(cub->rays[(NB_RAYS / 2)].real_x, cub->rays[(NB_RAYS / 2)].real_y, (cub->plane / ((NB_RAYS / 2))) * ((NB_RAYS / 2) - i), cub->angle + 90);
		cub->rays[i].angle = cub->angle - angle(SIZE, (cub->plane / (NB_RAYS / 2)) * ((NB_RAYS / 2) - i));
		if (cub->rays[i].angle < 0)
			cub->rays[i].angle = 360 + cub->rays[i].angle;
		expand_ray(cub, &cub->rays[i]);
		fish_eye_corr(cub, i);
	}
	while (++i < NB_RAYS)
	{
		cub->rays[i] = intersection(cub->rays[(NB_RAYS / 2)].real_x, cub->rays[(NB_RAYS / 2)].real_y, (cub->plane / (NB_RAYS / 2)) * (i - (NB_RAYS / 2)), cub->angle - 90);
		cub->rays[i].angle = cub->angle + angle(SIZE, (cub->plane / (NB_RAYS / 2)) * (i - (NB_RAYS / 2)));
		if (cub->rays[i].angle >= 360)
			cub->rays[i].angle -= 360;
		expand_ray(cub, &cub->rays[i]);
		fish_eye_corr(cub, i);
	}
	draw_game(cub);
}
