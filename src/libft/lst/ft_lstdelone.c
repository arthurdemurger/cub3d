/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:39:15 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/12 21:39:42 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

void	ft_lstdelone(t_lst **l_lst, int i)
{
	t_lst	*prev;
	t_lst	*lst;
	t_lst	*next;

	lst = ft_lstget(*l_lst, i);
	next = ft_lstget(*l_lst, i + 1);
	prev = ft_lstget(*l_lst, i - 1);
	free(lst->content);
	free(lst);
	if (prev && next)
		prev->next = next;
	else if (prev && !next)
		prev->next = NULL;
	else if (!prev && next)
		lst = next;
	else
		lst = NULL;
	(void) lst;
}