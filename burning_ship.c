/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:43:03 by dpalacio          #+#    #+#             */
/*   Updated: 2022/05/24 11:58:46 by dpalacio         ###   ########.fr       */
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

void	burning_ship(t_data *data)
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
				img_pixel_put(data, x, y, iter * RED / 50);
			iter = 0;
			y++;
		}
		y = 0;
		x++;
	}
}
