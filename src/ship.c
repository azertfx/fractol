/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ship.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anabaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 17:27:39 by anabaoui          #+#    #+#             */
/*   Updated: 2020/01/20 18:45:53 by anabaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_ship_itr(t_var v)
{
	int		i;
	double	real_nbr;
	double	img_nbr;
	double	old_real_nbr;

	real_nbr = v.coor.x;
	img_nbr = v.coor.y;
	i = 1;
	while ((i < v.itr) && ((real_nbr * real_nbr + img_nbr * img_nbr) <= 4))
	{
		old_real_nbr = real_nbr;
		real_nbr = (real_nbr * real_nbr) - (img_nbr * img_nbr) + v.coor.x;
		img_nbr = ft_nbrtoabs(2 * old_real_nbr * img_nbr) + v.coor.y;
		i++;
	}
	return (i);
}

void	*ft_ship(void *v)
{
	int		itr;
	int		i;
	int		j;
	t_var	*t;

	t = (t_var *)v;
	j = t->t_start;
	while (j < t->t_end)
	{
		t->coor.y = ((j + t->move.y) * (t->max.y - t->min.y) / IMG_H)
			+ t->min.y;
		i = 0;
		while (i < IMG_W)
		{
			t->coor.x = ((i + t->move.x) * (t->max.x - t->min.x) / IMG_W)
				+ t->min.x;
			itr = ft_ship_itr(*t);
			t->img_data[(j * IMG_W) + i] = (itr != t->itr) ?
				(itr * 0xF31502 * t->color) : 0x000000;
			i++;
		}
		j++;
	}
	return (NULL);
}
