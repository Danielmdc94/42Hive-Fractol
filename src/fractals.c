/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:46:02 by dpalacio          #+#    #+#             */
/*   Updated: 2022/07/25 19:43:34 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static int	mandelbrot(t_data *data, t_pixel *pixel);
static int	julia(t_data *data, t_pixel *pixel);
static int	burning_ship(t_data *data, t_pixel *pixel);
static int	burning_julia(t_data *data, t_pixel *pixel);

/* Depending on the given data, choses a fractal ecuation to
 * apply iteratively on the given pixel */
int	choose_fractal(t_data *data, t_pixel *pixel)
{
	if (data->fractal == 0)
		return (mandelbrot(data, pixel));
	else if (data->fractal == 1)
		return (julia(data, pixel));
	else if (data->fractal == 2)
		return (burning_ship(data, pixel));
	else if (data->fractal == 3)
		return (burning_julia(data, pixel));
	else if (data->fractal == 4)
		return (melt_mandelbrot(data, pixel));
	else if (data->fractal == 5)
		return (melt_ship(data, pixel));
	else if (data->fractal == 6)
		return (celtic(data, pixel));
	else if (data->fractal == 7)
		return (melt_celtic(data, pixel));
	return (0);
}

static int	mandelbrot(t_data *data, t_pixel *pixel)
{
	long double	cr;
	long double	ci;
	long double	zr;
	long double	zi;
	long double	temp;

	cr = map_real(pixel->x, data);
	ci = map_imaginary(pixel->y, data);
	zr = 0;
	zi = 0;
	while (pixel->iter < data->max_iter && ft_abs(zr + zi) < data->escape)
	{
		temp = zr * zr - zi * zi + cr;
		zi = 2.0 * zr * zi + ci;
		zr = temp;
		pixel->iter++;
	}
	pixel->distance = get_distance(zr, zi);
	return (pixel->iter);
}

static int	julia(t_data *data, t_pixel *pixel)
{
	long double	cr;
	long double	ci;
	long double	zr;
	long double	zi;
	long double	temp;

	cr = ((long double)data->mouse_x * ((data->start.r_max - data->start.r_min)
				/ WIN_WIDTH) + data->start.r_min);
	ci = ((long double)data->mouse_y * ((data->start.i_max - data->start.i_min)
				/ WIN_HEIGHT) + data->start.i_min);
	zr = map_real(pixel->x, data);
	zi = map_imaginary(pixel->y, data);
	while (pixel->iter < data->max_iter && zr * zr + zi * zi < data->escape)
	{
		temp = zr * zr - zi * zi + cr;
		zi = 2.0 * zr * zi + ci;
		zr = temp;
		pixel->iter++;
	}
	pixel->distance = get_distance(zr, zi);
	return (pixel->iter);
}

static int	burning_ship(t_data *data, t_pixel *pixel)
{
	long double	cr;
	long double	ci;
	long double	zr;
	long double	zi;
	long double	temp;

	cr = map_real(pixel->x, data);
	ci = map_imaginary(pixel->y, data);
	zr = cr;
	zi = ci;
	while (pixel->iter < data->max_iter && zr * zr + zi * zi < data->escape)
	{
		temp = (zr * zr - zi * zi) + cr;
		zi = fabsl(2.0 * zr * zi) + ci;
		zr = (temp);
		pixel->iter++;
	}
	pixel->distance = get_distance(zr, zi);
	return (pixel->iter);
}

static int	burning_julia(t_data *data, t_pixel *pixel)
{
	long double	cr;
	long double	ci;
	long double	zr;
	long double	zi;
	long double	temp;

	cr = ((long double)data->mouse_x * ((data->start.r_max - data->start.r_min)
				/ WIN_WIDTH) + data->start.r_min);
	ci = ((long double)data->mouse_y * ((data->start.i_max - data->start.i_min)
				/ WIN_HEIGHT) + data->start.i_min);
	zr = map_real(pixel->x, data);
	zi = map_imaginary(pixel->y, data);
	while (pixel->iter < data->max_iter && zr * zr + zi * zi < data->escape)
	{
		temp = zr * zr - zi * zi + cr;
		zi = fabsl(2.0 * zr * zi) + ci;
		zr = (temp);
		pixel->iter++;
	}
	pixel->distance = get_distance(zr, zi);
	return (pixel->iter);
}
