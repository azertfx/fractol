/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quatro.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anabaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 17:35:07 by anabaoui          #+#    #+#             */
/*   Updated: 2020/01/13 17:39:41 by anabaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		quatro_itr(t_var v)
{
	int     i;
	float   real_nbr;
	float   img_nbr;
	float   old_real_nbr;

	real_nbr = v.coor.x;
	img_nbr = v.coor.y;
	i = 1;
	while ((i < v.itr) && ((real_nbr * real_nbr + img_nbr * img_nbr) <= 4))
	{
		old_real_nbr = real_nbr;
		real_nbr = nbrpower(real_nbr, 5) - 10 * nbrpower(real_nbr, 3) * nbrpower(img_nbr, 2) + 5 * real_nbr * nbrpower(img_nbr, 4) + v.coor.x;
		img_nbr = 5 * nbrpower(old_real_nbr, 4) * img_nbr - 10 * nbrpower(old_real_nbr, 2) * nbrpower(img_nbr, 3) + nbrpower(img_nbr, 5) + v.coor.y;
		i++;
	}
	return (i);
}

void    quatro(t_var v)
{
	int itr;
	int i;
	int j;

	j = 0;
	while (j < IMG_H)
	{
		v.coor.y = ((j + v.move.y) * (v.max.y - v.min.y) / IMG_H) + v.min.y;
		i = 0;
		while (i < IMG_W)
		{
			v.coor.x = ((i + v.move.x) * (v.max.x - v.min.x) / IMG_W) + v.min.x;
			itr = quatro_itr(v);
			v.img_data[(j * IMG_W) + i] = (itr != v.itr) ? (itr * 0x03d3fc * v.color) : 0x000000;
			i++;
		}
		j++;
	}
}
