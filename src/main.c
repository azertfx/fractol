/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anabaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 02:01:50 by anabaoui          #+#    #+#             */
/*   Updated: 2020/01/17 17:38:44 by anabaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		ft_strtolower(argv[1]);
		if ((ft_strcmp(argv[1], "mandelbrot") == 0) || (ft_strcmp(argv[1],
						"julia") == 0) || (ft_strcmp(argv[1], "ship") == 0)
				|| (ft_strcmp(argv[1], "quatro") == 0) || (ft_strcmp(argv[1],
						"penta") == 0))
		{
			ft_fractol(argv[1]);
			return (0);
		}
	}
	ft_putstr("usage : ./fractol [Fractols]\n");
	ft_putstr(" Fractols :\n");
	ft_putstr(" --> Mandelbrot\n");
	ft_putstr(" --> Julia\n");
	ft_putstr(" --> Ship\n");
	ft_putstr(" --> Quatro\n");
	ft_putstr(" --> Penta\n");
	return (0);
}
