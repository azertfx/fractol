/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anabaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 02:01:50 by anabaoui          #+#    #+#             */
/*   Updated: 2019/11/21 23:52:17 by anabaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		strtolower(argv[1]);
		if ((ft_strcmp(argv[1], "mandelbrot") == 0) || (ft_strcmp(argv[1], "julia") == 0))
		{
			fractol(argv[1]);
			return (0);
		}
	}
	ft_putstr("usage : ./fractol [Fractols]\n");
	ft_putstr(" Fractols :\n");
	ft_putstr(" --> Mandelbrot\n");
	ft_putstr(" --> Julia\n");
	return (0);
}
