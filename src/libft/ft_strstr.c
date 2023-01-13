/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:40:40 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/13 16:27:10 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

char	*ft_strstr(char *big, char *little)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*little)
		return (big);
	while (big[i])
	{
		j = 0;
		while (big[i + j] == little[j])
		{
			if (!little[j])
				return (&big[i]);
			j++;
		}
		if (!little[j])
			return (&big[i]);
		i++;
	}
	return (NULL);
}
