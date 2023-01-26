/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:29:17 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/25 17:52:08 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	draw_col(t_cub *cub, float l, int col, int color)
{
	int		i;
	float	height;

	i = 384;
	height = ((cub->r * SIZE) / l) * 7;
	my_mlx_pixel_put(&cub->img_game, col, i, color);
	while (++i <= 384 + ((int)height / 2))
		my_mlx_pixel_put(&cub->img_game, col, i, color);
	i = 384;
	while (--i >= 384 - ((int)height / 2))
		my_mlx_pixel_put(&cub->img_game, col, i, color);
}

void	get_color(t_cub *cub, t_ray ray, int col)
{
	if (ray.face % 2)
		draw_col(cub, ray.l, col, LIGHT_GREEN);
	else if (!ray.face % 2)
		draw_col(cub, ray.l, col, DARK_GREEN);
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
	y = 383;
	while (--y > 0)
	{
		x = -1;
		while (++x < 1024)
			my_mlx_pixel_put(&cub->img_game, x, y, 0x000000);
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
	int	i;
	
	i = -1;
	init_draw(cub);
	cub->rays[NB_RAYS / 2] = intersection(cub, cub->plr.real_x, cub->plr.real_y, cub->r, cub->angle);
	cub->rays[NB_RAYS / 2].angle = cub->angle;
	cub->rays[NB_RAYS / 2].l = expand_ray(cub, cub->rays[NB_RAYS / 2].angle, &cub->rays[NB_RAYS / 2]);
	while (++i <= (NB_RAYS / 2) - 1)
	{
		cub->rays[i] = intersection(cub, cub->rays[NB_RAYS / 2].real_x, cub->rays[NB_RAYS / 2].real_y, (cub->plane / (NB_RAYS / 2)) * (NB_RAYS / 2 - i), cub->angle + 90);
		cub->rays[i].angle = cub->angle - angle(SIZE, (cub->plane / (NB_RAYS / 2)) * ((NB_RAYS / 2 ) - i));
		if (cub->rays[i].angle < 0)
			cub->rays[i].angle = 360 + cub->rays[i].angle;
		cub->rays[i].l = expand_ray(cub, cub->rays[i].angle, &cub->rays[i]);
	}
	while (++i <= NB_RAYS - 1)
	{
		cub->rays[i] = intersection(cub, cub->rays[NB_RAYS / 2].real_x, cub->rays[NB_RAYS / 2].real_y, (cub->plane / (NB_RAYS / 2)) * (i - (NB_RAYS / 2)), cub->angle - 90);
		cub->rays[i].angle = cub->angle + angle(SIZE, (cub->plane / (NB_RAYS / 2)) * (i - (NB_RAYS / 2)));
		if (cub->rays[i].angle >= 360)
			cub->rays[i].angle -= 360;
		cub->rays[i].l = expand_ray(cub, cub->rays[i].angle, &cub->rays[i]);
	}
	draw_game(cub);
}