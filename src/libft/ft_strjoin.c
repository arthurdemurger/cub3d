/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:23:26 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/23 10:30:52 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t		i;
	size_t		j;
	char		*result;

	if (!s1 || !s2)
		return (0);
	i = 0;
	j = 0;
	result = malloc (sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!result)
		ft_error(MALLOC_ERR);
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		result[i] = s2[j];
		i++;
		j++;
	}
	result[i] = '\0';
	free ((void *) s1);
	return (result);
}