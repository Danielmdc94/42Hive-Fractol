/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:54:02 by dpalacio          #+#    #+#             */
/*   Updated: 2022/06/01 15:45:45 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(int button, int x, int y, double z, t_data *data)
{
	double	x_map;
	double	y_map;

	x_map = map_real(x, data);
	y_map = map_imaginary(y, data);
	data->r_min = data->r_min + fabs(data->r_min - x_map) * 0.1;
	data->r_max = data->r_max - fabs(data->r_max - x_map) * 0.1;
	data->i_min = data->i_min + fabs(data->i_min - y_map) * 0.1;
	data->i_max = data->i_max - fabs(data->i_max - y_map) * 0.1;
	data->zoom *= z;
}

void	mouse_lock(int button, int x, int y, t_data *data)
{
	if (data->mouse_lock == 0)
		data->mouse_lock = 1;
	else if (data->mouse_lock == 1)
		data->mouse_lock = 0;
}
