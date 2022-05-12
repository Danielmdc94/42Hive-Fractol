/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:54:02 by dpalacio          #+#    #+#             */
/*   Updated: 2022/05/12 14:58:53 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(int button, t_data *data)
{
	if (button == 5)
	{
		data->r_min = data->r_min - data->zoom;
		data->r_max = data->r_max + data->zoom;
		data->i_min = data->i_min - data->zoom;
		data->i_max = data->i_max + data->zoom;
		if (data->max_iter > 50)
			data->max_iter--;
	}
	if (button == 4)
	{
		data->r_min = data->r_min + data->zoom;
		data->r_max = data->r_max - data->zoom;
		data->i_min = data->i_min + data->zoom;
		data->i_max = data->i_max - data->zoom;
		if (data->max_iter < 500)
			data->max_iter++;
	}
	fractal_to_window(data);
}
