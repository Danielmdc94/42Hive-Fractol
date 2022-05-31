/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:46:02 by dpalacio          #+#    #+#             */
/*   Updated: 2022/05/31 19:03:37 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	mandelbrot(t_data *data, int x, int y, int iter);
static int	julia(t_data *data, int x, int y, int iter);
static int	burning_ship(t_data *data, int x, int y, int iter);

int	choose_fractal(t_data *data, int x, int y, int iter)
{
	if (ft_strcmp(data->fractal, "mandelbrot") == 0)
		return (mandelbrot(data, x, y, iter));
	else if (ft_strcmp(data->fractal, "julia") == 0)
		return (julia(data, x, y, iter));
	else if (ft_strcmp(data->fractal, "burning_ship") == 0)
		return (burning_ship(data, x, y, iter));
	return (0);
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

	cr = /*map_real(data->mouse_x, data);*/ (data->mouse_x - WIN_WIDTH / 2.0) / 666.0;
	ci = /*map_imaginary(data->mouse_y, data);*/ (data->mouse_y - WIN_HEIGHT / 2.0) / 666.0;
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

static int	burning_ship(t_data *data, int x, int y, int iter)
{
	double	cr;
	double	ci;
	double	zr;
	double	zi;
	double	temp;

	cr = map_real(x, data);
	ci = map_imaginary(y, data);
	zr = cr;
	zi = ci;
	while (iter < data->max_iter && zr * zr + zi * zi < 4.0)
	{
		temp = zr * zr - zi * zi + cr;
		zi = fabs(2.0 * zr * zi) + ci;
		zr = (temp);
		iter++;
	}
	get_distance(data, zr, zi);
	return (iter);
}
