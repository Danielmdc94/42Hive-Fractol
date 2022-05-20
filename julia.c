/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 11:47:17 by dpalacio          #+#    #+#             */
/*   Updated: 2022/05/20 14:04:32 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	iterate(t_data *data, int x, int y, int iter)
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
	return (iter);
}

void	julia(t_data *data)
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
				img_pixel_put(data, x, y, GREEN * iter / 50);
			iter = 0;
			y++;
		}
		y = 0;
		x ++;
	}
}
