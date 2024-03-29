/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:03:10 by dpalacio          #+#    #+#             */
/*   Updated: 2022/07/25 19:41:42 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/* Chooses a coloring method based on the number of iterations of the
 * ecuation on the given pixel or based on the distance to the orbit trap,
 * depending on the selected method */
int	color(t_data *data, t_pixel *pixel)
{
	if (data->color_mode == 0)
		return (iter_color(data, pixel->iter));
	if (data->color_mode == 1)
		return (distance_color(pixel->distance));
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

int	distance_color(long double distance)
{
	return (distance * BLUE);
}
