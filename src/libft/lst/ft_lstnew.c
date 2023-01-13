/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:45:27 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/13 16:27:26 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

t_lst	*ft_lstnew(char *content)
{
	t_lst	*var;

	var = malloc(sizeof(t_lst));
	if (!var)
		return (NULL);
	var->content = content;
	var->next = NULL;
	var->prev = NULL;
	return (var);
}
