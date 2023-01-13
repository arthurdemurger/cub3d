/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_charset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 10:46:39 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/13 12:34:29 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static int	is_charset(char *charset, char c)
{
	int	i;

	i = -1;
	while (charset[++i])
		if (charset[i] == c)
			return (1);
	return (0);
}

static char	*split_strdup(char *src, char *charset)
{
	int		i;
	int		c;
	char	*str;

	i = 0;
	c = 0;
	while (src[c] != '\0')
		c++;
	str = (char *)malloc(sizeof(char) * (c + 1));
	if (!str)
		return (NULL);
	while (src[i] && !is_charset(charset, src[i]))
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static int	count_words(char *str, char *charset)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (str[i])
	{
		while (str[i] && is_charset(charset, str[i]))
			i++;
		if (str[i] && !is_charset(charset, str[i]))
			c++;
		while (str[i] && !is_charset(charset, str[i]))
			i++;
	}
	return (c);
}

static int	ft_index(char *str, char *charset, int index)
{
	int	i;
	int	c;
	int	j;

	j = -1;
	i = 0;
	c = 0;
	while (str[i] && c != index)
	{
		while (str[i] && is_charset(charset, str[i]))
			i++;
		if (str[i] && !is_charset(charset, str[i]))
		{
			c++;
			j = i;
		}
		while (str[i] && !is_charset(charset, str[i]))
			i++;
	}
	return (j);
}

char	**ft_split_charset(char *str, char *charset)
{
	int		i;
	int		size;
	char	**split_str;

	if (!str || !charset)
		return (NULL);
	size = count_words(str, charset);
	split_str = (char **)malloc(sizeof(char *) * (size + 1));
	if (!split_str)
		return (NULL);
	i = -1;
	while (++i < size)
	{
		split_str[i] = split_strdup(&str[ft_index(str, charset, i + 1)],
				charset);
		if (!split_str[i])
			return (free_tab(split_str, ft_tablen(split_str)));
	}
	split_str[i] = 0;
	return (split_str);
}
