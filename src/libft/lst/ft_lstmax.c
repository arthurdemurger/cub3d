/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 22:10:43 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/20 13:08:56 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

t_lst	*ft_lstmax(t_lst *lst)
{
	t_lst	*max;
	t_lst	*tmp;
	int		max_len;

	max = lst;
	tmp = lst;
	max_len = ft_strlen(max->content);
	while (tmp)
	{
		if (max_len < ft_strlen(tmp->content))
		{
			max = tmp;
			max_len = ft_strlen(max->content);
		}
		tmp = tmp->next;
	}
	return (max);
}
