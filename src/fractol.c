/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anabaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 02:08:52 by anabaoui          #+#    #+#             */
/*   Updated: 2020/01/10 16:33:12 by anabaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
int		check_iteration(int itr, float x, float y)
{
	int		i;
	float	real_nbr;
	float	img_nbr;
	float	old_real_nbr;

	real_nbr = x;
	img_nbr = y;
	i = 1;
	while ((i < itr) && ((real_nbr * real_nbr + img_nbr * img_nbr) <= 4))
	{
		old_real_nbr = real_nbr;
		real_nbr = (real_nbr * real_nbr) - (img_nbr * img_nbr) + x;
		img_nbr = (2 * old_real_nbr * img_nbr) + y;
		i++;
	}
	return (i);
}

void	go_draw(t_var v)
{
	int		res;
	int 	i;
	int		j;

	printf("str = %s\n", v.fractol);
	if (ft_strcmp(v.fractol, "mandelbrot") == 0)
	{	
	j = 0;
	while (j < IMG_H)
	{
		v.coor.y = v.max.y - (j * (v.max.y - v.min.y) / IMG_H);
		i = 0;
		while (i < IMG_W)
		{
			v.coor.x = (i * (v.max.x - v.min.x) / IMG_W) - v.max.x;
			res = check_iteration(v.itr, v.coor.x, v.coor.y);
			v.img_data[(j * IMG_W) + i] = (res != v.itr) ? (res * 0x03d3fc) : 0x000000;
			i++;
		}
		j++;
	}
	}
	else if (ft_strcmp(v.fractol, "julia") == 0)
	{
		printf("julia is here\n");
	}
}

void	initialization(t_var *v)
{
	v->mov.x = 0;
	v->mov.y = 0;
	v->itr = 70;
	v->min.x = -2;
	v->min.y = -2;
	v->max.x = 2;
	v->max.y = 2;
}

void	fractol(char *str)
{
	t_var v;

	v.mlx_ptr = mlx_init();
	v.win_ptr = mlx_new_window(v.mlx_ptr, IMG_W, IMG_H, "1337 FRACTOL");
	v.img_ptr = mlx_new_image(v.mlx_ptr, IMG_W, IMG_H);
	v.img_data = (int *)mlx_get_data_addr(v.img_ptr, &v.bpp,
			&v.size_l, &v.endian);
	initialization(&v);
	v.fractol = str;
	go_draw(v);
	mlx_hook(v.win_ptr, 2, 1, keys_hook, &v);
	mlx_mouse_hook(v.win_ptr, mouse_hook, &v);
	mlx_put_image_to_window(v.mlx_ptr, v.win_ptr, v.img_ptr, 0, 0);
	mlx_loop(v.mlx_ptr);
}
