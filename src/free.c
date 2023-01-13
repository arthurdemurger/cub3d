/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:29:28 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/13 12:06:24 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	*free_tab(char **tab, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		if (tab && tab[i])
			free(tab[i]);
	if (tab)
		free(tab);
	return (NULL);
}
