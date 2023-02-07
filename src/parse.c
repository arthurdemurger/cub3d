/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:13:06 by gponcele          #+#    #+#             */
/*   Updated: 2023/02/07 15:33:18 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	texture_done(t_cub *cub)
{
	if (cub->txtr.c == -1)
		return (0);
	else if (cub->txtr.c == -1)
		return (0);
	else if (!cub->txtr.ea)
		return (0);
	else if (!cub->txtr.no)
		return (0);
	else if (!cub->txtr.so)
		return (0);
	else if (!cub->txtr.we)
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

t_lst	*parse_texture(t_cub *cub, t_lst *lst)
{
	char	**split;
	t_lst	*tmp;

	tmp = lst;
	while (tmp && !texture_done(cub))
	{
		if (!ft_strcmp(tmp->content, "\n"))
		{
			tmp = tmp->next;
			continue ;
		}
		split = ft_split_charset(tmp->content, " \n");
		if (ft_tablen(split) != 2 || !is_texture(cub, split[0]))
		{
			free_tab(split, ft_tablen(split));
			ft_error(cub, "Wrong or missing information for textures");
		}
		add_texture(cub, split);
		free_tab(split, ft_tablen(split));
		tmp = tmp->next;
	}
	if (!texture_done(cub))
		ft_error(cub, "Wrong or missing information for textures");
	return (tmp);
}

char	**parse_map(t_cub *cub, t_lst *lst)
{
	t_lst	*tmp;
	char	*trim;

	while (lst && !ft_strcmp(lst->content, "\n"))
		lst = lst->next;
	tmp = lst;
	if (!tmp)
		ft_error(cub, "No map input");
	while (tmp)
	{
		if (!is_map_char(tmp->content) || !ft_strcmp(tmp->content, "\n"))
			ft_error(cub, "Wrong map");
		trim = ft_strtrim(tmp->content, "\n");
		free(tmp->content);
		tmp->content = trim;
		tmp = tmp->next;
	}
	return (ft_lst_to_map(cub, lst));
}

void	parse(t_cub *cub, char *file)
{
	int		fd;
	t_lst	*map;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error(cub, "Cannot open the file.");
	cub->map.lst = read_file(fd);
	map = parse_texture(cub, cub->map.lst);
	cub->map.map = parse_map(cub, map);
	check_map(cub, cub->map.map);
	cub->r = SIZE;
	cub->plane = (cub->r * ZOOM) / 2;
}
