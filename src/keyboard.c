/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:14:53 by dpalacio          #+#    #+#             */
/*   Updated: 2022/07/25 19:35:46 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/* Changes the ploting values to "move" the fractal by
 * pressing the arrow keys */
void	move_camera(int key, t_data *data)
{
	long double	r_move;
	long double	i_move;

	r_move = fabsl(data->r_max - data->r_min) / 20;
	i_move = fabsl(data->i_max - data->i_min) / 20;
	if (key == 123)
	{
		data->r_min -= r_move;
		data->r_max -= r_move;
	}
	if (key == 124)
	{
		data->r_min += r_move;
		data->r_max += r_move;
	}
	if (key == 125)
	{
		data->i_min += i_move;
		data->i_max += i_move;
	}
	if (key == 126)
	{
		data->i_min -= i_move;
		data->i_max -= i_move;
	}
}

/* Changes the maximum number of iterations the fractal ecuations
 * complete before exiting the loop by presing + or - */
void	max_iter(int key, t_data *data)
{
	if (key == 27 && data->max_iter > 0)
		data->max_iter = data->max_iter - 1;
	if (key == 24 && data->max_iter < 500)
		data->max_iter = data->max_iter + 1;
}

/* Changes the coloring method from iterations to distance and the other
 * way around by pressing the 'option' key */
void	change_colors(int key, t_data *data)
{
	if (key == 262)
	{
		if (data->color_mode == 0)
			data->color_mode = 1;
		else if (data->color_mode == 1)
			data->color_mode = 0;
	}
}

/* Changes the fractal to be drawn with the numpad */
void	change_fractal(int key, t_data *data)
{
	if (key == 82)
		data->fractal = 0;
	if (key == 83)
		data->fractal = 1;
	if (key == 84)
		data->fractal = 2;
	if (key == 85)
		data->fractal = 3;
	if (key == 86)
		data->fractal = 4;
	if (key == 87)
		data->fractal = 5;
	if (key == 88)
		data->fractal = 6;
	if (key == 89)
		data->fractal = 7;
	fractals_init(data);
}

/* Changes the value of "infinity" determining when the ecuation escapes
 * such value by pressing [ or ] */
void	change_escape(int key, t_data *data)
{
	if (key == 33 && data->escape > 0)
		data->escape--;
	if (key == 30 && data->escape < 128)
		data->escape++;
}
