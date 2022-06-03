/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:46:02 by dpalacio          #+#    #+#             */
/*   Updated: 2022/06/03 21:19:31 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	mandelbrot(t_data *data, t_pixel *pixel);
static int	julia(t_data *data, t_pixel *pixel);
static int	burning_ship(t_data *data, t_pixel *pixel);

int	choose_fractal(t_data *data, t_pixel *pixel)
{
	if (data->fractal == 0)
		return (mandelbrot(data, pixel));
	else if (data->fractal == 1)
		return (julia(data, pixel));
	else if (data->fractal == 2)
		return (burning_ship(data, pixel));
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
	while (pixel->iter < data->max_iter && ft_abs(zr + zi) < 16.0)
	{
		temp = zr * zr - zi * zi + cr;
		zi = 2.0 * zr * zi + ci;
		zr = temp;
		pixel->iter++;
	}
	iter_color(data, pixel->iter);
	pixel->distance = get_distance(data, zr, zi);
	return (pixel->iter);
}

static int	julia(t_data *data, t_pixel *pixel)
{
	long double	cr;
	long double	ci;
	long double	zr;
	long double	zi;
	long double	temp;
//need to figure out how to stop the value shift when zooming and moving
	cr = map_real(data->mouse_x, data);
	ci = map_imaginary(data->mouse_y, data);
	zr = map_real(pixel->x, data);
	zi = map_imaginary(pixel->y, data);
	while (pixel->iter < data->max_iter && zr * zr + zi * zi < 16.0)
	{
		temp = zr * zr - zi * zi + cr;
		zi = 2.0 * zr * zi + ci;
		zr = temp;
		pixel->iter++;
	}
	iter_color(data, pixel->iter);
	pixel->distance = get_distance(data, zr, zi);
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
	while (pixel->iter < data->max_iter && zr * zr + zi * zi < 4.0)
	{
		temp = zr * zr - zi * zi + cr;
		zi = fabsl(2.0 * zr * zi) + ci;
		zr = (temp);
		pixel->iter++;
	}
	pixel->distance = get_distance(data, zr, zi);
	return (pixel->iter);
}
