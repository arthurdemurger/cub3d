/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:23:26 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/20 15:57:36 by gponcele         ###   ########.fr       */
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