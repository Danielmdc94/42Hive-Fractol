/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:40:52 by dpalacio          #+#    #+#             */
/*   Updated: 2022/06/17 11:24:45 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* Is called in case of an error and prints the message given */
void	e_print_exit(char *e_string, t_data *data)
{
	ft_putendl(e_string);
	exit_fractol(data);
}

/* Quits the program after freeing the data structure */
int	exit_fractol(t_data *data)
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
		e_print_exit("Usage: ./fractol <fractal_name>", &data);
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
		data.fractal = 0;
	else if (ft_strcmp(argv[1], "julia") == 0)
		data.fractal = 1;
	else if (ft_strcmp(argv[1], "burning_ship") == 0)
		data.fractal = 2;
	else if (ft_strcmp(argv[1], "burning_julia") == 0)
		data.fractal = 3;
	else
		data.fractal = -1;
	data_init(&data);
	hook_control(&data);
}
