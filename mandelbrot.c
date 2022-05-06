/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:40:39 by dpalacio          #+#    #+#             */
/*   Updated: 2022/05/06 14:57:22 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_data data)
{
	int		x;
	int		y;
	int		iter;
	double	cr;
	double	ci;
	int		z;
	int		zr;
	int		zi;
	int		temp;

//	z(iter)=z2 + c

	x = 0;
	y = 0;
	iter = 0;
	z = 0;


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
	}


}
