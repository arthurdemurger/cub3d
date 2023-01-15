/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:23:58 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/15 17:51:50 by ademurge         ###   ########.fr       */
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
