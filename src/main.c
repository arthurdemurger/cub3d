/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:29:17 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/15 22:04:12 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init_hero(t_cub *cub)
{
	t_vector	*hero;

	hero = malloc (sizeof(t_vector) * 1);
	if (!hero)
		ft_error("Problem with malloc");
	hero->x = 300;
	hero->y = 200;
	cub->hero = hero;
}

void	get_dir(t_cub *cub)
{
	cub->dir = malloc (sizeof(t_vector) * 1);
	if (!cub->dir)
		ft_error("Problem with malloc");
	if (cub->look == 0)
	{
		cub->dir->x = cub->hero->x;
		cub->dir->y = cub->hero->y - cub->ray0;
	}
	else if (cub->look == 1)
	{
		cub->dir->x = cub->hero->x + cub->ray0;
		cub->dir->y = cub->hero->y;
	}
	else if (cub->look == 2)
	{
		cub->dir->x = cub->hero->x;
		cub->dir->y = cub->hero->y + cub->ray0;
	}
	else if (cub->look == 3)
	{
		cub->dir->x = cub->hero->x - cub->ray0;
		cub->dir->y = cub->hero->y;
	}
}

void	get_plane(t_cub *cub, int i)
{
	cub->plane = malloc (sizeof(t_vector) * 1);
	if (!cub->plane)
		ft_error("Problem with malloc");
	if (cub->look == 0)
	{
		cub->plane->x = cub->dir->x + (210 * i);
		cub->plane->y = cub->dir->y;
	}
	else if (cub->look == 1)
	{
		cub->plane->x = cub->dir->x;
		cub->plane->y = cub->dir->y + (210 * i);
	}
	else if (cub->look == 2)
	{
		cub->plane->x = cub->dir->x - (210 * i);
		cub->plane->y = cub->dir->y;
	}
	else if (cub->look == 3)
	{
		cub->plane->x = cub->dir->x;
		cub->plane->y = cub->dir->y - (210 * i);
	}
}

void	init(t_cub *cub, int ac, char **av)
{
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
	free_all(cub);
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

void	deal_key(int key, t_cub *cub)
{
	(void)cub;
	if (key == 65307)
		ft_close(0, cub);
	else if (is_input_linux(key))
		printf("Valid key\n");
		// ft_move(key, cub);
}

int	main(int ac, char **av)
{
	t_cub	cub;

	test(&cub);
	// if (ac != 2)
	// 	ft_error("Wrong number of arguments.");
	// else if (!check_extension(av[1]))
	// 	ft_error("Wrong file extension.");
	// init(&cub, ac, av);
	// parse(&cub, av[1]);
	// cub.mlx_ptr = mlx_init();
	// cub.win_ptr = mlx_new_window(cub.mlx_ptr, 320, 200, "Cub3D");
	// // ft_draw(&cub);
	// mlx_hook(cub.win_ptr, 17, 0, (void *)ft_close, &cub);
	// mlx_key_hook(cub.win_ptr, (void *)deal_key, &cub);
	// mlx_loop(cub.mlx_ptr);
	// // free_all(&cub);
	// return (0);
}
