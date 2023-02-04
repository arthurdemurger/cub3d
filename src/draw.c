/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:29:17 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/27 18:06:47 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	draw_col(t_cub *cub, t_ray ray, int col, int color)
{
	int		i;
	float	height;

	i = WIN_HEIGHT / 2;
	height = (SIZE * SIZE) / floorf(ray.l);
	height *= 25;
	my_mlx_pixel_put(&cub->img_game, col, i, color);
	while (++i <= (WIN_HEIGHT / 2) + ((int)height / 2) && i < 768)
		my_mlx_pixel_put(&cub->img_game, col, i, color);
	i = WIN_HEIGHT / 2;
	while (--i >= (WIN_HEIGHT / 2) - ((int)height / 2) && i >= 0)
		my_mlx_pixel_put(&cub->img_game, col, i, color);
}

void	get_color(t_cub *cub, t_ray ray, int col)
{
	if (ray.side == NORTH)
		draw_col(cub, ray, col, LIGHT_GREEN);
	else if (ray.side == EAST)
		draw_col(cub, ray, col, DARK_GREEN);
	else if (ray.side == SOUTH)
		draw_col(cub, ray, col, BLUE);
	else if (ray.side == WEST)
		draw_col(cub, ray, col, RED);
	else if (ray.side == 5)
		draw_col(cub, ray, col, WHITE);
}

void	draw_game(t_cub *cub)
{
	int	i;

	i = -1;
	while (++i < NB_RAYS)
		get_color(cub, cub->rays[i], i);
	// draw_cursor(cub);
	mlx_put_image_to_window(cub->mlx, cub->win_game, cub->img_game.img, 0, 0);
}

void	init_draw(t_cub *cub)
{
	int	x;
	int	y;

	y = (WIN_HEIGHT / 2) - 1;
	while (--y > 0)
	{
		x = -1;
		while (++x < WIN_WIDTH)
			my_mlx_pixel_put(&cub->img_game, x, y, CEILING);
	}
	y = (WIN_HEIGHT / 2) - 1;
	while (++y < WIN_HEIGHT)
	{
		x = -1;
		while (++x < WIN_WIDTH)
			my_mlx_pixel_put(&cub->img_game, x, y, FLOOR);
	}
}

void	fish_eye_corr(t_cub *cub, t_ray *ray)
{
	float	cos_a;
	float	radian[2];

	radian[0] = ray->angle * (M_PI / 180);
	radian[1] = cub->angle * (M_PI / 180);
	cos_a = cos(radian[0] - radian[1]);
	ray->l *= cos_a;
}

void	draw(t_cub *cub)
{
	int		i;

	i = -1;
	init_draw(cub);
	cub->rays[MID_RAY] = intersection(cub->plr.real_x, cub->plr.real_y, cub->r, cub->angle);
	cub->rays[MID_RAY].angle = cub->angle;
	expand_ray(cub, &cub->rays[MID_RAY]);
	while (++i < MID_RAY)
	{
		cub->rays[i] = intersection(cub->rays[MID_RAY].real_x, cub->rays[MID_RAY].real_y, (cub->plane / (MID_RAY)) * (MID_RAY - i), cub->angle - 90);
		cub->rays[i].angle = cub->angle - angle(SIZE, (cub->plane / MID_RAY) * (MID_RAY - i));
		if (cub->rays[i].angle < 0)
			cub->rays[i].angle = 360 + cub->rays[i].angle;	
		expand_ray(cub, &cub->rays[i]);
		fish_eye_corr(cub, &cub->rays[i]);
	}
	while (++i < NB_RAYS)
	{
		cub->rays[i] = intersection(cub->rays[MID_RAY].real_x, cub->rays[MID_RAY].real_y, (cub->plane / MID_RAY) * (i - MID_RAY), cub->angle + 90);
		cub->rays[i].angle = cub->angle + angle(SIZE, (cub->plane / MID_RAY) * (i - MID_RAY));
		if (cub->rays[i].angle >= 360)
			cub->rays[i].angle -= 360;
		expand_ray(cub, &cub->rays[i]);
		fish_eye_corr(cub, &cub->rays[i]);
	}
	draw_game(cub);
}
