/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:23:58 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/20 12:13:13 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int	is_good_coord(char c)
{
	if (c == '0' || c == '1' || ft_strchr(POS_CHAR, c))
		return (1);
	return (0);
}

static int	check_zero(char **map, int i, int j)
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
	return (1);
}


int	check_map(char **map)
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
			if ((map[i][j] == '0' || ft_strchr(POS_CHAR, map[i][j]))
				&& !check_zero(map, i, j))
				return (0);
			if (map[i][j] == '1' && !check_one(map, i, j))
				return (0);
			if (ft_strchr(POS_CHAR, map[i][j]))
				pos++;
		}
	}
	if (!pos || pos > 1)
		return (0);
	return (1);
}
