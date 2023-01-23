/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:29:17 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/23 17:09:56 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init(t_cub *cub, int ac, char **av)
{
	if (ac != 2)
		ft_error("Wrong number of arguments.");
	else if (!check_extension(av[1]))
		ft_error("Wrong file extension.");
	cub->txtr.c = NULL;
	cub->txtr.ea = NULL;
	cub->txtr.f = NULL;
	cub->txtr.no = NULL;
	cub->txtr.so = NULL;
	cub->txtr.we = NULL;
}

void	ft_close(int keycode, t_cub *cub)
{
	(void) keycode;
	(void)cub;
	// free_all(cub);
	exit (0);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void deal_key(int key, t_cub *cub)
{
	if (key == ESC)
	{
		mlx_destroy_window(cub->mlx, cub->win_main);
		mlx_destroy_window(cub->mlx, cub->win_data);
		free (cub->mlx);
		exit(0);
	}
	if (key == W || key == A || key == S || key == D)
		move(cub, key);
	else if (key == KEY_LEFT || key == KEY_RIGHT)
		rotate(cub, key);
}

int	main(int ac, char **av)
{
	t_cub	cub;

	init(&cub, ac, av);
	parse(&cub, av[1]);
	cub.mlx = mlx_init();
	cub.img.img = mlx_new_image(cub.mlx, cub.map.w * SIZE, cub.map.h * SIZE);
	cub.img.addr = mlx_get_data_addr(cub.img.img, &cub.img.bits_per_pixel, &cub.img.line_length,
								&cub.img.endian);
	create_window_main(&cub);
	create_window_data(&cub);
	mlx_hook(cub.win_main, 17, 0, (void *)ft_close, &cub);
	mlx_hook(cub.win_main, KEYPRESS, 0, (void *)deal_key, &cub);
	// mlx_put_image_to_window(cub.mlx, cub.win_main, cub.img.img, 0, 0);
	// mlx_mouse_hook(cub.win_main, (void *)click, &cub);
	mlx_loop(cub.mlx);
	// free_all(&cub);
	// return (0);
}
