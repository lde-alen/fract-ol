#include "./includes/ft_fractol.h"

int key_print(int key, void *idk)
{
    printf("key: %d\n", key);
    return (0);
}
int main()
{
    int     key;
    void    *mlx;
    void    *win;
    mlx = mlx_init();
    win = mlx_new_window(mlx, 200, 200, "key");
    mlx_key_hook(win, key_print, (void *)0);
    mlx_mouse_hook(win, key_print, (void *)0);
    mlx_loop(mlx);
    return (0);
}
