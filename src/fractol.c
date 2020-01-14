/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anabaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 02:08:52 by anabaoui          #+#    #+#             */
/*   Updated: 2020/01/13 18:08:27 by anabaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
void	go_draw(t_var v)
{
	t_var		t[THREADS];
	pthread_t	id[THREADS];
	int		i;

	i = 0;
	v.t_start = 0;
	v.t_end = 0;
	while (i < THREADS)
	{
		t[i] = v;
		t[i].t_start = v.t_start;
		t[i].t_end = IMG_H / THREADS + v.t_start;
		//if (ft_strcmp(v.fractol, "mandelbrot") == 0)
		//	pthread_create(&id[i], NULL, mandelbrot(v), t[i]);
		//else if (ft_strcmp(v.fractol, "julia") == 0)
		//	pthread_create(&id[i], NULL, julia(v), t[i]);
		//else if (ft_strcmp(v.fractol, "ship") == 0)
		//	pthread_create(&id[i], NULL, ship(v), t[i]);
		if (ft_strcmp(v.fractol, "quatro") == 0)
			pthread_create(&id[i], NULL, quatro, (void *)&t[i]);
		//else
		//	pthread_create(&id[i], NULL, penta(v), t[i]);
		v.t_start = t[i].t_end;
		i++;
	}
	i = 0;
	while (i < THREADS)
	{
		pthread_join(id[i], NULL);
		i++;
	}
}

void	initialization(t_var *v)
{
	v->move.x = 0;
	v->move.y = 0;
	v->itr = 40;
	v->min.x = -2;
	v->min.y = -2;
	v->max.x = 2;
	v->max.y = 2;
	v->julia.x = -0.8;
	v->julia.y = 0.156;
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
