/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstget.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:38:06 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/13 16:27:28 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

t_lst	*ft_lstget(t_lst *lst, int index)
{
	int	i;

	i = 0;
	while (lst && i < index)
	{
		i++;
		lst = lst->next;
	}
	return (lst);
}
