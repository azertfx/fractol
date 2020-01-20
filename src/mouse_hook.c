/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anabaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 13:55:10 by anabaoui          #+#    #+#             */
/*   Updated: 2020/01/17 17:40:27 by anabaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_mouse_move(int x, int y, t_var *v)
{
	if (ft_strcmp(v->fractol, "julia") == 0 && v->stop_julia == 1)
	{
		v->julia.x = (y * (v->max.y - v->min.y) / IMG_H) + v->min.y;
		v->julia.y = (x * (v->max.x - v->min.x) / IMG_W) + v->min.x;
		ft_clear_and_draw(v);
	}
	return (0);
}

int		ft_mouse_hook(int m, int x, int y, t_var *v)
{
	if (m == 1)
		v->stop_julia *= -1;
	if (m == 4)
		ft_zoom(v, x, y, 0.9);
	if (m == 5)
		ft_zoom(v, x, y, 1 / 0.9);
	ft_clear_and_draw(v);
	return (0);
}
