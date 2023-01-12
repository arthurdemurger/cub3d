/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:31:20 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/12 22:38:07 by ademurge         ###   ########.fr       */
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
	t_text	txtr;
}	t_cub;


/*
** Functions
*/

/* Main */

/* Parse */
void			parse(t_cub *cub, char *file);
void			parse_texture (t_cub *cub, t_lst *lst);

/* Free */
void			free_tab(char **tab);

/* Error management */
void			ft_error(char *s);

/* Libft */
void			ft_putendl_fd(char *s, int fd);
char			*ft_strchr(char *s, char c);
int				ft_strncmp(const char *s1, const char *s2, int n);
int				ft_strcmp(char *s1, char *s2);
char			*ft_strdup(char *str);
int				ft_strlcpy(char *dest, char *src, int size);
int				ft_strlen(char *s);
char			*ft_strstr(char *big, char *little);
char			*ft_strtrim(char *s1, char *set);
char			*ft_substr(char *s, int start, int len);
void			ft_lstadd_back(t_lst **lst, t_lst *new);
void			ft_lstdelone(t_lst **l_lst, int i);
t_lst			*ft_lstget(t_lst *lst, int index);
int				ft_lstindex(t_lst **l_lst, t_lst *lst);
t_lst			*ft_lstlast(t_lst *lst);
t_lst			*ft_lstnew(char *content);

/* GNL */
char			*get_next_line(int fd);

#endif