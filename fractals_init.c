/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 19:00:08 by dpalacio          #+#    #+#             */
/*   Updated: 2022/07/22 13:33:15 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_mandelbrot(t_data *data);
static void	init_julia(t_data *data);
static void	init_burning_ship(t_data *data);

/* Picks a funtion to plot the window depending on the current fractal */
void	fractals_init(t_data *data)
{
	if (data->fractal == 0 || data->fractal == 4 || data->fractal == 6
		|| data->fractal == 7)
		init_mandelbrot(data);
	else if (data->fractal == 1 || data->fractal == 3)
		init_julia(data);
	else if (data->fractal == 2 || data->fractal == 5)
		init_burning_ship(data);
	else
		e_print_exit("Valid fractals:\n - mandelbrot\n - julia\n - burning_ship\n \
- burning_julia\n - melt_mandelbrot\n - melt_ship\n - celtic\n - melt_celtic",
			data);
	data->start.r_min = data->r_min;
	data->start.r_max = data->r_max;
	data->start.i_min = data->i_min;
	data->start.i_max = data->i_max;
	data->escape = 16.0;
}

static void	init_mandelbrot(t_data *data)
{
	data->r_min = -2;
	data->r_max = 0.5;
	data->i_min = -1.25;
	data->i_max = 1.25;
	data->max_iter = 50;
	data->zoom = 1.0;
}

static void	init_julia(t_data *data)
{
	data->r_min = -1.25;
	data->r_max = 1.25;
	data->i_min = -1.25;
	data->i_max = 1.25;
	data->max_iter = 50;
	data->zoom = 1.0;
	data->mouse_lock = 0;
}

static void	init_burning_ship(t_data *data)
{
	data->r_min = -2;
	data->r_max = 1;
	data->i_min = -1.5;
	data->i_max = 1.5;
	data->max_iter = 50;
	data->zoom = 1.0;
}
