/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:49:15 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/12 21:56:26 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

char	*ft_substr(char *s, int start, int len)
{
	char	*src;
	char	*str;
	int		size;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	size = ft_strlen(&s[start]);
	if (size > len)
		size = len;
	src = s;
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, &src[start], size + 1);
	return (str);
}
