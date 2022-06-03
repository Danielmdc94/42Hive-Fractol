/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:14:53 by dpalacio          #+#    #+#             */
/*   Updated: 2022/06/03 20:46:10 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

void	max_iter(int key, t_data *data)
{
	if (key == 27 && data->max_iter > 0)
		data->max_iter = data->max_iter - 1;
	if (key == 24 && data->max_iter < 500)
		data->max_iter = data->max_iter + 1;
}

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
