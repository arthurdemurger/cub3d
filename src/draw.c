/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:29:17 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/26 12:55:15 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	draw_col(t_cub *cub, t_ray ray, int col, int color)
{
	int		i;
	float	height;

	i = WIN_HEIGHT / 2;
	height = ((cub->r * SIZE) / ray.l) * 7;
	my_mlx_pixel_put(&cub->img_game, col, i, color);
	while (++i <= (WIN_HEIGHT / 2) + ((int)height / 2))
		my_mlx_pixel_put(&cub->img_game, col, i, color);
	i = WIN_HEIGHT / 2;
	while (--i >= (WIN_HEIGHT / 2) - ((int)height / 2))
		my_mlx_pixel_put(&cub->img_game, col, i, color);
}

void	get_color(t_cub *cub, t_ray ray, int col)
{
	if (ray.face % 2)
		draw_col(cub, ray, col, LIGHT_GREEN);
	else if (!(ray.face % 2))
		draw_col(cub, ray, col, DARK_GREEN);
}

void	draw_game(t_cub *cub)
{
	int	i;

	i = -1;
	while (++i < NB_RAYS)
		get_color(cub, cub->rays[i], i);
	mlx_put_image_to_window(cub->mlx, cub->win_game, cub->img_game.img, 0, 0);
}

void	init_draw(t_cub *cub)
{
	int	i;
	int	x;
	int	y;

	i = -1;
	while (++i < NB_RAYS)
		cub->rays[i].face = 0;
	y = (WIN_HEIGHT / 2) - 1;
	while (--y > 0)
	{
		x = -1;
		while (++x < WIN_WIDTH)
			my_mlx_pixel_put(&cub->img_game, x, y, BLACK);
	}
	y = 383;
	while (++y < 768)
	{
		x = -1;
		while (++x < 1024)
			my_mlx_pixel_put(&cub->img_game, x, y, 0xCAA472);
	}
}

void	draw(t_cub *cub)
{
	int		i;

	i = -1;
	init_draw(cub);
	cub->rays[NB_RAYS / 2] = intersection(cub, cub->plr.real_x, cub->plr.real_y, cub->r, cub->angle);
	cub->rays[NB_RAYS / 2].angle = cub->angle;
	cub->rays[NB_RAYS / 2].l = expand_ray(cub, cub->rays[NB_RAYS / 2].angle, &cub->rays[NB_RAYS / 2]);
	while (++i <= (NB_RAYS / 2) - 1)
	{
		cub->rays[i] = intersection(cub, cub->rays[(NB_RAYS / 2)].real_x, cub->rays[(NB_RAYS / 2)].real_y, (cub->plane / ((NB_RAYS / 2))) * ((NB_RAYS / ) - i), cub->angle + 90);
		cub->rays[i].angle = cub->angle - angle(SIZE, (cub->plane / (NB_RAYS / 2)) * ((NB_RAYS / ) - i));
		if (cub->rays[i].angle < 0)
			cub->rays[i].angle = 360 + cub->rays[i].angle;
		cub->rays[i].l = expand_ray(cub, cub->rays[i].angle, &cub->rays[i]);
	}
	while (++i < NB_RAYS)
	{
		cub->rays[i] = intersection(cub, cub->rays[(NB_RAYS / 2)].real_x, cub->rays[(NB_RAYS / 2)].real_y, (cub->plane / (NB_RAYS / 2)) * (i - (NB_RAYS / )), cub->angle - 90);
		cub->rays[i].angle = cub->angle + angle(SIZE, (cub->plane / (NB_RAYS / 2)) * (i - (NB_RAYS / )));
		if (cub->rays[i].angle >= 360)
			cub->rays[i].angle -= 360;
		cub->rays[i].l = expand_ray(cub, cub->rays[i].angle, &cub->rays[i]);
		cub->rays[i].l = expand_ray(cub, i, cub->rays[i].angle);
	}
