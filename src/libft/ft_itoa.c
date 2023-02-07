/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:23:26 by ademurge          #+#    #+#             */
/*   Updated: 2023/02/07 11:41:57 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static int	ft_size_to_malloc(int n)
{
	int		count;
	long	ln;

	ln = n;
	count = 0;
	if (ln < 0)
	{
		ln = -ln;
		count++;
	}
	else if (!ln)
		return (1);
	while (ln)
	{
		ln /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	ln;
	int		i;

	str = (char *)malloc(sizeof(char) * (ft_size_to_malloc(n) + 1));
	if (!str)
		return (NULL);
	i = ft_size_to_malloc(n);
	str[i] = 0;
	ln = n;
	if (ln < 0)
	{
		str[0] = '-';
		ln = -ln;
	}
	else if (!ln)
		str[0] = '0';
	while (ln)
	{
		str[--i] = (ln % 10) + 48;
		ln /= 10;
	}
	return (str);
}
