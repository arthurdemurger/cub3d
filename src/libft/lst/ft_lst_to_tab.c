/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_to_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:14:37 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/13 16:16:41 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

char	**ft_lst_to_tab(t_lst *lst)
{
	int		i;
	int		size;
	char	**tab;

	size = ft_lstsize(lst);
	tab = malloc(sizeof(char *) * (size + 1));
	if (!tab)
		return (NULL);
	i = -1;
	while (++i < size)
	{
		tab[i] = ft_strdup(lst->content);
		lst = lst->next;
	}
	tab[i] = NULL;
	return (tab);
}
