/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:29:17 by ademurge          #+#    #+#             */
/*   Updated: 2023/02/07 13:31:38 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	draw_col(t_cub *cub, t_ray ray, int col, t_img *img)
{
	int		ints[2];
	float	height;
	float	line;
	int		*pix;
	float	multi;

	height = ((SIZE * SIZE) / floorf(ray.l)) * 25;
	multi = height / 256.000;
	ints[0] = (768.000 - (int)floorf(height)) / 2;
	ints[1] = ints[0];
	if (ints[1] < 0)
		ints[1] = 0;
	line = 0;
	if (height > 768)
		line += (height - 768.000) / 2;
	while (ints[1] < (768.000 - ints[0]) && ints[1] < 768)
	{
		pix = (int *)img->addr + ((int)floorf(line / multi) * (img->line_length
					/ 4) + (int)floorf(ray.col) * (img->bits_per_pixel / 32));
		my_mlx_pixel_put(&cub->img_col, 0, ints[1],
			mlx_get_color_value(cub->mlx, *pix));
		line += 1.000;
		ints[1]++;
	}
	mlx_put_image_to_window(cub->mlx, cub->win_game, cub->img_col.img, col, 0);
}

void	draw_game(t_cub *cub)
{
	int	i;

	i = -1;
	while (++i < NB_RAYS)
		get_color(cub, cub->rays[i], i);
}

void	init_draw(t_cub *cub)
{
	cub->rays[MID_RAY] = intersection(cub->plr.real_x, cub->plr.real_y,
			cub->r, cub->angle);
	cub->rays[MID_RAY].angle = cub->angle;
	expand_ray(cub, &cub->rays[MID_RAY]);
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
	int	i;

	i = -1;
	init_draw(cub);
	while (++i < MID_RAY)
	{
		cub->rays[i] = intersection(cub->rays[MID_RAY].real_x,
				cub->rays[MID_RAY].real_y, (cub->plane / (MID_RAY))
				* (MID_RAY - i), cub->angle - 90);
		cub->rays[i].angle = cub->angle - angle(SIZE, (cub->plane / MID_RAY)
				* (MID_RAY - i));
		expand_ray(cub, &cub->rays[i]);
		fish_eye_corr(cub, &cub->rays[i]);
	}
	while (++i < NB_RAYS)
	{
		cub->rays[i] = intersection(cub->rays[MID_RAY].real_x,
				cub->rays[MID_RAY].real_y, (cub->plane / MID_RAY)
				* (i - MID_RAY), cub->angle + 90);
		cub->rays[i].angle = cub->angle + angle(SIZE, (cub->plane / MID_RAY)
				* (i - MID_RAY));
		expand_ray(cub, &cub->rays[i]);
		fish_eye_corr(cub, &cub->rays[i]);
	}
	draw_game(cub);
}
