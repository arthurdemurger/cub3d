/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:13:06 by gponcele          #+#    #+#             */
/*   Updated: 2023/01/12 18:47:01 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// static int	parse_texture(char *file)
// {

// 	return (0);
// }

// static int	parse_map(char *file)
// {
// 	return (0);
// }

static int	check_extension(char *file)
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
	return (list);
}

void	parse(int ac, char **av)
{
	int		fd;
	t_lst	*list;

	if (ac != 2)
		ft_error("Wrong number of arguments.");
	else if (!check_extension(av[1]))
		ft_error("Wrong file extension.");
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		ft_error("Cannot open the file.");
	list = read_file(fd);
	// if (parse_texture(av[1]))
	// 	ft_error("Wrong texture input.");
	// else if (parse_map(av[1]))
	// 	ft_error("Wrong map.");
}
