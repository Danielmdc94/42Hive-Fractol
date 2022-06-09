/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:54:02 by dpalacio          #+#    #+#             */
/*   Updated: 2022/06/08 13:04:10 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(int button, int x, int y, t_data *data)
{
	double	x_map;
	double	y_map;

	x_map = map_real(x, data);
	y_map = map_imaginary(y, data);
	if (button == 4 && data->zoom < 375)
	{
		data->r_min += fabsl(data->r_min - x_map) * ZOOM;
		data->r_max -= fabsl(data->r_max - x_map) * ZOOM;
		data->i_min += fabsl(data->i_min - y_map) * ZOOM;
		data->i_max -= fabsl(data->i_max - y_map) * ZOOM;
		data->zoom++;
	}
	if (button == 5 && data->zoom > -50)
	{
		data->r_min -= fabsl(data->r_min - x_map) * ZOOM;
		data->r_max += fabsl(data->r_max - x_map) * ZOOM;
		data->i_min -= fabsl(data->i_min - y_map) * ZOOM;
		data->i_max += fabsl(data->i_max - y_map) * ZOOM;
		data->zoom--;
	}
}

void	mouse_lock(int button, int x, int y, t_data *data)
{
	if (data->mouse_lock == 0)
		data->mouse_lock = 1;
	else if (data->mouse_lock == 1)
		data->mouse_lock = 0;
}
