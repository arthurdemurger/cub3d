/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:13:06 by gponcele          #+#    #+#             */
/*   Updated: 2023/01/13 12:33:54 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	check_extension(char *file)
{
	char	*ext;

	if (file[0] == '.')
		return (0);
	ext = ft_strchr(file, '.');
	if (!ext || ft_strcmp(ext, ".cub"))
		return (0);
	return (1);
}

t_lst	*read_file(int fd)
{
	char	*tmp;
	t_lst	*list;
	t_lst	*tmp_lst;

	tmp = get_next_line(fd);
	list = NULL;
	while (tmp)
	{
		if (!list)
			list = ft_lstnew(ft_strdup(tmp));
		else
			ft_lstadd_back(&list, ft_lstnew(ft_strdup(tmp)));
		free(tmp);
		tmp = get_next_line(fd);
	}
	tmp_lst = list;
	while (tmp_lst)
	{
		if (tmp_lst->next)
			tmp_lst->next->prev = tmp_lst;
		tmp_lst = tmp_lst->next;
	}
	return (list);
}

void	parse(t_cub *cub, char *file)
{
	int		fd;
	t_lst	*list;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error("Cannot open the file.");
	list = read_file(fd);
	if (!parse_texture(cub, list))
		ft_error("wrong or missing information for textures");
}
