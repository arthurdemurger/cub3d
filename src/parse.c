/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:13:06 by gponcele          #+#    #+#             */
/*   Updated: 2023/01/13 16:25:00 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

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


t_lst	*parse_texture (t_cub *cub, t_lst *lst)
{
	char	**split;
	t_lst	*tmp;

	tmp = lst;
	while (!texture_done(cub) && tmp)
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
			return (NULL);
		}
		add_texture(cub, split);
		free_tab(split, ft_tablen(split));
		tmp = tmp->next;
	}
	if (!texture_done(cub))
		return (NULL);
	return (tmp);
}

int	check_map(char **map)
{
	(void) map;
	// code
	return (1);
}

char	**parse_map(t_lst *lst)
{
	t_lst	*tmp;
	char	*trim;

	while (lst && !ft_strcmp(lst->content, "\n"))
		lst = lst->next;
	tmp = lst;
	while (tmp)
	{
		if (!is_map_char(tmp->content))
			return (NULL);
		trim = ft_strtrim(tmp->content, "\n");
		free(tmp->content);
		tmp->content = trim;
		tmp = tmp->next;
	}
	return (ft_lst_to_tab(lst));
}

void	parse(t_cub *cub, char *file)
{
	int		fd;
	t_lst	*list;
	t_lst	*map;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error("Cannot open the file.");
	list = read_file(fd);
	map = parse_texture(cub, list);
	if (!map)
		ft_error("Wrong or missing information for textures");
	cub->map = parse_map(map);
	if (!cub->map)
		ft_error("Not a valid map.");
	if (!check_map(cub->map))
		ft_error("The map must be surrounded by walls.");
	ft_lstclear(list);
}