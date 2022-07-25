/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:05:05 by dpalacio          #+#    #+#             */
/*   Updated: 2022/07/25 19:48:22 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	melt_mandelbrot(t_data *data, t_pixel *pixel)
{
	long double	cr;
	long double	ci;
	long double	zr;
	long double	zi;
	long double	temp;

	cr = map_real(pixel->x, data);
	ci = map_imaginary(pixel->y, data);
	zr = ((long double)data->mouse_x * ((data->start.r_max - data->start.r_min)
				/ WIN_WIDTH) + data->start.r_min);
	zi = ((long double)data->mouse_y * ((data->start.i_max - data->start.i_min)
				/ WIN_HEIGHT) + data->start.i_min);
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

int	melt_ship(t_data *data, t_pixel *pixel)
{
	long double	cr;
	long double	ci;
	long double	zr;
	long double	zi;
	long double	temp;

	cr = map_real(pixel->x, data);
	ci = map_imaginary(pixel->y, data);
	zr = ((long double)data->mouse_x * ((data->start.r_max - data->start.r_min)
				/ WIN_WIDTH) + data->start.r_min);
	zi = ((long double)data->mouse_y * ((data->start.i_max - data->start.i_min)
				/ WIN_HEIGHT) + data->start.i_min);
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

int	celtic(t_data *data, t_pixel *pixel)
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
		temp = fabsl(zr * zr - zi * zi) + cr;
		zi = 2.0 * zr * zi + ci;
		zr = (temp);
		pixel->iter++;
	}
	pixel->distance = get_distance(zr, zi);
	return (pixel->iter);
}

int	melt_celtic(t_data *data, t_pixel *pixel)
{
	long double	cr;
	long double	ci;
	long double	zr;
	long double	zi;
	long double	temp;

	cr = map_real(pixel->x, data);
	ci = map_imaginary(pixel->y, data);
	zr = ((long double)data->mouse_x * ((data->start.r_max - data->start.r_min)
				/ WIN_WIDTH) + data->start.r_min);
	zi = ((long double)data->mouse_y * ((data->start.i_max - data->start.i_min)
				/ WIN_HEIGHT) + data->start.i_min);
	while (pixel->iter < data->max_iter && ft_abs(zr + zi) < data->escape)
	{
		temp = fabsl(zr * zr - zi * zi) + cr;
		zi = 2.0 * zr * zi + ci;
		zr = (temp);
		pixel->iter++;
	}
	pixel->distance = get_distance(zr, zi);
	return (pixel->iter);
}
