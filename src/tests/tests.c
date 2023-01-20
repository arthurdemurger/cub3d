#include "../../inc/test/test.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	size_t		j;
	char		*result;

	if (!s1 || !s2)
		return (0);
	i = 0;
	j = 0;
	result = malloc (sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!result)
		return (NULL);
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		result[i] = s2[j];
		i++;
		j++;
	}
	result[i] = '\0';
	free ((void *) s1);
	return (result);
}

static int	ft_strlen_int(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i = 1;
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		len;
	long	nb;
	char	*str;

	len = ft_strlen_int(n);
	nb = n;
	str = malloc (sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len--] = '\0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		str[0] = '0';
	while (nb > 0)
	{
		str[len] = nb % 10 + '0';
		nb /= 10;
		len--;
	}
	return (str);
}

void    grid(t_cub *cub)
{
    int x;
    int y;

    y = 0;
    while (x < (SIZE * 20) || y < (SIZE * 20))
    {
        x = 0;
        while (x < (SIZE * 20))
        {
            if ((y > 0 && ((x % SIZE) == 0)) || (y % SIZE) == 0)
                mlx_pixel_put(cub->mlx, cub->win_main, x, y, 0x000000);
            x++;
        }
        y++;
    }
}

void create_window_main(t_cub *cub)
{
    int x;
    int y;

    cub->mlx = mlx_init();
    cub->win_main = mlx_new_window(cub->mlx, 20 * SIZE, 20 * SIZE, "Cub3D - Test");
    while (x < (SIZE * 20) || y < (SIZE * 20))
    {
        x = 0;
        while (x < (SIZE * 20))
        {
            mlx_pixel_put(cub->mlx, cub->win_main, x, y, 0xFFFFFF);
            x++;
        }
        y++;
    }
    grid(cub);
}

void    move(t_cub *cub, int key)
{
    int x_copy;
    int y_copy;

    grid(cub);
    y_copy = cub->plr->realy - 5;
    while (x_copy < (cub->plr->realx + 5) || y_copy < (cub->plr->realy + 5))
    {
        x_copy = cub->plr->realx - 5;
        while (x_copy < (cub->plr->realx + 5))
        {
            mlx_pixel_put(cub->mlx, cub->win_main, x_copy, y_copy, 0xFFFFFF);
            x_copy++;
        }
        y_copy++;
    }
    if (key == 122)
        cub->plr->realy -= 3;
    else if (key == 113)
        cub->plr->realx -= 3;
    else if (key == 115)
        cub->plr->realy += 3;
    else if (key == 100)
        cub->plr->realx += 3;
    draw_spot(cub, cub->plr->realx, cub->plr->realy);
}

void deal_key(int key, t_cub *cub)
{
    if (key == 65307)
    {
        mlx_destroy_window(cub->mlx, cub->win_main);
        mlx_destroy_window(cub->mlx, cub->win_data);
        free (cub->mlx);
        free (cub->plr);
        free (cub->dir);
        exit(0);
    }
    if (key == 122 || key == 113 || key == 115 || key == 100)
        move(cub, key);
}

void create_window_data(t_cub *cub)
{
    char    *data;

    data = NULL;
    cub->win_data = mlx_new_window(cub->mlx, 300, 95, "Cub3D - Data");
    mlx_string_put(cub->mlx, cub->win_data, 10, 15, 0xFFFFFF, "Player position :");
    mlx_string_put(cub->mlx, cub->win_data, 10, 40, 0xFFFFFF, "Dir last position :");
    mlx_string_put(cub->mlx, cub->win_data, 10, 65, 0xFFFFFF, "Ray0 length :");
    mlx_string_put(cub->mlx, cub->win_data, 10, 90, 0xFFFFFF, "Wall encountered :");
    data = ft_strjoin(ft_itoa(cub->plr->x), " - ");
    data = ft_strjoin(data, ft_itoa(cub->plr->y));
    update_data(cub, 1, data);
}

