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

void	ft_close(t_cub *cub)
{
	mlx_destroy_window(cub->mlx, cub->win_game);
	mlx_destroy_image(cub->mlx, cub->txtr.north);
	mlx_destroy_image(cub->mlx, cub->txtr.east);
	mlx_destroy_image(cub->mlx, cub->txtr.south);
	mlx_destroy_image(cub->mlx, cub->txtr.west);
	mlx_destroy_image(cub->mlx, cub->img_map.img);
	mlx_destroy_image(cub->mlx, cub->img_game.img);
	mlx_destroy_image(cub->mlx, cub->img_col.img);
	free (cub->mlx);
	free_tab(cub->map.map, ft_tablen(cub->map.map));
	exit(0);
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
		ft_close(cub);
	else if (key == 122 || key == 113 || key == 115 || key == 100)
		get_move(cub, key);
	else if (key == 65361 || key == 65363)
		rotate(cub, key);
}

void	init_textures(t_cub *cub, t_text *text)
{
	text->north = mlx_new_image(cub->mlx, 253, 253);
	text->east = mlx_new_image(cub->mlx, 253, 253);
	text->south = mlx_new_image(cub->mlx, 253, 253);
	text->west = mlx_new_image(cub->mlx, 253, 253);
	text->north = mlx_xpm_file_to_image(cub->mlx, "./files/textures/North_wall.xpm", &cub->txtr.north_width, &cub->txtr.north_width);
	text->east = mlx_xpm_file_to_image(cub->mlx, "./files/textures/East_wall.xpm", &cub->txtr.east_width, &cub->txtr.east_width);
	text->south = mlx_xpm_file_to_image(cub->mlx, "./files/textures/South_wall.xpm", &cub->txtr.south_width, &cub->txtr.south_width);
	text->west = mlx_xpm_file_to_image(cub->mlx, "./files/textures/West_wall.xpm", &cub->txtr.west_width, &cub->txtr.west_width);
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
	cub->img_col.img = mlx_new_image(cub->mlx, 1, WIN_HEIGHT);
	cub->img_col.addr = mlx_get_data_addr(cub->img_col.img,
		&cub->img_col.bits_per_pixel, &cub->img_col.line_length,
		&cub->img_col.endian);
	create_window_main(cub);
	// mlx_hook(cub->win_game, DESTROY_BUTTON, 0, (void *)ft_close, cub);
	mlx_key_hook(cub->win_game, (void *)deal_key, cub);
	// mlx_do_key_autorepeaton(cub->mlx);
	mlx_loop(cub->mlx);
}

int	main(int ac, char **av)
{
	t_cub	cub;

	init(&cub, ac, av);
	parse(&cub, av[1]);
	launch(&cub);
}
