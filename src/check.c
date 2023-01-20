/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:23:58 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/20 13:04:30 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int	is_good_coord(char c)
{
	if (c == '0' || c == '1' || ft_strchr(POS_CHAR, c))
		return (1);
	return (0);
}

static int	check_coord(char **map, int i, int j)
{
	if (map[i][j] == '0' || ft_strchr(POS_CHAR, map[i][j]))
	{
		if (i == 0 || !map[i + 1] || j == 0 || !map[i][j + 1])
			return (0);
		if (!is_good_coord(map[i - 1][j - 1]))
			return (0);
		if (!is_good_coord(map[i - 1][j]))
			return (0);
		if (!is_good_coord(map[i - 1][j + 1]))
			return (0);
		if (!is_good_coord(map[i][j - 1]))
			return (0);
		if (!is_good_coord(map[i][j + 1]))
			return (0);
		if (!is_good_coord(map[i + 1][j - 1]))
			return (0);
		if (!is_good_coord(map[i + 1][j]))
			return (0);
		if (!is_good_coord(map[i + 1][j + 1]))
			return (0);
	}
	return (1);
}

void	init_plr(t_cub *cub, int x, int y, char cardinal)
{
	int		i;
	char	*dir;

	cub->plr.x = x;
	cub->plr.y = y;
	i = -1;
	dir = POS_CHAR;
	while (dir[++i])
	{
		if (cardinal == dir[i])
			cub->angle = 90 * i;
	}
	cub->plr.real_x = (x * SIZE) + (SIZE / 2);
	cub->plr.real_y = (y * SIZE) + (SIZE / 2);
}

int	check_map(t_cub *cub, char **map)
{
	int	i;
	int	j;
	int	pos;

	i = -1;
	pos = 0;
	while (map[++i] && pos <= 1)
	{
		j = -1;
		while (map[i][++j] && pos <= 1)
		{
			if (ft_strchr(POS_CHAR, map[i][j]))
				init_plr(cub, j, i, map[i][j]);
			if (!check_coord(map, i, j))
				return (0);
			if (ft_strchr(POS_CHAR, map[i][j]))
				pos++;
		}
	}
	if (!pos || pos > 1)
		return (0);
	return (1);
}
