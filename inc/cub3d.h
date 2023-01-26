/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:31:20 by ademurge          #+#    #+#             */
/*   Updated: 2023/01/26 13:32:01 by ademurge         ###   ########.fr       */
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

/* Colors */
# define BLUE 0x0000CD
# define BLACK 0x000000
# define GREEN 0x008000
# define RED 0xFF0000
# define WHITE 0xFFFFFF
# define LIGHT_GREEN 0x7FFF00
# define DARK_GREEN 0x006400
# define FLOOR 0xCAA472

/* Debug */
# define ICI printf("ici\n");
# define LEAKS system("leaks cub3d");

/* Directions */
# define NO 1
# define NE 2
# define SE 3
# define SO 4
# define NORTH 1
# define EAST 2
# define SOUTH 3
# define WEST 4

/* Characters */
# define MAP_CHAR "01NSEW \n"
# define POS_CHAR "ESWN"
# define ROT_ANGLE 10
# define PIX_MOVE 3
# define SIZE 32
# define SIDE 3
# define NB_RAYS 1024
# define MID_RAY 512
# define RADIUS 100
# define ZOOM 0.66
# define WIN_HEIGHT 768
# define WIN_WIDTH 1024

/* Managing errors */
# define MALLOC_ERR "minishell : error in the memory allocation of a malloc."

/* Keyboard*/
# define DESTROY_BUTTON 17
# define ESC 53
# define KEYPRESS 2
# define W 13
# define A 0
# define S 1
# define D 2
# define KEY_UP 126
# define KEY_LEFT 123
# define KEY_DOWN 125
# define KEY_RIGHT 124

/* Keyboard*/
# define DESTROY_BUTTON 17
# define ESC 53
# define KEYPRESS 2
# define W 13
# define A 0
# define S 1
# define D 2
# define KEY_UP 126
# define KEY_LEFT 123
# define KEY_DOWN 125
# define KEY_RIGHT 124

/*
** Structures
*/

typedef struct s_lst
{
	char			*content;
	struct s_lst	*next;
	struct s_lst	*prev;
}	t_lst;

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_text
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
}	t_text;

typedef struct s_vector
{
	int		x;
	int		y;
	int		real_x;
	int		real_y;
}	t_vector;

typedef struct s_ray
{
	int		x;
	int		y;
	int		real_x;
	int		real_y;
	int		face;
	float	l;
	float	angle;
	// int		x1;
	// int		x2;
	// float	xa;
	// int		y1;
	// int		y2;
	// float	ya;
	int		dir;
	// float	l_h;
	// float	l_v;
}	t_ray;

typedef struct s_map
{
	char	**map;
	int		w;
	int		h;
}	t_map;

typedef struct	s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}	t_img;

typedef struct s_cub
{
	t_map		map;
	t_vector	plr;
	t_vector	dir;
	t_ray		rays[NB_RAYS];
	t_img		img_map;
	t_img		img_game;
	float		angle;
	float		r;
	float		plane;
	void		*mlx;
	void		*win_main;
	void		*win_data;
	void		*win_game;
	t_text		txtr;
}	t_cub;

/*
** Functions
*/

/* Main */
void			my_mlx_pixel_put(t_img *data, int x, int y, int color);

/* Create Window */
void			create_window_main(t_cub *cub);
void			draw_square(t_cub *cub, int x, int y, int color);
void			grid(t_cub *cub);
void			fill_squares(t_cub *cub);
void			create_window_data(t_cub *cub);
void			create_window_game(t_cub *cub);
void			clean_map(t_cub *cub);

/* Draw */
void			draw(t_cub *cub);

/* Update */
void			update_data(t_cub *cub, int line, char *data);

/* Move */
void			move(t_cub *cub, int key);

/* Rotate */
void			rotate(t_cub *cub, int key);
void			display_pov(t_cub *cub, int color);

/* DDA */
t_pos 			dda(t_cub *cub, int x, int y, int color, int ray);
float			distance(int x1, int y1, int x2, int y2);
float 			expand_ray(t_cub *cub, float angle, t_ray *ray);
float			angle(float a, float b);

/* Circle */
void			circle(t_cub *cub, int r, int color);
t_ray	 		intersection(t_cub *cub, int cx, int cy, float r, float angle);

/* Parse */
void			add_texture(t_cub *cub, char **texture);
int				check_extension(char *file);
int				is_map_char(char *s);
int				is_texture(t_cub *cub, char *s);
void			parse(t_cub *cub, char *file);
t_lst			*parse_texture(t_cub *cub, t_lst *lst);
int				texture_done(t_cub *cub);
int				check_map(t_cub *cub, char **map);

/* Free */
void			*free_tab(char **tab, int len);
void			free_all(t_cub *cub);

/* Error management */
void			ft_error(char *s);

/* Libft */
void			ft_bzero(void *s, int n);
char			*ft_itoa(int n);
void			*ft_memset(void *s, int c, size_t n);
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
char			*ft_strjoin(char *s1, char *s2);
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
char			**ft_lst_to_map(t_cub *cub, t_lst *lst);
int				ft_lstsize(t_lst *lst);
char			**ft_lst_to_map(t_cub *cub, t_lst *lst);
char			**ft_lst_to_tab(t_lst *lst);

/* GNL */
char			*get_next_line(int fd);

#endif