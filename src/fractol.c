/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anabaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 02:08:52 by anabaoui          #+#    #+#             */
/*   Updated: 2020/01/11 22:38:49 by anabaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
int		check_iteration(t_var v)
{
	int		i;
	float	real_nbr;
	float	img_nbr;
	float	old_real_nbr;

	real_nbr = v.coor.x;
	img_nbr = v.coor.y;
	i = 1;
	if (ft_strcmp(v.fractol, "mandelbrot") == 0 || ft_strcmp(v.fractol, "ship") == 0)
	{
		v.jom.x = v.coor.x;
		v.jom.y = v.coor.y;
	}
	while ((i < v.itr) && ((real_nbr * real_nbr + img_nbr * img_nbr) <= 4))
	{
		old_real_nbr = real_nbr;
		real_nbr = (real_nbr * real_nbr) - (img_nbr * img_nbr) + v.jom.x;
		if (ft_strcmp(v.fractol,"ship") == 0)
			img_nbr = nbrtoabs(2 * old_real_nbr * img_nbr) + v.jom.y;
		else
			img_nbr = 2 * old_real_nbr * img_nbr + v.jom.y;
		i++;
	}
	return (i);
}

void	go_draw(t_var v)
{
	int		res;
	int 	i;
	int		j;

	j = 0;
	while (j < IMG_H)
	{
		v.coor.y = ((j + v.move.y) * (v.max.y - v.min.y) / IMG_H) + v.min.y;
		i = 0;
		while (i < IMG_W)
		{
			v.coor.x = ((i + v.move.x) * (v.max.x - v.min.x) / IMG_W) + v.min.x;
			res = check_iteration(v);
			v.img_data[(j * IMG_W) + i] = (res != v.itr) ? (res * 0x03d3fc * v.color) : 0x000000;
			i++;
		}
		j++;
	}
}

void	initialization(t_var *v)
{
	v->move.x = 0;
	v->move.y = 0;
	v->itr = 60;
	v->min.x = -2;
	v->min.y = -2;
	v->max.x = 2;
	v->max.y = 2;
	v->jom.x = -0.8;
	v->jom.y = 0.156;
	v->stop_julia = 1;
	v->color = 1;
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
	mlx_hook(v.win_ptr, 2, 0, keys_hook, &v);
	mlx_hook(v.win_ptr, 6, 0, mouse_move, &v);
	mlx_mouse_hook(v.win_ptr, mouse_hook, &v);
	mlx_put_image_to_window(v.mlx_ptr, v.win_ptr, v.img_ptr, 0, 0);
	mlx_loop(v.mlx_ptr);
}
