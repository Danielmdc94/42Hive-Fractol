/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:40:39 by dpalacio          #+#    #+#             */
/*   Updated: 2022/05/06 17:07:29 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	mandelbrot(t_data data)
{
	int		x;
	int		y;
	int		iter;
	double	cr;
	double	ci;
	double		z;
	double		zr;
	double		zi;
	double		temp;

//z0=z^2 + c = c
//z1=z^2 + c = c^2 + c
//z2=z^2 + c = (c^2 + c)^2 + c
//...

//c = (cr + ci * I)
//c^2 = cr^2 - ci^2 + 2 * cr * ci I

	data.r_min = -2;
	data.r_max = 1;
	data.i_min = -1;
	data.i_max = 1;

	x = 0;
	y = 0;
	iter = 0;
	z = 0;
	zr = 0;
	zi = 0;

	while (x < WIN_WIDTH)
	{
		while (y < WIN_HEIGHT)
		{
			//ecuation start
			cr = (x * ((data.r_max - data.r_min) / WIN_WIDTH) + data.r_min);
			ci = (y * ((data.i_max - data.r_max) / WIN_HEIGHT) + data.i_min);
//			printf("%f ", cr);
			while (iter < 3 && ft_abs(zr + zi) < 16.0)
			{
//				printf("%f & %f  ", zr, zi);
				temp = zr * zr - zi * zi + cr;
				zi = 2.0 * zr * zi + ci;
				zr = temp;
				iter++;
				printf("%d ", iter);
			}
			//ecuation finish
			if (iter == 3)
			{
				printf("%d ", iter);
				img_pixel_put(&data, x, y, RED);
			}
			y++;
			iter = 0;
		}
		y = 0;
		x++;
	}

/*
	while (y < WIN_HEIGHT)
	{
		while (x < WIN_WIDTH)
		{
			cr = (x * ((1 +2) / WIN_WIDTH) -2);
			ci = (y * ((1 +1) / WIN_HEIGHT) -1);
			while (iter < 50)
			{
				if (ft_abs(zr + zi) > 16)
					break ;
				temp = zr * zr - zi * zi + cr;
				zi = 2 * zr * zi + ci;
				zr = temp;
				iter++;
			}
			cr = zr;
			ci = zi;
			if (iter == 50)
				img_pixel_put(&data, x, y, WHITE);
			iter = 0;
			x++;
		}
		x = 0;
		y++;
	}*/
}
