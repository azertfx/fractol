/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anabaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 03:04:50 by anabaoui          #+#    #+#             */
/*   Updated: 2020/01/20 18:49:12 by anabaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_clear_and_draw(t_var *v)
{
	mlx_destroy_image(v->mlx_ptr, v->img_ptr);
	v->img_ptr = mlx_new_image(v->mlx_ptr, IMG_W, IMG_H);
	mlx_clear_window(v->mlx_ptr, v->win_ptr);
	ft_instruction(v);
	ft_go_draw(*v);
	mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->img_ptr, 210, 0);
}

void	ft_zoom(t_var *v, int x, int y, float z)
{
	v->coor.y = ((y + v->move.y) * (v->max.y - v->min.y) / IMG_H) + v->min.y;
	v->coor.x = ((x + v->move.x - 210) * (v->max.x - v->min.x) / IMG_W)
		+ v->min.x;
	v->min.x = v->coor.x + (v->min.x - v->coor.x) * z;
	v->min.y = v->coor.y + (v->min.y - v->coor.y) * z;
	v->max.x = v->coor.x + (v->max.x - v->coor.x) * z;
	v->max.y = v->coor.y + (v->max.y - v->coor.y) * z;
}

void	ft_fractal_keys(int k, t_var *v)
{
	if (k == 46)
		v->fractol = "mandelbrot";
	else if (k == 38)
		v->fractol = "julia";
	else if (k == 1)
		v->fractol = "ship";
	else if (k == 12)
		v->fractol = "quatro";
	else if (k == 35)
		v->fractol = "penta";
	ft_initialization(v);
}

int		ft_keys_hook(int k, t_var *v)
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
		v->itr = (v->itr < 150) ? (v->itr + 1) : v->itr;
	else if (k == 78)
		v->itr = (v->itr > 1) ? (v->itr - 1) : 1;
	else if (k == 8)
		v->color = (v->color > 100) ? 0.5 : v->color + 0.5;
	else if (k == 34)
		ft_initialization(v);
	else if (k == 46 || k == 38 || k == 1
			|| k == 12 || k == 35)
		ft_fractal_keys(k, v);
	ft_clear_and_draw(v);
	return (0);
}
