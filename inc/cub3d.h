/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:31:20 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/15 22:30:08 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

/*
** Libraries
*/

# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "../files/mlx/mlx.h"

/*
** Define constants
*/

/* Debug */
# define ICI printf("ici\n");
# define LEAKS system("leaks cub3d");

/* Characters */
# define MAP_CHAR "01NSEW \n"
# define POS_CHAR "NSEW"
# define SIZE 64

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
	void	*no;
	void	*so;
	void	*we;
	void	*ea;
	int		*f;
	int		*c;
}	t_text;

typedef struct s_map
{
	char	**map;
}	t_map;

typedef struct s_vector
{
	int		x;
	int		y;
}	t_vector;

typedef struct s_cub
{
	t_map		map;
	void		*mlx;
	void		*win;
	t_vector	*hero;
	t_text		txtr;
}	t_cub;

/*
** Functions
*/

/* Main */
void			ft_draw(t_cub *cub);

/* Tests */
void    		test(t_cub *cub);

/* DDA */
void 			DDA_ray0(t_cub *cub);
void 			DDA_plane(t_cub *cub);

/* Parse */
void			add_texture(t_cub *cub, char **texture);
int				check_extension(char *file);
int				is_map_char(char *s);
int				is_texture(t_cub *cub, char *s);
void			parse(t_cub *cub, char *file);
t_lst			*parse_texture(t_cub *cub, t_lst *lst);
int				texture_done(t_cub *cub);
int				check_map(char **map);

/* Free */
void			*free_tab(char **tab, int len);
void			free_all(t_cub *cub);

/* Error management */
void			ft_error(char *s);

/* Libft */
void			ft_bzero(void *s, int n);
void			ft_putendl_fd(char *s, int fd);
void			ft_putstr(char *s);
void			ft_puttab(char **tab);
char			**ft_split(char const *s, char c);
char			**ft_split_charset(char *str, char *charset);
char			*ft_strchr(char *s, char c);
int				ft_strncmp(const char *s1, const char *s2, int n);
int				ft_strcmp(char *s1, char *s2);
char			*ft_strcpy(char *dest, char *src);
char			*ft_strdup(char *str);
int				ft_strlcpy(char *dest, char *src, int size);
int				ft_strlen(char *s);
char			*ft_strstr(char *big, char *little);
char			*ft_strtrim(char *s1, char *set);
char			*ft_substr(char *s, int start, int len);
int				ft_tablen(char **tab);
/* lst */
void			ft_lstadd_back(t_lst **lst, t_lst *new);
void			ft_lstclear(t_lst *lst);
void			ft_lstdelone(t_lst **l_lst, int i);
t_lst			*ft_lstget(t_lst *lst, int index);
int				ft_lstindex(t_lst **l_lst, t_lst *lst);
t_lst			*ft_lstlast(t_lst *lst);
t_lst			*ft_lstmax(t_lst *lst);
t_lst			*ft_lstnew(char *content);
void			ft_lstput(t_lst *lst);
int				ft_lstsize(t_lst *lst);
char			**ft_lst_to_tab(t_lst *lst);

/* GNL */
char			*get_next_line(int fd);

#endif