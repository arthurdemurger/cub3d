/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:29:17 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/27 12:59:41 by gponcele         ###   ########.fr       */
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
	(void)keycode;
	(void)cub;
	exit (0);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / MAP_DIV));
	*(unsigned int*)dst = color;
}

void deal_key(int key, t_cub *cub)
{
	if (key == 65307)
	{
		mlx_destroy_window(cub->mlx, cub->win_game);
		free (cub->txtr.north);
		free (cub->txtr.east);
		free (cub->txtr.south);
		free (cub->txtr.west);
		free (cub->img_map.img);
		free (cub->img_game.img);
		free (cub->mlx);
		free_tab(cub->map.map, ft_tablen(cub->map.map));
		exit(0);
	}
	if (key == 122 || key == 113 || key == 115 || key == 100)
		get_move(cub, key);
	else if (key == 65361 || key == 65363)
		rotate(cub, key);
}

void	init_textures(t_cub *cub, t_text *text)
{
	int	size;

	size = SIZE * 1;
	text->north = mlx_new_image(cub->mlx, 64, 64);
	text->east = mlx_new_image(cub->mlx, 64, 64);
	text->south = mlx_new_image(cub->mlx, 64, 64);
	text->west = mlx_new_image(cub->mlx, 64, 64);
	text->north = mlx_xpm_file_to_image(cub->mlx, "./files/textures/north_wall.xpm", &size, &size);
	text->east = mlx_xpm_file_to_image(cub->mlx, "./files/textures/east_wall.xpm", &size, &size);
	text->south = mlx_xpm_file_to_image(cub->mlx, "./files/textures/south_wall.xpm", &size, &size);
	text->west = mlx_xpm_file_to_image(cub->mlx, "./files/textures/west_wall.xpm", &size, &size);
}

void	launch(t_cub *cub)
{
	cub->mlx = mlx_init();
	init_textures(cub, &cub->txtr);
	cub->img_map.img = mlx_new_image(cub->mlx, (cub->map.w * SIZE) / MAP_DIV,
		(cub->map.h * SIZE) / MAP_DIV);
	cub->img_map.addr = mlx_get_data_addr(cub->img_map.img,
		&cub->img_map.bits_per_pixel, &cub->img_map.line_length,
		&cub->img_map.endian);
	cub->img_game.img = mlx_new_image(cub->mlx, WIN_WIDTH, WIN_HEIGHT);
	cub->img_game.addr = mlx_get_data_addr(cub->img_game.img,
		&cub->img_game.bits_per_pixel, &cub->img_game.line_length,
		&cub->img_game.endian);
	create_window_main(cub);
	// create_window_data(cub);
	// mlx_hook(cub->win_game, DESTROY_BUTTON, 0, (void *)ft_close, cub);
	mlx_key_hook(cub->win_game, (void *)deal_key, cub);
	mlx_loop(cub->mlx);
}

int	main(int ac, char **av)
{
	t_cub	cub;

	init(&cub, ac, av);
	parse(&cub, av[1]);
	launch(&cub);
}
