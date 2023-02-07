/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:13:51 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/13 14:32:51 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

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

void	ft_error(char *s)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putendl_fd(s, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
