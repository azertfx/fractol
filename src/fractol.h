/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anabaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 02:10:11 by anabaoui          #+#    #+#             */
/*   Updated: 2020/01/13 18:04:40 by anabaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../libft/libft.h"
# include "mlx.h"

# define IMG_W 600
# define IMG_H 600

typedef struct	s_coor
{
	float	x;
	float	y;
}				t_coor;

typedef struct	s_var
{
	t_coor	move;
	t_coor	coor;
	t_coor	min;
	t_coor	max;
	t_coor	julia;
	float	color;
	int		stop_julia;
	char	*fractol;
	int		itr;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		*img_data;
	int		bpp;
	int		size_l;
	int		endian;
}				t_var;

void	fractol(char *str);
int		keys_hook(int k, t_var *v);
int		mouse_hook(int m, int x, int y, t_var *v);
int		mouse_move(int x, int y, t_var *v);
void	go_draw(t_var v);
void	initialization(t_var *v);
void	mandelbrot(t_var v);
void	julia(t_var v);
void	ship(t_var v);
void	quatro(t_var v);
void	penta(t_var v);

#endif
