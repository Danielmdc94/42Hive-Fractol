/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:37:41 by dpalacio          #+#    #+#             */
/*   Updated: 2022/05/31 15:55:36 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
static void get_pixel(t_thread *structs);

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

void	screen_threads(t_data *data)
{
	pthread_t	threads[10];
	t_thread	structs[10];
	int	id;

	id = 0;
	while(id < 10)
	{
		structs[id].id = id;
		structs[id].data = data;
		pthread_create(&threads[id], NULL, get_pixel, (void *)&structs[id]);
		id++;
	}
	while(id >= 0)
	{
		pthread_join(threads[id], NULL);
		id--;
	}
}

static void	get_pixel(t_thread *structs)
{
	int	x;
	int	y;
	int	iter;

	x = 100 * structs->id;
	y = 0;
	iter = 0;
	while (x < 100 * (structs->id + 1))
	{
		while (y < WIN_HEIGHT)
		{
			iter = choose_fractal(structs->data, x, y, iter);
			img_pixel_put(structs->data, x, y, iter_color(structs->data, iter));
			iter = 0;
			y++;
		}
		y = 0;
		x++;
	}
}
