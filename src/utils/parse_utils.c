/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 22:12:47 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/13 12:32:48 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	texture_done(t_cub *cub)
{
	if (!cub->txtr.c)
		return (0);
	else if (!cub->txtr.ea)
		return (0);
	else if (!cub->txtr.f)
		return (0);
	else if (!cub->txtr.no)
		return (0);
	else if (!cub->txtr.so)
		return (0);
	else if (!cub->txtr.we)
		return (0);
	return (1);
}

void	add_texture(t_cub *cub, char **texture)
{
	if (!ft_strcmp(texture[0], "NO"))
		cub->txtr.no = ft_strdup(texture[1]);
	else if (!ft_strcmp(texture[0], "SO"))
		cub->txtr.so = ft_strdup(texture[1]);
	else if (!ft_strcmp(texture[0], "WE"))
		cub->txtr.we = ft_strdup(texture[1]);
	else if (!ft_strcmp(texture[0], "EA"))
		cub->txtr.ea = ft_strdup(texture[1]);
	else if (!ft_strcmp(texture[0], "F"))
		cub->txtr.f = ft_strdup(texture[1]);
	else if (!ft_strcmp(texture[0], "C"))
		cub->txtr.c = ft_strdup(texture[1]);
}

int	is_texture(t_cub *cub, char *s)
{
	if (!ft_strcmp(s, "NO") && !cub->txtr.no)
		return (1);
	else if (!ft_strcmp(s, "SO") && !cub->txtr.so)
		return (1);
	else if (!ft_strcmp(s, "WE") && !cub->txtr.we)
		return (1);
	else if (!ft_strcmp(s, "EA") && !cub->txtr.ea)
		return (1);
	else if (!ft_strcmp(s, "F") && !cub->txtr.f)
		return (1);
	else if (!ft_strcmp(s, "C") && !cub->txtr.c)
		return (1);
	return (0);
}

int	parse_texture (t_cub *cub, t_lst *lst)
{
	t_lst	*tmp;
	char	**split;

	tmp = lst;
	while (!texture_done(cub) && tmp)
	{
		if (!ft_strcmp(tmp->content, "\n"))
		{
			tmp = tmp->next;
			continue ;
		}
		split = ft_split_charset(tmp->content, " \n");
		if (ft_tablen(split) != 2 || !is_texture(cub, split[0]))
		{
			free_tab(split, ft_tablen(split));
			return (0);
		}
		add_texture(cub, split);
		free_tab(split, ft_tablen(split));
		tmp = tmp->next;
	}
	if (!texture_done(cub))
		return (0);
	return (1);
}