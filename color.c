/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:03:10 by dpalacio          #+#    #+#             */
/*   Updated: 2022/06/08 12:43:17 by dpalacio         ###   ########.fr       */
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
	return (distance * 10);
}
