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
# include "../miniLibX/mlx.h"
# include <pthread.h>

# define WIN_W 920
# define IMG_W 700
# define IMG_H 700
# define THREADS 4

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
	int	t_start;
	int	t_end;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int	*img_data;
	int	bpp;
	int	size_l;
	int	endian;
}				t_var;

void	fractol(char *str);
int		keys_hook(int k, t_var *v);
int		mouse_hook(int m, int x, int y, t_var *v);
int		mouse_move(int x, int y, t_var *v);
void	go_draw(t_var v);
void	initialization(t_var *v);
void	*mandelbrot(void *v);
void	*julia(void *v);
void	*ship(void *v);
void	*quatro(void *v);
void	*penta(void *v);
void	right_window(t_var *v);
void	instruction(t_var *v);
void	draw_btn(t_var *v, int x, int y);
void	btn_content(t_var *v);

#endif
