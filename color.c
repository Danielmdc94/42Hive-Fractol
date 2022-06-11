/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:03:10 by dpalacio          #+#    #+#             */
/*   Updated: 2022/06/11 16:07:06 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	color(t_data *data, t_pixel *pixel)
{
	if (data->color_mode == 0)
		return (iter_color(data, pixel->iter));
	if (data->color_mode == 1)
		return (distance_color(data, pixel->distance));
	else
		return (0);
}

int	iter_color(t_data *data, int iter)
{
	if (iter == data->max_iter)
		return (BLACK);
	else
		return (iter * RED / 50);
}

int	distance_color(t_data *data, long double distance)
{
	return (distance * GREEN);
}

t_color	int_to_argb(int color)
{
	t_color	argb;

	argb.a = color >> 24;
	argb.r = (color & 0x00FF0000) >> 16;
	argb.g = (color & 0x0000FF00) >> 8;
	argb.b = (color & 0x000000FF);
	return (argb);
}

int		argb_to_int(int a, int r, int g, int b)
{
	int	color;

	color = (a << 24) + (r << 16) + (g << 8) + b;
	return color;
}
