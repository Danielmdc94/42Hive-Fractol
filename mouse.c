/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:54:02 by dpalacio          #+#    #+#             */
/*   Updated: 2022/05/31 20:10:24 by dpalacio         ###   ########.fr       */
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
		data->zoom = data->zoom - 1;
	}
	if (button == 4)
	{
		data->r_min = data->r_min / 1.5;
		data->r_max = data->r_max / 1.5;
		data->i_min = data->i_min / 1.5;
		data->i_max = data->i_max / 1.5;
		data->zoom = data->zoom + 1;
	}
}

void	mouse_lock(int button, int x, int y, t_data *data)
{
	if (data->mouse_lock == 0)
		data->mouse_lock = 1;
	else if (data->mouse_lock == 1)
		data->mouse_lock = 0;

}
