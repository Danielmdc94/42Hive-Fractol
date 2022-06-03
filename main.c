/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:40:52 by dpalacio          #+#    #+#             */
/*   Updated: 2022/06/03 20:36:42 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	e_print_exit(char *e_string, t_data *data)
{
	ft_putendl(e_string);
	exit_fractol(data);
}

int	exit_fractol(t_data *data)
{
	exit(0);
	free(data);
	return (1);
}

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
	
	data_init(&data);
	hook_control(&data);
}
