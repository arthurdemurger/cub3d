/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:29:17 by ademurge          #+#    #+#             */
/*   Updated: 2023/02/07 11:05:11 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init(t_cub *cub, int ac, char **av)
{
	if (ac != 2)
		ft_error("Wrong number of arguments.");
	else if (!check_extension(av[1]))
		ft_error("Wrong file extension.");
	cub->txtr.ea = NULL;
	cub->txtr.no = NULL;
	cub->txtr.so = NULL;
	cub->txtr.we = NULL;
	cub->txtr.c = -1;
	cub->txtr.f = -1;
}

void	ft_close(t_cub *cub)
{
	mlx_destroy_window(cub->mlx, cub->win_game);
	// mlx_destroy_window(cub->mlx, cub->win_test);
	mlx_destroy_image(cub->mlx, cub->txtr.north.img);
	mlx_destroy_image(cub->mlx, cub->txtr.east.img);
	mlx_destroy_image(cub->mlx, cub->txtr.south.img);
	mlx_destroy_image(cub->mlx, cub->txtr.west.img);
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
	if (key == 53)
		ft_close(cub);
	else if (key == 13 || key == 0 || key == 1 || key == 2)
		get_move(cub, key);
	else if (key == 123 || key == 124)
		rotate(cub, key);
}

void	init_textures(t_cub *cub, t_text *text)
{
	text->north.img = mlx_new_image(cub->mlx, 253, 253);
	text->east.img = mlx_new_image(cub->mlx, 253, 253);
	text->south.img = mlx_new_image(cub->mlx, 253, 253);
	text->west.img = mlx_new_image(cub->mlx, 253, 253);
	text->north.img = mlx_xpm_file_to_image(cub->mlx, "./files/textures/North_wall.xpm", &text->north_width, &text->north_height);
	text->east.img = mlx_xpm_file_to_image(cub->mlx, "./files/textures/East_wall.xpm", &text->east_width, &text->east_height);
	text->south.img = mlx_xpm_file_to_image(cub->mlx, "./files/textures/South_wall.xpm", &text->south_width, &text->south_height);
	text->west.img = mlx_xpm_file_to_image(cub->mlx, "./files/textures/West_wall.xpm", &text->west_width, &text->west_height);
	text->north.addr = mlx_get_data_addr(text->north.img,
		&text->north.bits_per_pixel, &text->north.line_length,
		&text->north.endian);
	text->east.addr = mlx_get_data_addr(text->east.img,
		&text->east.bits_per_pixel, &text->east.line_length,
		&text->east.endian);
	text->south.addr = mlx_get_data_addr(text->south.img,
		&text->south.bits_per_pixel, &text->south.line_length,
		&text->south.endian);
	text->west.addr = mlx_get_data_addr(text->west.img,
		&text->west.bits_per_pixel, &text->west.line_length,
		&text->west.endian);
}

// void	display_xpm(t_cub *cub)
// {
// 	cub->img_col_test.img = mlx_new_image(cub->mlx, 300, 300);
// 	cub->img_col_test.img = mlx_xpm_file_to_image(cub->mlx, "./files/textures/North_wall.xpm", &cub->width_test, &cub->height_test);
// 	cub->win_test = mlx_new_window(cub->mlx, 300, 300, "Cub3D - Test");
// 	mlx_put_image_to_window(cub->mlx, cub->win_test, cub->img_col_test.img, 0, 0);
// }

void	launch(t_cub *cub)
{
	cub->mlx = mlx_init();
	init_textures(cub, &cub->txtr);
	// display_xpm(cub);
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
	mlx_hook(cub->win_game, DESTROY_BUTTON, 0, (void *)ft_close, cub);
	mlx_hook(cub->win_game, KEYPRESS, 0, (void *)deal_key, cub);
	mlx_loop(cub->mlx);
}

int	main(int ac, char **av)
{
	t_cub	cub;

	init(&cub, ac, av);
	parse(&cub, av[1]);
	launch(&cub);
}
