/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:29:17 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/27 12:55:40 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	rotate_left(t_cub *cub)
{
	circle(cub, 1, RED);
	if (cub->angle >= 0 && cub->angle < ROT_ANGLE)
		cub->angle += 360;
	cub->angle -= ROT_ANGLE;
	draw(cub);
	// update_data(cub, 6, ft_itoa(cub->angle));
}

void	rotate_right(t_cub *cub)
{
	circle(cub, 1, RED);
	if (cub->angle < 360 && cub->angle >= 360 - ROT_ANGLE)
		cub->angle -= 360;
	cub->angle += ROT_ANGLE;
	draw(cub);
	// update_data(cub, 6, ft_itoa(cub->angle));
}

void	rotate(t_cub *cub, int key)
{
	clean_map(cub);
	if (key == KEY_LEFT)
		rotate_left(cub);
	else if (key == KEY_RIGHT)
		rotate_right(cub);
	grid(cub);
	mlx_put_image_to_window(cub->mlx, cub->win_game, cub->img_map.img, 0, 0);
	// printf("%d | %d\n", cub->plr.real_x / SIZE, cub->plr.real_y / SIZE);
}

// void	init_ray(t_ray *ray, t_cub *cub, int i)
// {
// 	ray->x1 = 0;
// 	ray->xa = 0;
// 	ray->y1 = 0;
// 	ray->ya = 0;
// 	if (cub->angle < 90 || cub->angle > 270)
// 	{
// 		if (i < (NB_RAYS / 2))
// 			ray->dir = NO;
// 		else
// 			ray->dir = NE;
// 	}
// 	else if (cub->angle >= 90 && cub->angle <= 270)
// 	{
// 		if (i < (NB_RAYS / 2))
// 			ray->dir = SE;
// 		else
// 			ray->dir = SO;
// 	}
// }

// void	display_pov(t_cub *cub, int color)
// {
// 	int	i;

// 	i = -1;
// 	cub->rays[NB_RAYS / 2].face = 1;
// 	cub->rays[NB_RAYS / 2] = intersection(cub->plr.real_x, cub->plr.real_y, cub->r, cub->angle);
// 	cub->rays[NB_RAYS / 2].angle = cub->angle;
// 	cub->rays[NB_RAYS / 2].l = expand_ray(cub, cub->rays[NB_RAYS / 2].angle, color);
// 	while (++i <= (NB_RAYS / 2) - 1)
// 	{
// 		cub->rays[i].face = 1;
// 		cub->rays[i] = intersection(cub->rays[NB_RAYS / 2].real_x, cub->rays[NB_RAYS / 2].real_y, (cub->plane / (NB_RAYS / 2)) * (NB_RAYS / 2 - i), cub->angle + 90);
// 		cub->rays[i].angle = cub->angle - angle(SIZE, (cub->plane / (NB_RAYS / 2)) * ((NB_RAYS / 2 ) - i));
// 		if (cub->rays[i].angle < 0)
// 			cub->rays[i].angle = 360 + cub->rays[i].angle;
// 		cub->rays[i].l = expand_ray(cub, cub->rays[i].angle, color);
// 	}
// 	while (++i <= NB_RAYS - 1)
// 	{
// 		cub->rays[i].face = 1;
// 		cub->rays[i] = intersection(cub->rays[NB_RAYS / 2].real_x, cub->rays[NB_RAYS / 2].real_y, (cub->plane / (NB_RAYS / 2)) * (i - (NB_RAYS / 2)), cub->angle - 90);
// 		cub->rays[i].angle = cub->angle + angle(SIZE, (cub->plane / (NB_RAYS / 2)) * (i - (NB_RAYS / 2)));
// 		if (cub->rays[i].angle >= 360)
// 			cub->rays[i].angle -= 360;
// 		// printf("%f\n", cub->rays[i].angle);
// 		cub->rays[i].l = expand_ray(cub, cub->rays[i].angle, color);
// 	}
// }
