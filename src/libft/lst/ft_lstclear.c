/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:34:11 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/13 14:34:47 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

void	ft_lstclear(t_lst *lst)
{
	if (lst->next)
		ft_lstclear(lst->next);
	if (lst->content)
	{
		free (lst->content);
		lst->content = NULL;
	}
	if (lst)
	{
		free (lst);
		lst = NULL;
	}
}
