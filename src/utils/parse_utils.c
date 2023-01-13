/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 22:12:47 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/13 16:09:50 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	check_extension(char *file)
{
	char	*ext;

	if (file[0] == '.')
		return (0);
	ext = ft_strchr(file, '.');
	if (!ext || ft_strcmp(ext, ".cub"))
		return (0);
	return (1);
}

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

int	is_map_char(char *s)
{
	int	i;

	i = -1;
	while (s && s[++i])
		if (!ft_strchr(MAP_CHAR, s[i]))
			return (0);
	return (1);
}