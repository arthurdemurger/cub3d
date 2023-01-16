/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_to_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:14:01 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/16 15:14:26 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

char	**ft_lst_to_map(t_cub *cub, t_lst *lst)
{
	int		i;
	t_lst	*tmp;
	char	**map;

	tmp = lst;
	cub->map.height = ft_lstsize(lst);
	cub->map.width = ft_strlen(ft_lstmax(lst)->content);
	map = malloc(sizeof(char *) * (cub->map.height + 1));
	if (!map)
		return (NULL);
	i = -1;
	while (++i < cub->map.height)
	{
		map[i] = malloc(sizeof(char) * (cub->map.width + 1));
		if (!map[i])
			return (free_tab(map, ft_tablen(map)));
		ft_bzero(map[i], cub->map.width);
		ft_strcpy(map[i], tmp->content);
		tmp = tmp->next;
	}
	map[i] = NULL;
	return (map);
}
