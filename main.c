/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:40:52 by dpalacio          #+#    #+#             */
/*   Updated: 2022/07/22 14:58:34 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* Is called in case of an error and prints the message given,
 * then, exits the program */
void	e_print_exit(char *e_string)
{
	ft_putendl(e_string);
	exit_fractol();
}

/* Quits the program */
int	exit_fractol(void)
{
	exit(0);
	return (1);
}

/* Start of the program, checks that the argument given is valid
 * and calls the initializing function before hooking to events */
int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		e_print_exit("Usage: ./fractol <fractal_name>\n\nValid fractals:\n\
 - mandelbrot\n - julia\n - burning_ship\n - burning_julia\n\
 - melt_mandelbrot\n - melt_ship\n - celtic\n - melt_celtic");
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
		data.fractal = 0;
	else if (ft_strcmp(argv[1], "julia") == 0)
		data.fractal = 1;
	else if (ft_strcmp(argv[1], "burning_ship") == 0)
		data.fractal = 2;
	else if (ft_strcmp(argv[1], "burning_julia") == 0)
		data.fractal = 3;
	else if (ft_strcmp(argv[1], "melt_mandelbrot") == 0)
		data.fractal = 4;
	else if (ft_strcmp(argv[1], "melt_ship") == 0)
		data.fractal = 5;
	else if (ft_strcmp(argv[1], "celtic") == 0)
		data.fractal = 6;
	else if (ft_strcmp(argv[1], "melt_celtic") == 0)
		data.fractal = 7;
	else
		data.fractal = -1;
	data_init(&data);
	hook_control(&data);
}
