/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:31:20 by ademurge          #+#    #+#             */
/*   Updated: 2023/02/07 12:09:30 by gponcele         ###   ########.fr       */
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
# define LIGHT_RED 0xFF0000
# define DARK_RED 0xB60A0A
# define WHITE 0xFFFFFF
# define LIGHT_GREEN 0x7FFF00
# define DARK_GREEN 0x006400
# define FLOOR 0x2E1F02
# define CEILING 0

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
# define PIX_MOVE 40
# define MAP_DIV 8
# define SIZE 64
# define SIDE 3
# define NB_RAYS 1024
# define MID_RAY 512
# define RADIUS 100
# define ZOOM 0.66
# define WIN_HEIGHT 768
# define WIN_WIDTH 1024
# define LEFT 1
# define RIGHT 0
# define INT_MAX 2147483647

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

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}	t_img;
typedef struct s_text
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	t_img	north;
	int		north_width;
	int		north_height;
	t_img	east;
	int		east_width;
	int		east_height;
	t_img	south;
	int		south_width;
	int		south_height;
	t_img	west;
	int		west_width;
	int		west_height;
	int		f;
	int		c;
}	t_text;

typedef struct s_vector
{
	int			x;
	int			y;
	float		real_x;
	float		real_y;
}	t_vector;

typedef struct s_ray
{
	int			x;
	int			y;
	float		real_x;
	float		real_y;
	float		l;
	float		angle;
	int			dir;
	int			side;
	float		col;
}	t_ray;

typedef struct s_map
{
	char	**map;
	int		w;
	int		h;
}	t_map;

typedef struct s_cub
{
	t_map		map;
	t_vector	plr;
	t_vector	dir;
	t_ray		rays[NB_RAYS];
	t_img		img_map;
	t_img		img_game;
	t_img		img_col;
	t_img		img_col_test;
	int			width_test;
	int			height_test;
	t_text		txtr;
	float		angle;
	float		r;
	float		plane;
	void		*mlx;
	void		*win_main;
	void		*win_data;
	void		*win_game;
	void		*win_test;
}	t_cub;

/*
** Functions
*/

/* Main */
void			my_mlx_pixel_put(t_img *img, int x, int y, int color);

/* Create Window */
void			create_window_main(t_cub *cub);
void			grid(t_cub *cub);
void			fill_squares(t_cub *cub);
void			clean_map(t_cub *cub);

/* Draw */
void			draw(t_cub *cub);
void			draw_cursor(t_cub *cub);

/* Update */
void			update_data(t_cub *cub, int line, char *data);

/* Move */
void			get_move(t_cub *cub, int key);

/* Rotate */
void			rotate(t_cub *cub, int key);

/* DDA */
void			expand_ray(t_cub *cub, t_ray *ray);
float			angle(float a, float b);

/* Corners */
int				north_west(t_vector plr, float *floats, char **map, float angle);
int				north_east(t_vector plr, float *floats, char **map, float angle);
int				south_west(t_vector plr, float *floats, char **map, float angle);
int				south_east(t_vector plr, float *floats, char **map, float angle);

/* Circle */
void			circle(t_cub *cub, int r, int color);
t_ray			intersection(int cx, int cy, float r, float angle);

/* Parse */
void			add_texture(t_cub *cub, char **texture);
int				check_extension(char *file);
int				is_map_char(char *s);
int				is_texture(t_cub *cub, char *s);
void			parse(t_cub *cub, char *file);
t_lst			*parse_texture(t_cub *cub, t_lst *lst);
int				texture_done(t_cub *cub);
int				check_map(t_cub *cub, char **map);

/* Utils */
float			add_angle(float a, float b);
float			min_angle(float a, float b);

/* Free */
void			*free_tab(char **tab, int len);
void			free_all(t_cub *cub);

/* Error management */
void			ft_error(char *s);

/* Libft */
int				ft_atoi(const char *str);
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