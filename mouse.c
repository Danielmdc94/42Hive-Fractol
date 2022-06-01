/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:54:02 by dpalacio          #+#    #+#             */
/*   Updated: 2022/06/01 11:40:17 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(int button, int x, int y, double z, t_data *data)
{
	data->r_min += (data->r_min - map_real(x, data)) * (data->zoom);
	data->r_max = (data->r_max - map_real(x, data)) * (data->zoom);
	data->i_min = (data->i_min - map_imaginary(y, data)) * (data->zoom);
	data->i_max = (data->i_max - map_imaginary(y, data)) * (data->zoom);
	data->zoom *= z;
}

void	mouse_lock(int button, int x, int y, t_data *data)
{
	if (data->mouse_lock == 0)
		data->mouse_lock = 1;
	else if (data->mouse_lock == 1)
		data->mouse_lock = 0;

}
