/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:46:02 by dpalacio          #+#    #+#             */
/*   Updated: 2022/05/31 17:02:48 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	mandelbrot(t_data *data, int x, int y, int iter);
static int	julia(t_data *data, int x, int y, int iter);

int	choose_fractal(t_data *data, int x, int y, int iter)
{
	if (ft_strcmp(data->fractal, "mandelbrot") == 0)
		return(mandelbrot(data, x, y, iter));
	else if (ft_strcmp(data->fractal, "julia") == 0)
		return(julia(data, x, y, iter));
	else if (ft_strcmp(data->fractal, "burning_ship") == 0)
		burning_ship(data);
}

static int	mandelbrot(t_data *data, int x, int y, int iter)
{
	double	cr;
	double	ci;
	double	zr;
	double	zi;
	double	temp;

	cr = map_real(x, data);
	ci = map_imaginary(y, data);
	zr = 0;
	zi = 0;
	while (iter < data->max_iter && ft_abs(zr + zi) < 16.0)
	{
		temp = zr * zr - zi * zi + cr;
		zi = 2.0 * zr * zi + ci;
		zr = temp;
		iter++;
	}
	iter_color(data, iter);
	get_distance(data, zr, zi);
	return (iter);
}

static int	julia(t_data *data, int x, int y, int iter)
{
	double	cr;
	double	ci;
	double	zr;
	double	zi;
	double	temp;

	cr = /*map_real(data->mouse_x, data);*/(data->mouse_x - WIN_WIDTH / 2.0) / 666.0;
	ci = /*map_imaginary(data->mouse_y, data);*/(data->mouse_y - WIN_HEIGHT / 2.0) / 666.0;
	zr = map_real(x, data);
	zi = map_imaginary(y, data);
	while (iter < data->max_iter && zr * zr + zi * zi < 16.0)
	{
		temp = zr * zr - zi * zi + cr;
		zi = 2.0 * zr * zi + ci;
		zr = temp;
		iter++;
	}
	iter_color(data, iter);
	get_distance(data, zr, zi);
	return (iter);
}

/*
static int	burning_ship(t_data *data, int x, int y, int iter)
 16 {
 17 >···double>·cr;
 18 >···double>·ci;
 19 >···double>·zr;
 20 >···double>·zi;
 21 >···double>·temp;
 22
 23 >···cr = map_real(x, data);
 24 >···ci = map_imaginary(y, data);
 25 >···zr = cr;
 26 >···zi = ci;
 27 >···while (iter < data->max_iter && zr * zr + zi * zi < 4.0)
 28 >···{
 29 >···>···temp = zr * zr - zi * zi + cr;
 30 >···>···zi = fabs(2.0 * zr * zi) + ci;
 31 >···>···zr = (temp);
 32 >···>···iter++;
 33 >···}
 34 >···get_distance(data, zr, zi);
 35 >···return (iter);
 36 }*/
