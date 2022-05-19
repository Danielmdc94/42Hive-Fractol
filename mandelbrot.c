/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:40:39 by dpalacio          #+#    #+#             */
/*   Updated: 2022/05/19 18:05:30 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_abscomplex(double zr, double zi)
{
	double	abs;

	abs = sqrt(zr * zr + zi * zi);
	return (abs);
}

void	get_distance(t_data *data, double zr, double zi)
{
	double	distance;
	double	z_point;

	distance = 10e5;
	z_point = ft_abscomplex(zr, zi);
	if (z_point < distance)
		data->distance = z_point;
}

double	map_real(int x, t_data *data)
{
	double	range;

	range = data->r_max - data->r_min;
	return (x * (range / data->height) + data->r_min);
}

double	map_imaginary(int y, t_data *data)
{
	double	range;

	range = data->i_max - data->i_min;
	return (y * (range / data->height) + data->i_min);
}

static int	iterate(t_data *data, int x, int y, int iter)
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
		get_distance(data, zr, zi);
		iter++;
	}
	return (iter);
}

void	mandelbrot(t_data *data)
{
	int	x;
	int	y;
	int	iter;

	x = 0;
	y = 0;
	iter = 0;
	while (x < data->width)
	{
		while (y < data->height)
		{
			iter = iterate(data, x, y, iter);
			if (iter == data->max_iter)
				img_pixel_put(data, x, y, BLACK);
			else
				img_pixel_put(data, x, y, iter * GREEN / 50);
			iter = 0;
			y++;
		}
		y = 0;
		x++;
	}
}
