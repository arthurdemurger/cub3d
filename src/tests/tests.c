#include "../../inc/test/test.h"

void    create_window_main(t_cub *cub)
{
    int x;
    int y;

    cub->mlx = mlx_init();
    cub->win_main = mlx_new_window(cub->mlx, 15 * SIZE, 15 * SIZE, "Cub3D - Test");
    while (x < (SIZE * 15) || y < (SIZE * 15))
    {
        x = 0;
        while (x < (SIZE * 15))
        {
            mlx_pixel_put(cub->mlx, cub->win_main, x, y, 0xFFFFFF);
            x++;
        }
        y++;
    }
    y = 0;
    while (x < (SIZE * 15) || y < (SIZE * 15))
    {
        x = 0;
        while (x < (SIZE * 15))
        {
            if ((y > 0 && ((x % SIZE) == 0)) || (y % SIZE) == 0)
                mlx_pixel_put(cub->mlx, cub->win_main, x, y, 0x000000);
            x++;
        }
        y++;
    } 
}

void    deal_key(int key, t_cub *cub)
{
    if (key == 65307)
    {
        mlx_destroy_window(cub->mlx, cub->win_main);
        mlx_destroy_window(cub->mlx, cub->win_data);
        exit (0);
    }
}

void    create_window_data(t_cub *cub)
{
    cub->win_data = mlx_new_window(cub->mlx, 300, 95, "Cub3D - Data");
    mlx_string_put(cub->mlx, cub->win_data, 10, 15, 0xFFFFFF, "Player position :");
    mlx_string_put(cub->mlx, cub->win_data, 10, 40, 0xFFFFFF, "Dir position :");
    mlx_string_put(cub->mlx, cub->win_data, 10, 65, 0xFFFFFF, "Ray0 length :");
    mlx_string_put(cub->mlx, cub->win_data, 10, 90, 0xFFFFFF, "Wall encountered :");
}

int main(void)
{
    t_cub   cub;

    create_window_main(&cub);
    create_window_data(&cub);
    mlx_key_hook(cub.win_main, (void *)deal_key, &cub);
    mlx_loop(cub.mlx);
}