/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:50:39 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/12 21:51:06 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	ft_strlcpy(char *dest, char *src, int size)
{
	int	i;
	int	c;

	i = -1;
	c = 0;
	while (src[c])
		c++;
	if (size)
	{
		while (src[++i] && i < (size - 1))
			dest[i] = src[i];
		dest[i] = 0;
	}
	return (c);
}
