/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:40:39 by dpalacio          #+#    #+#             */
/*   Updated: 2022/05/30 14:33:56 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	mandelbrot_tl(t_data *data);
static void	mandelbrot_tr(t_data *data);
static void	mandelbrot_bl(t_data *data);
static void	mandelbrot_br(t_data *data);

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
		iter++;
	}
	iter_color(data, iter);
	get_distance(data, zr, zi);
	return (iter);
}

void	mandelbrot(t_data *data)
{
	pthread_t	threads[4];

	pthread_create(&threads[0], NULL, mandelbrot_tl, (void *)data);
	pthread_create(&threads[1], NULL, mandelbrot_tr, (void *)data);
	pthread_create(&threads[2], NULL, mandelbrot_bl, (void *)data);
	pthread_create(&threads[3], NULL, mandelbrot_br, (void *)data);
	pthread_join(&threads[0], NULL);
	pthread_join(&threads[1], NULL);
	pthread_join(&threads[2], NULL);
	pthread_join(&threads[3], NULL);
}


static void	mandelbrot_tl(t_data *data)
{
	int	x;
	int	y;
	int	iter;

	x = 0;
	y = 0;
	iter = 0;
	while (x < data->width / 2)
	{
		while (y < data->height / 2)
		{
			iter = iterate(data, x, y, iter);
//			img_pixel_put(data, x, y, data->color);
			if (iter == data->max_iter)
				img_pixel_put(data, x, y, BLACK);
			else
				img_pixel_put(data, x, y, iter * RED / 50);
			 iter = 0;
			y++;
		}
		y = 0;
		x++;
	}
}

static void	mandelbrot_tr(t_data *data)
{
	int	x;
	int	y;
	int	iter;

	x = data->width / 2;
	y = 0;
	iter = 0;
	while (x < data->width)
	{
		while (y < data->height / 2)
		{
			iter = iterate(data, x, y, iter);
//			img_pixel_put(data, x, y, data->color);
			if (iter == data->max_iter)
				img_pixel_put(data, x, y, BLACK);
			else
				img_pixel_put(data, x, y, iter * RED / 50);
			iter = 0;
			y++;
		}
		y = 0;
		x++;
	}
}

static void	mandelbrot_bl(t_data *data)
{
	int	x;
	int	y;
	int	iter;

	x = 0;
	y = data->height / 2;
	iter = 0;
	while (x < data->width / 2)
	{
		while (y < data->height)
		{
			iter = iterate(data, x, y, iter);
//			img_pixel_put(data, x, y, data->color);
			if (iter == data->max_iter)
				img_pixel_put(data, x, y, BLACK);
			else
				img_pixel_put(data, x, y, iter * RED / 50);
			iter = 0;
			y++;
		}
		y = data->height / 2;;
		x++;
	}
}

static void	mandelbrot_br(t_data *data)
{
	int	x;
	int	y;
	int	iter;

	x = data->width / 2;
	y = data->height / 2;
	iter = 0;
	while (x < data->width)
	{
		while (y < data->height)
		{
			iter = iterate(data, x, y, iter);
//			img_pixel_put(data, x, y, data->color);
			if (iter == data->max_iter)
				img_pixel_put(data, x, y, BLACK);
			else
				img_pixel_put(data, x, y, iter * RED / 50);
			iter = 0;
			y++;
		}
		y = data->height / 2;;
		x++;
	}
}
