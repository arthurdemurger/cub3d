/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:29:17 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/20 17:07:09 by ademurge         ###   ########.fr       */
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

int	is_input_linux(int key)
{
	if (key == 122)
		return (1);
	else if (key == 113)
		return (1);
	else if (key == 115)
		return (1);
	else if (key == 100)
		return (1);
	else if (key == 65361)
		return (1);
	else if (key == 65363)
		return (1);
	return (0);
}

// int	is_input_mac(int key)
// {
// 	if (key == )
// 		return (1);
// 	else if (key == )
// 		return (1);
// 	else if (key == )
// 		return (1);
// 	else if (key == )
// 		return (1);
// 	else if (key == )
// 		return (1);
// 	else if (key == )
// 		return (1);
// 	return (0);
// }

/*
LINUX KEYS
Z = 122
Q = 113
S = 115
D = 100
< = 65361
> = 65363
ESC = 65307
=================
MAC KEYS
W = 
A = 
S = 
D = 
< = 
> = 
ESC = 
*/

void deal_key(int key, t_cub *cub)
{
	if (key == ESC)
	{
		mlx_destroy_window(cub->mlx, cub->win_main);
		// mlx_destroy_window(cub->mlx, cub->win_data);
		free (cub->mlx);
		exit(0);
	}
	if (key == W || key == A || key == S || key == D)
		move(cub, key);
	else if (key == KEY_LEFT || key == KEY_RIGHT)
		rotate(cub, key);
}

void	click(int button, int x, int y, t_cub *cub)
{
	if (button == 1)
		dda_ray0(cub, x, y);
}

int	main(int ac, char **av)
{
	t_cub	cub;

	init(&cub, ac, av);
	parse(&cub, av[1]);
	// printf("x : %d | y : %d | pixel_x : %d | pixel_y : %d | angle : %d\n", cub.plr.x, cub.plr.y, cub.plr.real_x, cub.plr.real_y, cub.angle);
	create_window_main(&cub);
	create_window_data(&cub);
	//ft_puttab(cub.map.map);
	// ft_draw(&cub);
	mlx_hook(cub.win_main, 17, 0, (void *)ft_close, &cub);
	mlx_key_hook(cub.win_main, (void *)deal_key, &cub);
	mlx_mouse_hook(cub.win_main, (void *)click, &cub);
	mlx_loop(cub.mlx);
	// free_all(&cub);
	// return (0);
}
