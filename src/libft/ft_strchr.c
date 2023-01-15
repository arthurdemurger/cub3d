/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:33:04 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/15 17:41:48 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

char	*ft_strchr(char *s, char c)
{
	int	i;

	i = -1;
	if (!c)
		return (NULL);
	while (s[++i])
		if (s[i] == c)
			return (&s[i]);
	if (s[i] == c)
		return (&s[i]);
	return (NULL);
}
