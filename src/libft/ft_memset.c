/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:10:00 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/20 13:18:30 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	*ft_memset(void *s, int c, size_t n)
{
	void	*tmp;

	tmp = s;
	while (n--)
		*(unsigned char *)(tmp++) = (unsigned char) c;
	return (s);
}
