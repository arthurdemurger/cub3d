#ifndef TEST_H

# define TEST_H

/*
** Libraries
*/

# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "../../files/mlx/mlx.h"

/*
** Define constants
*/

/* Debug */
# define ICI printf("ici\n");
# define LEAKS system("leaks cub3d");

/* Characters */
# define MAP_CHAR "01NSEW \n"
# define POS_CHAR "NSEW"
# define SIZE 32

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
    int     realx;
    int     realy;
}	t_vector;

typedef struct s_square
{
    int     x;
    int     y;
    int     wall;
}   t_square;


typedef struct s_cub
{
	t_map		map;
	void		*mlx;
	void		*win_main;
    void        *win_data;
	t_vector	*plr;
    t_vector    *dir;
    t_square    *square;
	t_text		txtr;
}	t_cub;

void                    create_window_main(t_cub *cub);
void                    deal_key(int key, t_cub *cub);
void                    create_window_data(t_cub *cub);
void                    update_data(t_cub *cub, int line, char *data);
void                    initial_data(t_cub *cub);
char	                *ft_itoa(int n);
static int	            ft_strlen_int(int n);
char	                *ft_strjoin(char const *s1, char const *s2);
size_t	                ft_strlen(const char *s);
void                    set_wall(int button, int x, int y, t_cub *cub);
void                    draw_spot(t_cub *cub, int x, int y);

#endif