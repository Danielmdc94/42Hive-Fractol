/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:34:32 by dpalacio          #+#    #+#             */
/*   Updated: 2022/05/31 20:06:11 by dpalacio         ###   ########.fr       */
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
	return ((double)x * (range / WIN_WIDTH) + data->r_min);
}

double	map_imaginary(int y, t_data *data)
{
	double	range;

	range = data->i_max - data->i_min;
	return ((double)y * (range / WIN_HEIGHT) + data->i_min);
}
