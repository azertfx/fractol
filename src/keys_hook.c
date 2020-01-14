/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anabaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 03:04:50 by anabaoui          #+#    #+#             */
/*   Updated: 2020/01/13 16:59:19 by anabaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
void	clear_and_draw(t_var *v)
{
	printf("sssss\n");
	mlx_destroy_image(v->mlx_ptr, v->img_ptr);
	v->img_ptr = mlx_new_image(v->mlx_ptr, IMG_W, IMG_H);
	mlx_clear_window(v->mlx_ptr, v->win_ptr);
	go_draw(*v);
	mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->img_ptr, 0, 0);
}

void	zoom(t_var *v, int x, int y, float z)
{
	v->coor.y = (y * (v->max.y - v->min.y) / IMG_H) + v->min.y;
	v->coor.x = (x * (v->max.x - v->min.x) / IMG_W) + v->min.x;
	v->min.x = v->coor.x + (v->min.x - v->coor.x) * z;
	v->min.y = v->coor.y + (v->min.y - v->coor.y) * z;
	v->max.x = v->coor.x + (v->max.x - v->coor.x) * z;
	v->max.y = v->coor.y + (v->max.y - v->coor.y) * z;
}

int		mouse_move(int x, int y, t_var *v)
{
	if (ft_strcmp(v->fractol, "julia") == 0 && v->stop_julia == 1)
	{
		v->julia.x = (y * (v->max.y - v->min.y) / IMG_H) + v->min.y;
		v->julia.y = (x * (v->max.x - v->min.x) / IMG_W) + v->min.x;
		clear_and_draw(v);
	}
	return (0);
}

int		mouse_hook(int m, int x, int y, t_var *v)
{
	if (m == 1)
		v->stop_julia *= -1;
	if (m == 4)
		zoom(v, x, y, 0.9);
	if (m == 5)
		zoom(v, x, y, 1 / 0.9);
	clear_and_draw(v);
	return (0);
}

int		keys_hook(int k, t_var *v)
{
	if (k == 53)
		exit(0);
	else if (k == 124)
		v->move.x -= 10;
	else if (k == 123)
		v->move.x += 10;
	else if (k == 126)
		v->move.y += 10;
	else if (k == 125)
		v->move.y -= 10;
	else if (k == 69)
		v->itr = (v->itr < 80) ? (v->itr + 1) : v->itr;
	else if (k == 78)
		v->itr = (v->itr > 1) ? (v->itr - 1) : 1;
	else if (k == 8)
		v->color += 0.5;
	else if (k == 34)
		initialization(v);
	clear_and_draw(v);
	return (0);
}
