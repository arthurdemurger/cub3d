/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstindex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 22:05:09 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/12 22:05:38 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

int	ft_lstindex(t_lst **l_lst, t_lst *lst)
{
	t_lst	*tmp;
	int		i;

	tmp = *l_lst;
	i = 0;
	while (tmp)
	{
		if (!ft_strcmp(tmp->content, lst->content))
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (-1);
}
