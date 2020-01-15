/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   penta.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anabaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 18:03:30 by anabaoui          #+#    #+#             */
/*   Updated: 2020/01/13 18:06:56 by anabaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		penta_itr(t_var v)
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
		real_nbr = nbrpower(real_nbr, 6) - nbrpower(img_nbr, 6) + 15 * nbrpower(real_nbr, 2) * nbrpower(img_nbr, 4) - nbrpower(img_nbr, 2) * nbrpower(real_nbr, 4) - 14 * nbrpower(real_nbr, 4) * nbrpower(img_nbr, 2) + v.coor.x;
		img_nbr = 6 * nbrpower(old_real_nbr, 5) * img_nbr - 20 * nbrpower(old_real_nbr, 3) * nbrpower(img_nbr, 3) + 6 * old_real_nbr * nbrpower(img_nbr, 5) + v.coor.y;
		i++;
	}
	return (i);
}

void    *penta(void *v)
{
	int 	itr;
	int 	i;
	int 	j;
	t_var	*t;

	t = (void *)v;
	j = t->t_start;
	while (j < t->t_end)
	{
		t->coor.y = ((j + t->move.y) * (t->max.y - t->min.y) / IMG_H) + t->min.y;
		i = 0;
		while (i < IMG_W)
		{
			t->coor.x = ((i + t->move.x) * (t->max.x - t->min.x) / IMG_W) + t->min.x;
			itr = penta_itr(*t);
			t->img_data[(j * IMG_W) + i] = (itr != t->itr) ? (itr * 0x03d3fc * t->color) : 0x000000;
			i++;
		}
		j++;
	}
	return NULL;
}
