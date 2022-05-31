/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:40:52 by dpalacio          #+#    #+#             */
/*   Updated: 2022/05/31 19:40:02 by dpalacio         ###   ########.fr       */
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
	data.fractal = ft_strdup(argv[1]);
	data_init(&data);
	hook_control(&data);
}