void update_data(t_cub *cub, int line, char *data)
{
    int     x;
    int     y;

    if (line == 1)
    {
        y = 15;
        while (x < 250 || y < 20)
        {
            x = 150;
            while (x < 250)
            {
                mlx_pixel_put(cub->mlx, cub->win_data, x, y, 0x000000);
                x++;
            }
            y++;
        }
        mlx_string_put(cub->mlx, cub->win_data, 150, 15, 0xFFFFFF, data);
    }
    else if (line == 2)
    {
        y = 40;
        while (x < 250 || y < 45)
        {
            x = 150;
            while (x < 250)
            {
                mlx_pixel_put(cub->mlx, cub->win_data, x, y, 0x000000);
                x++;
            }
            y++;
        }
        mlx_string_put(cub->mlx, cub->win_data, 150, 40, 0xFFFFFF, data);
    }
    else if (line == 3)
    {
        y = 65;
        while (x < 250 || y < 70)
        {
            x = 150;
            while (x < 250)
            {
                mlx_pixel_put(cub->mlx, cub->win_data, x, y, 0x000000);
                x++;
            }
            y++;
        }
        mlx_string_put(cub->mlx, cub->win_data, 150, 65, 0xFFFFFF, data);
    }
    else if (line == 4)
    {
        y = 90;
        while (x < 250 || y < 95)
        {
            x = 150;
            while (x < 250)
            {
                mlx_pixel_put(cub->mlx, cub->win_data, x, y, 0x000000);
                x++;
            }
            y++;
        }
        mlx_string_put(cub->mlx, cub->win_data, 150, 90, 0xFFFFFF, data);
    }
}

void    draw_spot(t_cub *cub, int x, int y)
{
    int x_copy;
    int y_copy;

    y_copy = y - 5;
    while (x_copy < (x + 5) || y_copy < (y + 5))
    {
        x_copy = x - 5;
        while (x_copy < (x + 5))
        {
            mlx_pixel_put(cub->mlx, cub->win_main, x_copy, y_copy, 0xD72A2A);
            x_copy++;
        }
        y_copy++;
    }
}

void initial_data(t_cub *cub)
{
    cub->plr = malloc(sizeof(t_vector) * 1);
    cub->dir = malloc(sizeof(t_vector) * 1);
    if (!cub->plr || !cub->dir)
    {
        if (cub->plr)
            free(cub->plr);
        exit(0);
    }
    cub->plr->x = 7;
    cub->plr->y = 10;
    cub->plr->realx = (cub->plr->x * SIZE) + 16;
    cub->plr->realy = (cub->plr->y * SIZE) + 16;
    draw_spot(cub, cub->plr->realx, cub->plr->realy);
}

void    set_wall(int button, int x, int y, t_cub *cub)
{
    int x_copy;
    int y_copy;

    while ((x % 32) != 0)
        x--;
    while ((y % 32) != 0)
        y--;
    if (button == 1)
    {
        y_copy = y + 1;
        while (x_copy < (x + 32) || y_copy < (y + 32))
        {
            x_copy = x + 1;
            while ((x_copy) < (x + 32))
            {
                mlx_pixel_put(cub->mlx, cub->win_main, x_copy, y_copy, 0x3345E9);
                x_copy++;
            }
            y_copy++;
        }
    }
}

// void    init_map(t_cub *cub)
// {
//     int i = 0;
//     int x = 0;
//     int y = 0;

//     while (i < 400)
//     {

//     }
// }

int main(void)
{
    t_cub cub;

    // init_map(&cub);
    create_window_main(&cub);
    initial_data(&cub);
    create_window_data(&cub);
    mlx_key_hook(cub.win_main, (void *)deal_key, &cub);
    mlx_mouse_hook(cub.win_main, (void *)set_wall, &cub);
    mlx_loop(cub.mlx);
}