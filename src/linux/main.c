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
	// cub->txtr.c = NULL;
	cub->txtr.ea = NULL;
	// cub->txtr.f = NULL;
	cub->txtr.no = NULL;
	cub->txtr.so = NULL;
	cub->txtr.we = NULL;
}

void	ft_close(t_cub *cub)
{
	mlx_destroy_window(cub->mlx, cub->win_game);
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
	if (key == 65307)
		ft_close(cub);
	else if (key == 122 || key == 113 || key == 115 || key == 100)
		get_move(cub, key);
	else if (key == 65361 || key == 65363)
		rotate(cub, key);
}

void	init_textures(t_cub *cub, t_text *text)
{
	text->north.img = mlx_new_image(cub->mlx, 253, 253);
	text->east.img = mlx_new_image(cub->mlx, 253, 253);
	text->south.img = mlx_new_image(cub->mlx, 253, 253);
	text->west.img = mlx_new_image(cub->mlx, 253, 253);
	text->north.img = mlx_xpm_file_to_image(cub->mlx, "./files/textures/North_wall.xpm", &cub->txtr.north_width, &cub->txtr.north_width);
	text->east.img = mlx_xpm_file_to_image(cub->mlx, "./files/textures/East_wall.xpm", &cub->txtr.east_width, &cub->txtr.east_width);
	text->south.img = mlx_xpm_file_to_image(cub->mlx, "./files/textures/South_wall.xpm", &cub->txtr.south_width, &cub->txtr.south_width);
	text->west.img = mlx_xpm_file_to_image(cub->mlx, "./files/textures/West_wall.xpm", &cub->txtr.west_width, &cub->txtr.west_width);
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

void	find_color(void *mlx, t_img img)
{
	int	pix;
	// int		i;
	unsigned int	col;

	// (void)mlx;
	// (void)img;
	// pix = (unsigned int)*img.addr + (125 * img.line_length + 125 * (img.bits_per_pixel / MAP_DIV));
	pix = *(int*)img.addr + (125 * img.line_length + 125 * img.bits_per_pixel);
	col = mlx_get_color_value(mlx, pix);
	printf("%u\n", col);
	// i = -1;
	// while (++i < 24)
	// {
	// 	pix = img.addr + i;
	// 	col = mlx_get_color_value(mlx, *pix);
	// 	(void)col;
	// 	printf("%c\n", *pix);
	// }
	// printf("\n");
}

void	launch(t_cub *cub)
{
	cub->mlx = mlx_init();
	// mlx_do_key_autorepeaton(cub->mlx);
	init_textures(cub, &cub->txtr);
	// find_color(cub->mlx, cub->txtr.north);
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
	mlx_loop(cub->mlx);
}

int	main(int ac, char **av)
{
	t_cub	cub;

	init(&cub, ac, av);
	parse(&cub, av[1]);
	launch(&cub);
}
