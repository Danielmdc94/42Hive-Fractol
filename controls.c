/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 20:17:24 by dpalacio          #+#    #+#             */
/*   Updated: 2022/06/13 16:36:18 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* Calls a corresponding function when a defined key is pressed */
int	on_keydown(int key, t_data *data)
{
	if (key == 53)
		exit_fractol(data);
	if (key == 123 || key == 124 || key == 125 || key == 126)
		move_camera(key, data);
	if (key == 24 || key == 27)
		max_iter(key, data);
	if (key == 49)
		fractals_init(data);
	if (key == 262)
		change_colors(key, data);
	if (key == 82 || key == 83 || key == 84 || key == 85)
		change_fractal(key, data);
	if (key == 33 || key == 30)
		change_escape(key, data);
	return (1);
}

/* Calls a corresponding function when a defined mouse button is pressed
 * or the wheel is rolled */
int	on_mousedown(int button, int x, int y, t_data *data)
{
	if (button == 4 || button == 5)
		zoom(button, x, y, data);
	if (button == 1)
		mouse_lock(button, x, y, data);
	return (1);
}

/* Records the position of the mouse every time it moves */
int	on_mousemove(int x, int y, t_data *data)
{
	if (data->mouse_lock == 0)
	{
		data->mouse_x = x;
		data->mouse_y = y;
	}
	return (1);
}
