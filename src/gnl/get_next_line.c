/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:16:19 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/12 17:19:04 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/get_next_line.h"

char	*gnl_free(char *s)
{
	if (s)
		free(s);
	return (NULL);
}

char	*stash_to_line(char *str)
{
	int		size;

	size = 0;
	if (!*str)
		return (NULL);
	while (str[size] && str[size] != '\n')
		size++;
	return (gnl_substr(str, 0, size + 1));
}

char	*clean(char *stash, int n)
{
	char	*str;
	int		i;

	i = -1;
	if (!n)
		return (gnl_free(stash));
	while (stash && stash[++i])
	{
		if (stash[i] == '\n' && stash[i + 1])
		{
			str = ft_strdup(&stash[++i]);
			free(stash);
			return (str);
		}
		else if (stash[i] == '\n')
			return (gnl_free(stash));
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*buf;
	int			n;

	if (BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return(gnl_free(NULL));
	buf = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (gnl_free(buf));
	n = 42;
	while (n && !is_line_break(stash))
	{
		n = read(fd, buf, BUFFER_SIZE);
		buf[n] = 0;
		stash = gnl_strjoin(stash, buf);
		if (!stash)
			return (gnl_free(buf));
	}
	free(buf);
	line = stash_to_line(stash);
	stash = clean(stash, n);
	return (line);
}
