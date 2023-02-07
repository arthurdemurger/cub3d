/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:29:28 by ademurge          #+#    #+#             */
/*   Updated: 2023/02/07 13:31:53 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	*free_tab(char **tab, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		if (tab && tab[i])
			free(tab[i]);
	if (tab)
		free(tab);
	return (NULL);
}

void	free_all(t_cub *cub)
{
	mlx_destroy_window(cub->mlx, cub->win_game);
	mlx_destroy_image(cub->mlx, cub->txtr.north.img);
	mlx_destroy_image(cub->mlx, cub->txtr.east.img);
	mlx_destroy_image(cub->mlx, cub->txtr.south.img);
	mlx_destroy_image(cub->mlx, cub->txtr.west.img);
	mlx_destroy_image(cub->mlx, cub->img_map.img);
	mlx_destroy_image(cub->mlx, cub->img_game.img);
	mlx_destroy_image(cub->mlx, cub->img_col.img);
	free(cub->mlx);
	if (cub->txtr.no)
		free(cub->txtr.no);
	if (cub->txtr.so)
		free(cub->txtr.so);
	if (cub->txtr.we)
		free(cub->txtr.we);
	if (cub->txtr.ea)
		free(cub->txtr.ea);
	if (cub->map.map)
		free_tab(cub->map.map, ft_tablen(cub->map.map));
}
