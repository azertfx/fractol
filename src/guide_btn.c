/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guide_btn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anabaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 19:38:24 by anabaoui          #+#    #+#             */
/*   Updated: 2020/01/17 17:33:23 by anabaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_btn_content(t_var *v)
{
	mlx_string_put(v->mlx_ptr, v->win_ptr, 30, 113, 0xFFFFFF, "+");
	mlx_string_put(v->mlx_ptr, v->win_ptr, 30, 163, 0xFFFFFF, "-");
	mlx_string_put(v->mlx_ptr, v->win_ptr, 60, 113, 0xFFFFFF, "Itr up");
	mlx_string_put(v->mlx_ptr, v->win_ptr, 60, 163, 0xFFFFFF, "Itr down");
	mlx_string_put(v->mlx_ptr, v->win_ptr, 30, 213, 0xFFFFFF, "I");
	mlx_string_put(v->mlx_ptr, v->win_ptr, 30, 263, 0xFFFFFF, ">");
	mlx_string_put(v->mlx_ptr, v->win_ptr, 60, 213, 0xFFFFFF, "Init");
	mlx_string_put(v->mlx_ptr, v->win_ptr, 60, 263, 0xFFFFFF, "Right");
	mlx_string_put(v->mlx_ptr, v->win_ptr, 30, 313, 0xFFFFFF, "<");
	mlx_string_put(v->mlx_ptr, v->win_ptr, 30, 363, 0xFFFFFF, "C");
	mlx_string_put(v->mlx_ptr, v->win_ptr, 60, 313, 0xFFFFFF, "Left");
	mlx_string_put(v->mlx_ptr, v->win_ptr, 60, 363, 0xFFFFFF, "Color");
	mlx_string_put(v->mlx_ptr, v->win_ptr, 30, 413, 0x00EAFF, "M");
	mlx_string_put(v->mlx_ptr, v->win_ptr, 30, 463, 0xFFAA85, "J");
	mlx_string_put(v->mlx_ptr, v->win_ptr, 60, 413, 0x00EAFF, "Mandelbrot");
	mlx_string_put(v->mlx_ptr, v->win_ptr, 60, 463, 0xFFAA85, "Julia");
	mlx_string_put(v->mlx_ptr, v->win_ptr, 30, 513, 0xFFC600, "S");
	mlx_string_put(v->mlx_ptr, v->win_ptr, 60, 513, 0xFFC600, "Ship");
	mlx_string_put(v->mlx_ptr, v->win_ptr, 30, 563, 0x69FF97, "Q");
	mlx_string_put(v->mlx_ptr, v->win_ptr, 60, 563, 0x69FF97, "Quatro");
	mlx_string_put(v->mlx_ptr, v->win_ptr, 30, 613, 0xFF96F9, "P");
	mlx_string_put(v->mlx_ptr, v->win_ptr, 60, 613, 0xFF96F9, "Penta");
	mlx_string_put(v->mlx_ptr, v->win_ptr, 30, 663, 0xFF0000, "E");
	mlx_string_put(v->mlx_ptr, v->win_ptr, 60, 663, 0xFF0000, "Exit");
}

void	ft_draw_btn(t_var *v, int x, int y)
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
