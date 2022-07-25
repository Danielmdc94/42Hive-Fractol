/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:34:32 by dpalacio          #+#    #+#             */
/*   Updated: 2022/07/25 19:38:32 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/* Gets the absolute value of a complex number where the first argument
 * is the real value and the second is the imaginary */
long double	ft_abscomplex(long double zr, long double zi)
{
	long double	abs;

	abs = sqrt(zr * zr + zi * zi);
	return (abs);
}

/* Gets the distance to the orbit trap of a point within the complex plain */
long double	get_distance(long double zr, long double zi)
{
	long double	distance;
	long double	z_point;

	distance = 10e5;
	z_point = ft_abscomplex(zr, zi);
	if (z_point < distance)
		return (z_point);
	else
		return (distance);
}

/* Maps the horizontal value of a point to
 * the real value of the complex plane */
long double	map_real(int x, t_data *data)
{
	double	range;

	range = data->r_max - data->r_min;
	return ((long double)x * (range / WIN_WIDTH) + data->r_min);
}

/* Maps the vertical value of a point to
 * the imaginary value of the complex plane */
long double	map_imaginary(int y, t_data *data)
{
	double	range;

	range = data->i_max - data->i_min;
	return ((long double)y * (range / WIN_HEIGHT) + data->i_min);
}
