/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 19:00:08 by dpalacio          #+#    #+#             */
/*   Updated: 2022/05/31 19:48:43 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
static void	init_mandelbrot(t_data *data);
static void	init_julia(t_data *data);
static void	init_burning_ship(t_data *data);

void	fractals_init(t_data *data)
{
	if (ft_strcmp(data->fractal, "mandelbrot") == 0)
		init_mandelbrot(data);
	else if (ft_strcmp(data->fractal, "julia") == 0)
		init_julia(data);
	else if (ft_strcmp(data->fractal, "burning_ship") == 0)
		init_burning_ship(data);
	else
		e_print_exit("Valid fractals:\n - mandelbrot\n - julia\n - burning_ship\n",
			data);
}

static void	init_mandelbrot(t_data *data)
{
	data->r_min = -2;
	data->r_max = 0.5;
	data->i_min = -1.25;
	data->i_max = 1.25;
	data->cr = 0.0;
	data->ci = 0.0;
	data->max_iter = 50;
	data->zoom = 0.0;
}

static void	init_julia(t_data *data)
{
	data->r_min = -1.25;
	data->r_max = 1.25;
	data->i_min = -1.25;
	data->i_max = 1.25;
	data->cr = 0.0;
	data->ci = 0.0;
	data->max_iter = 50;
	data->zoom = 0.0;
}

static void	init_burning_ship(t_data *data)
{
	data->r_min = -2;
	data->r_max = 0.5;
	data->i_min = -1.25;
	data->i_max = 1.25;
	data->cr = 0.0;
	data->ci = 0.0;
	data->max_iter = 50;
	data->zoom = 0.0;
}
