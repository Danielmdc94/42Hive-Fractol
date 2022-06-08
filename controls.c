/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 20:17:24 by dpalacio          #+#    #+#             */
/*   Updated: 2022/06/08 11:19:59 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	if (key == 82 || key == 83 || key == 84)
		change_fractal(key, data);
	if (key == 33 || key == 30)
		change_escape(key, data);
	ft_putnbr(key);
	ft_putchar('\n');
	return (1);
}

int	on_mousedown(int button, int x, int y, t_data *data)
{
	if (button == 4 || button == 5)
		zoom(button, x, y, data);
	if (button == 1)
		mouse_lock(button, x, y, data);
	ft_putnbr(button);
	ft_putchar('\n');
	return (1);
}

int	on_mouseup(int button, int x, int y, t_data *data)
{
	return (1);
}

int	on_mousemove(int x, int y, t_data *data)
{
	if (data->mouse_lock == 0)
	{
		data->mouse_x = x;
		data->mouse_y = y;
	}
	return (1);
}
