/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 22:12:47 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/12 22:41:56 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	texture_done(t_cub *cub)
{
	if (!cub->txtr.c)
		return (0);
	else if (!cub->txtr.ea)
		return (0);
	else if (!cub->txtr.f)
		return (0);
	else if (!cub->txtr.no)
		return (0);
	else if (!cub->txtr.so)
		return (0);
	else if (!cub->txtr.we)
		return (0);
	return (1);
}

void	add_texture(t_cub *cub, char *texture)
{
	char	**split;

	split = ft_split(texture, )
	if (!ft_strncmp(texture, "NO", 2))

}

void	parse_texture (t_cub *cub, t_lst *lst)
{
	t_lst	*tmp;
	char	*swp;
	t_lst	*next;
	int		i;

	tmp = lst;
	i = 0;
	while (tmp && !texture_done(cub))
	{
		swp = tmp->content;
		next = tmp->next;
		tmp->content = ft_strtrim(tmp->content, " \t");
		if (!ft_strcmp(tmp->content, "\n"))
			ft_lstdelone(&lst, ft_lstindex(&lst, tmp));
		free(swp);
		add_texture(cub, tmp->content);
		tmp = next;
		i++;
	}
}