/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anabaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 03:04:50 by anabaoui          #+#    #+#             */
/*   Updated: 2020/01/10 16:22:23 by anabaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
void	clear_and_draw(t_var *v)
{
	mlx_destroy_image(v->mlx_ptr, v->img_ptr);
	v->img_ptr = mlx_new_image(v->mlx_ptr, IMG_W, IMG_H);
	mlx_clear_window(v->mlx_ptr, v->win_ptr);
	go_draw(*v, "bla bla");
	mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->img_ptr, 0, 0);
}

void	zoom(t_var *v, int x, int y, float z)
{
	v->coor.x = x / (IMG_W / (v->max.x - v->min.x)) + v->min.x;
	v->coor.y = y / (IMG_H / (v->max.y - v->min.y)) + v->min.y;
	v->min.x = v->coor.x + (v->min.x - v->coor.x) * z;
	v->min.y = v->coor.y + (v->min.y - v->coor.y) * z;
	v->max.x = v->coor.x + (v->max.x - v->coor.x) * z;
	v->max.y = v->coor.y + (v->max.y - v->coor.y) * z;
	printf("xxxxxxx = %f\n", v->coor.x);
}

int		mouse_hook(int m, int x, int y, t_var *v)
{
	if (v)
	{
		printf("m = %i\n", m);
		printf("x = %i\n", x);
		printf("y = %i\n", y);
	}
	if (m == 1)
		printf("left click\n");
	if (m == 2)
		printf("right click\n");
	if (m == 4)
	{
		printf("scroll down\n");
		zoom(v, x, y, 0.9);
		//v->min.x += 0.2;
		//v->min.y += 0.2;
		//v->max.x -= 0.2;
		//v->max.y -= 0.2;
	}
	if (m == 5)
	{
		printf("scroll up\n");
		v->min.x -= 0.2;
		v->min.y -= 0.2;
		v->max.x += 0.2;
		v->max.y += 0.2;
	}
	clear_and_draw(v);
	return (0);
}

int		keys_hook(int k, t_var *v)
{
	if (k == 53)
		exit(0);
	else if (k == 124)
		v->mov.x += 10;
	else if (k == 123)
		v->mov.x -= 10;
	else if (k == 126)
		v->mov.y += 10;
	else if (k == 125)
		v->mov.y -= 10;
	clear_and_draw(v);
	printf("key = %i\n", k);
	return (0);
}
