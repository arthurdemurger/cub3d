/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:29:28 by ademurge          #+#    #+#             */
/*   Updated: 2023/02/07 16:09:29 by gponcele         ###   ########.fr       */
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

void	destroy_mlx(t_cub *cub)
{
	if (cub->win_game)
		mlx_destroy_window(cub->mlx, cub->win_game);
	if (cub->txtr.north.img)
		mlx_destroy_image(cub->mlx, cub->txtr.north.img);
	if (cub->txtr.east.img)
		mlx_destroy_image(cub->mlx, cub->txtr.east.img);
	if (cub->txtr.south.img)
		mlx_destroy_image(cub->mlx, cub->txtr.south.img);
	if (cub->txtr.west.img)
		mlx_destroy_image(cub->mlx, cub->txtr.west.img);
	if (cub->img_map.img)
		mlx_destroy_image(cub->mlx, cub->img_map.img);
	if (cub->img_col.img)
		mlx_destroy_image(cub->mlx, cub->img_col.img);
	if (cub->torch.img)
		mlx_destroy_image(cub->mlx, cub->torch.img);
	if (cub->sword.img)
		mlx_destroy_image(cub->mlx, cub->sword.img);
	if (cub->hud.img)
		mlx_destroy_image(cub->mlx, cub->hud.img);
	if (cub->mlx)
		free(cub->mlx);
}

void	free_all(t_cub *cub)
{
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
	ft_lstclear(cub->map.lst);
	destroy_mlx(cub);
}
