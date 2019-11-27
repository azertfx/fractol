/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anabaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 02:08:52 by anabaoui          #+#    #+#             */
/*   Updated: 2019/11/24 06:53:10 by anabaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int		check_iteration(float x, float y)
{
	int		i;
	float	real_nbr;
	float	img_nbr;
	float	old_real_nbr;

	real_nbr = x;
	img_nbr = y;
	i = 1;
	while ((i < 50) && ((real_nbr * real_nbr + img_nbr * img_nbr) <= 4))
	{
		old_real_nbr = real_nbr;
		real_nbr = (real_nbr * real_nbr) - (img_nbr * img_nbr) + x;
		img_nbr = (2 * old_real_nbr * img_nbr) + y;
		i++;
	}
	return (i);
}

void	go_draw(t_var v, char *str)
{
	int		i;
	int		j;
	int		res;
	float	x;
	float	y;

	printf("str = %s\n", str);
	j = 0;
	while (j < IMG_H)
	{
		y = 2 - ((float)(j * 4) / (float)IMG_H);
		i = 0;
		while (i < IMG_W)
		{
			x = ((float)(i * 4) / (float)IMG_W) - 2;
			res = check_iteration(x, y);
			v.img_data[(j * IMG_W) + i] = (res != 50) ? (res * 0x03d3fc) : 0x000000;
			i++;
		}
		j++;
	}
}

void	fractol(char *str)
{
	t_var v;

	v.mlx_ptr = mlx_init();
	v.win_ptr = mlx_new_window(v.mlx_ptr, IMG_W, IMG_H, "1337 FRACTOL");
	v.img_ptr = mlx_new_image(v.mlx_ptr, IMG_W, IMG_H);
	v.img_data = (int *)mlx_get_data_addr(v.img_ptr, &v.bpp,
			&v.size_l, &v.endian);
	go_draw(v, str);
	mlx_put_image_to_window(v.mlx_ptr, v.win_ptr, v.img_ptr, 0, 0);
	mlx_loop(v.mlx_ptr);
}
