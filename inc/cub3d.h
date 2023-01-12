/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:31:20 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/12 18:09:01 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CUB3D_H

# define CUB3D_H

/*
** Libraries
*/

# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

/*
** Define constants
*/

/* Debug */
# define ICI printf("ici\n");

/*
** Structures
*/

typedef struct s_lst
{
	char			*content;
	struct s_lst	*next;
	struct s_lst	*prev;
}	t_lst;

typedef struct s_text
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
}	t_text;

typedef struct s_cub
{
	char	**map;
	t_text	textures;
}	t_cub;


/*
** Functions
*/

/* Main */
void			parse(int ac, char **av);

/* Free */
void			free_tab(char **tab);

/* Error management */
void			ft_error(char *s);

/* Libft */
void			ft_putendl_fd(char *s, int fd);
char			*ft_strchr(char *s, char c);
int				ft_strcmp(char *s1, char *s2);
char			*ft_strdup(char *str);
int				ft_strlen(char *s);
char			*ft_strstr(char *big, char *little);
void			ft_lstadd_back(t_lst **lst, t_lst *new);
t_lst			*ft_lstlast(t_lst *lst);
t_lst			*ft_lstnew(char *content);

/* GNL */
char			*get_next_line(int fd);

#endif