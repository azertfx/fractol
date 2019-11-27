/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anabaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 02:10:11 by anabaoui          #+#    #+#             */
/*   Updated: 2019/11/27 04:11:04 by anabaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../libft/libft.h"
# include "../miniLibX/mlx.h"

# define IMG_W 800
# define IMG_H 800

typedef struct	s_axes
{
	int		i;
	int		j;
}				t_axes;

typedef struct	s_coor
{
	float	x;
	float	y;
}				t_coor;

typedef struct	s_var
{
	t_coor	mov;
	t_axes	axes;
	t_coor	coor;
	int		itr;
	float	dim;
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
void	go_draw(t_var v, char *str);

#endif
