#include "fractol.h"

void	btn_content(t_var *v)
{
	mlx_string_put(v->mlx_ptr, v->win_ptr, 30, 113, 0x0FFFFF, "+");
	mlx_string_put(v->mlx_ptr, v->win_ptr, 30, 163, 0x0FFFFF, "-");
	mlx_string_put(v->mlx_ptr, v->win_ptr, 60, 113, 0x0FFFFF, "Itr up");
	mlx_string_put(v->mlx_ptr, v->win_ptr, 60, 163, 0x0FFFFF, "Itr down");
	mlx_string_put(v->mlx_ptr, v->win_ptr, 30, 213, 0x0FFFFF, "I");
	mlx_string_put(v->mlx_ptr, v->win_ptr, 30, 263, 0x0FFFFF, ">");
	mlx_string_put(v->mlx_ptr, v->win_ptr, 60, 213, 0x0FFFFF, "Init");
	mlx_string_put(v->mlx_ptr, v->win_ptr, 60, 263, 0x0FFFFF, "Right");
	mlx_string_put(v->mlx_ptr, v->win_ptr, 30, 313, 0x0FFFFF, "<");
	mlx_string_put(v->mlx_ptr, v->win_ptr, 30, 363, 0x0FFFFF, "C");
	mlx_string_put(v->mlx_ptr, v->win_ptr, 60, 313, 0x0FFFFF, "Left");
	mlx_string_put(v->mlx_ptr, v->win_ptr, 60, 363, 0x0FFFFF, "Color");
	mlx_string_put(v->mlx_ptr, v->win_ptr, 30, 413, 0x0FFFFF, "M");
	mlx_string_put(v->mlx_ptr, v->win_ptr, 30, 463, 0x0FFFFF, "J");
	mlx_string_put(v->mlx_ptr, v->win_ptr, 60, 413, 0x0FFFFF, "Mandelbrot");
	mlx_string_put(v->mlx_ptr, v->win_ptr, 60, 463, 0x0FFFFF, "Julia");
	mlx_string_put(v->mlx_ptr, v->win_ptr, 30, 513, 0x0FFFFF, "S");
	mlx_string_put(v->mlx_ptr, v->win_ptr, 60, 513, 0x0FFFFF, "Ship");
	mlx_string_put(v->mlx_ptr, v->win_ptr, 30, 563, 0x0FFFFF, "Q");
	mlx_string_put(v->mlx_ptr, v->win_ptr, 60, 563, 0x0FFFFF, "Quatro");
	mlx_string_put(v->mlx_ptr, v->win_ptr, 30, 613, 0x0FFFFF, "P");
	mlx_string_put(v->mlx_ptr, v->win_ptr, 60, 613, 0x0FFFFF, "Penta");
	mlx_string_put(v->mlx_ptr, v->win_ptr, 30, 663, 0xFF0000, "E");
	mlx_string_put(v->mlx_ptr, v->win_ptr, 60, 663, 0xFF0000, "Exit");
}

void	draw_btn(t_var *v, int x, int y)
{
	int i;

	i = 120 + y;
	while (i < 150 + y)
	{
		mlx_pixel_put(v->mlx_ptr, v->win_ptr, 10 + x, i, 0xFFFFFF);
		mlx_pixel_put(v->mlx_ptr, v->win_ptr, 40 + x, i++, 0xFFFFFF);
	}
	i = 10 + x;
	while (i < 40 + x)
	{
		mlx_pixel_put(v->mlx_ptr, v->win_ptr, i, 120 + y, 0xFFFFFF);
		mlx_pixel_put(v->mlx_ptr, v->win_ptr, i++, 150 + y, 0xFFFFFF);
	}
}
