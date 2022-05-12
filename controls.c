/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 20:17:24 by dpalacio          #+#    #+#             */
/*   Updated: 2022/05/12 11:57:48 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	on_keydown(int key, t_data *data)
{
	if (key == 53)
		exit_fractol(data);
	if (key == 123 || key == 124 || key == 125 || key == 126)
		move_camera(key, data);
	ft_putnbr(key);
	ft_putchar('\n');
	return (1);
}

int	on_mousedown(int button, int x, int y, t_data *data)
{
	if (button == 5)
	{
		data->r_min = data->r_min - 0.1;
		data->r_max = data->r_max + 0.1;
		data->i_min = data->i_min - 0.1;
		data->i_max = data->i_max + 0.1;
		data->max_iter--;
	}
		if (button == 4)
	{
		data->r_min = data->r_min + 0.1;
		data->r_max = data->r_max - 0.1;
		data->i_min = data->i_min + 0.1;
		data->i_max = data->i_max - 0.1;
		data->max_iter++;
	}
	ft_putnbr(button);
	ft_putchar('\n');
	fractal_to_window(data);
	return (1);
}
