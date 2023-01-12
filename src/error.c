/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:13:51 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/12 16:57:07 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_error(char *s)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putendl_fd(s, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
