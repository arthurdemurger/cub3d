/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:29:17 by ademurge          #+#    #+#             */
/*   Updated: 2023/02/06 10:56:46 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	draw_col(t_cub *cub, t_ray ray, int col, int color, t_img *img)
{
	int				i;
	float			height;
	int				*pix;

	(void)color;
	(void)img;
	i = WIN_HEIGHT / 2;
	height = (SIZE * SIZE) / floorf(ray.l);
	height *= 25;
	pix = (int*)img->addr + (126 * img->line_length + 126 * img->bits_per_pixel);
	// color = mlx_get_color_value(cub->mlx, *pix);
	my_mlx_pixel_put(&cub->img_game, col, i, color);
	// my_mlx_pixel_put(&cub->img_game, 0, i, mlx_get_color_value(cub->mlx, pix));
	while (++i <= (WIN_HEIGHT / 2) + ((int)height / 2) && i < 768)
	{
		// pix = *(int*)img.addr + (i * img.line_length + col * img.bits_per_pixel);
		my_mlx_pixel_put(&cub->img_game, col, i, color);
		// my_mlx_pixel_put(&cub->img_col, col, i, mlx_get_color_value(cub->mlx, pix));
	}
	i = WIN_HEIGHT / 2;
	while (--i >= (WIN_HEIGHT / 2) - ((int)height / 2) && i >= 0)
	{
		// pix = *(int*)img.addr + (i * img.line_length + col * img.bits_per_pixel);
		my_mlx_pixel_put(&cub->img_game, col, i, color);
		// my_mlx_pixel_put(&cub->img_col, col, i, mlx_get_color_value(cub->mlx, pix));
	}
	// mlx_put_image_to_window(cub->mlx, cub->win_game, cub->img_col.img, col, 0);
}

void	get_color(t_cub *cub, t_ray ray, int col)
{
	if (ray.side == NORTH)
		draw_col(cub, ray, col, DARK_GREEN, &cub->txtr.north);
	else if (ray.side == SOUTH)
		draw_col(cub, ray, col, LIGHT_GREEN, &cub->txtr.south);
	else if (ray.side == EAST)
		draw_col(cub, ray, col, DARK_RED, &cub->txtr.east);
	else if (ray.side == WEST)
		draw_col(cub, ray, col, BLUE, &cub->txtr.west);
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
