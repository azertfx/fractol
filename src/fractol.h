/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anabaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 02:10:11 by anabaoui          #+#    #+#             */
/*   Updated: 2020/01/20 18:50:26 by anabaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../libft/libft.h"
# include "../miniLibX/mlx.h"
# include <pthread.h>

# define WIN_W 910
# define IMG_W 700
# define IMG_H 700
# define THREADS 4

typedef struct	s_coor
{
	double	x;
	double	y;
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
	int		t_start;
	int		t_end;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		*img_data;
	int		bpp;
	int		size_l;
	int		endian;
}				t_var;

void			ft_fractol(char *str);
int				ft_keys_hook(int k, t_var *v);
int				ft_mouse_hook(int m, int x, int y, t_var *v);
int				ft_mouse_move(int x, int y, t_var *v);
void			ft_go_draw(t_var v);
void			ft_initialization(t_var *v);
void			*ft_mandelbrot(void *v);
void			*ft_julia(void *v);
void			*ft_ship(void *v);
void			*ft_quatro(void *v);
void			*ft_penta(void *v);
void			ft_right_window(t_var *v);
void			ft_instruction(t_var *v);
void			ft_draw_btn(t_var *v, int x, int y);
void			ft_btn_content(t_var *v);
void			ft_clear_and_draw(t_var *v);
void			ft_zoom(t_var *v, int x, int y, float z);

#endif
