/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:54:02 by dpalacio          #+#    #+#             */
/*   Updated: 2022/05/20 17:41:55 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(int button, int x, int y, t_data *data)
{
	if (button == 5)
	{
		data->r_min = data->r_min * 1.5;
		data->r_max = data->r_max * 1.5;
		data->i_min = data->i_min * 1.5;
		data->i_max = data->i_max * 1.5;
		data->zoom--;
	}
	if (button == 4)
	{
		data->r_min = data->r_min / 1.5;
		data->r_max = data->r_max / 1.5;
		data->i_min = data->i_min / 1.5;
		data->i_max = data->i_max / 1.5;
		data->zoom++;
	}
}

void	modify_complex(int button, int x, int y, t_data *data)
{
	data->cr = (data->mouse_x - WIN_WIDTH / 2.0) / 666.0;
	data->ci = (data->mouse_y - WIN_HEIGHT / 2.0) / 666.0;
}
