/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:14:53 by dpalacio          #+#    #+#             */
/*   Updated: 2022/05/12 18:28:14 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move_camera(int key, t_data *data)
{
	if (key == 123)
	{
		data->r_min = data->r_min - 0.1 / data->zoom;
		data->r_max = data->r_max - 0.1 / data->zoom;
	}
	if (key == 124)
	{
		data->r_min = data->r_min + 0.1 / data->zoom;
		data->r_max = data->r_max + 0.1 / data->zoom;
	}
	if (key == 125)
	{
		data->i_min = data->i_min + 0.1 / data->zoom;
		data->i_max = data->i_max + 0.1 / data->zoom;
	}
	if (key == 126)
	{
		data->i_min = data->i_min - 0.1 / data->zoom;
		data->i_max = data->i_max - 0.1 / data->zoom;
	}
	fractal_to_window(data);
}
