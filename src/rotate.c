/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:29:17 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/25 13:58:48 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	rotate_left(t_cub *cub)
{
	display_pov(cub, WHITE);
	draw(cub, 0);
	grid(cub);
	circle(cub, 5, RED);
	if (cub->angle == 0 || cub->angle == 1 || cub->angle == 2)
		cub->angle += 360;
	cub->angle -= 15;
	draw(cub, 1);
	update_data(cub, 6, ft_itoa(cub->angle));
	display_pov(cub, GREEN);
}

void	rotate_right(t_cub *cub)
{
	display_pov(cub, WHITE);
	draw(cub, 0);
	grid(cub);
	circle(cub, 5, RED);
	if (cub->angle == 359 || cub->angle == 358 || cub->angle == 357)
		cub->angle -= 360;
	cub->angle += 15;
	draw(cub, 1);
	update_data(cub, 6, ft_itoa(cub->angle));
	display_pov(cub, GREEN);
}

void	rotate(t_cub *cub, int key)
{
	if (key == KEY_LEFT)
		rotate_left(cub);
	else if (key == KEY_RIGHT)
		rotate_right(cub);
	grid(cub);
	mlx_put_image_to_window(cub->mlx, cub->win_main, cub->img_map.img, 0, 0);
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

void	display_pov(t_cub *cub, int color)
{
	int	i;
	
	i = -1;
	cub->rays[NB_RAYS / 2].face = 0;
	cub->rays[NB_RAYS / 2] = intersection(cub, cub->plr.real_x, cub->plr.real_y, SIZE, cub->angle - 90);
	cub->rays[NB_RAYS / 2].angle = cub->angle;
	cub->rays[NB_RAYS / 2].l = expand_ray(cub, cub->rays[NB_RAYS / 2].angle);
	dda(cub, cub->rays[NB_RAYS / 2].real_x, cub->rays[NB_RAYS / 2].real_y, color, i);
	while (++i <= (NB_RAYS / 2) - 1)
	{
		cub->rays[i].face = 0;
		cub->rays[i] = intersection(cub, cub->rays[NB_RAYS / 2].real_x, cub->rays[NB_RAYS / 2].real_y, (cub->plane / (NB_RAYS / 2)) * (NB_RAYS / 2 - i), cub->angle - 180);
		cub->rays[i].angle = cub->rays[NB_RAYS / 2].angle - angle(SIZE, (cub->plane / (NB_RAYS / 2)) * ((NB_RAYS / 2 ) - i));
		printf("%f\n", cub->rays[i].angle);
		cub->rays[i].l = expand_ray(cub, cub->rays[i].angle);
		dda(cub, cub->rays[i].real_x, cub->rays[i].real_y, color, i);
	}
	while (++i <= NB_RAYS - 1)
	{
		cub->rays[i].face = 0;
		cub->rays[i] = intersection(cub, cub->rays[NB_RAYS / 2].real_x, cub->rays[NB_RAYS / 2].real_y, (cub->plane / NB_RAYS / 2) * (i - (NB_RAYS / 2)), cub->angle);
		cub->rays[i].angle = cub->rays[NB_RAYS / 2].angle + angle(SIZE, (cub->plane / (NB_RAYS / 2)) * (i - (NB_RAYS / 2)));
		printf("%f\n", cub->rays[i].angle);
		cub->rays[i].l = expand_ray(cub, cub->rays[i].angle);
		dda(cub, cub->rays[i].real_x, cub->rays[i].real_y, color, i);
	}
}