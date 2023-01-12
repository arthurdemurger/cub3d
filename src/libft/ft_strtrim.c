/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:47:51 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/12 21:48:24 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static int	is_in_set(char c, char *set)
{
	int	i;

	i = -1;
	while (set[++i])
		if (set[i] == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char *s1, char *set)
{
	int		end;
	int		i;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (is_in_set(*s1, set))
		s1++;
	end = ft_strlen(s1) - 1;
	while (end > 0 && is_in_set(s1[end--], set))
		i++;
	return (ft_substr(s1, 0, ft_strlen(s1) - i));
}
