/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:54:02 by dpalacio          #+#    #+#             */
/*   Updated: 2022/05/17 16:51:16 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(int button, int x, int y, t_data *data)
{
	if (button == 5)
	{
		data->r_min = data->r_min * 1.1;
		data->r_max = data->r_max * 1.1;
		data->i_min = data->i_min * 1.1;
		data->i_max = data->i_max * 1.1;
		if (data->max_iter > 50 && (data->max_iter - data->zoom) >= 50)
			data->max_iter = data->max_iter - data->zoom;
		data->zoom--;
	}
	if (button == 4)
	{
		data->r_min = data->r_min / 1.1;
		data->r_max = data->r_max / 1.1;
		data->i_min = data->i_min / 1.1;
		data->i_max = data->i_max / 1.1;
		if (data->max_iter < 500 && (data->max_iter + data->zoom) >= 50)
			data->max_iter = data->max_iter + data->zoom;
		data->zoom++;
	}
	fractal_to_window(data);
}
