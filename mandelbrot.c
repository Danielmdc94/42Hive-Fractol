/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:40:39 by dpalacio          #+#    #+#             */
/*   Updated: 2022/05/10 20:33:37 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_data *data, int x, int y)
{
	int		iter;
	double	cr;
	double	ci;
	double	zr;
	double	zi;
	double	temp;

//z0=z^2 + c = c
//z1=z^2 + c = c^2 + c
//z2=z^2 + c = (c^2 + c)^2 + c
//...

//c = (cr + ci * I)
//c^2 = cr^2 - ci^2 + 2 * cr * ci I

/*	data->r_min = -2;
	data->r_max = 0.47;
	data->i_min = -1.12;
	data->i_max = 1.12;
*/
	iter = 0;

	cr = (x * ((data->r_max - data->r_min) / data->width) + data->r_min);
	ci = (y * ((data->i_max - data->r_max) / data->height) + data->i_min);
	zr = 0;
	zi = 0;
	while (iter < 100 && ft_abs(zr + zi) < 16.0)
	{
		temp = zr * zr - zi * zi + cr;
		zi = 2.0 * zr * zi + ci;
		zr = temp;
		iter++;
	}
	return (iter);
}

void	draw(t_data *data)
{
	int		x;
	int		y;


	mlx_clear_window(data->mlx, data->win);
	data->width = 1000;
	data->height = 1000;

	x = 100;
	y = 100;

	while (x < data->width)
	{
		while (y < data->height)
		{
			if (mandelbrot(data, x, y) == 100)
			{
				img_pixel_put(data, x, y, BLACK);
			}
			else
				img_pixel_put(data, x, y, GREEN * mandelbrot(data, x, y) / 50);
			y++;
		}
		y = 100;
		x++;
	}
}
