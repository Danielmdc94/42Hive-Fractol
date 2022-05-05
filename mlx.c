/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:21:04 by dpalacio          #+#    #+#             */
/*   Updated: 2022/05/04 13:57:37 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//Holds the hooks for every event controlling the program
void	hook_control(t_data *data)
{
//	mlx_hook(data->win, 3, 0, on_keyup, data);
//	mlx_hook(data->win, 2, 0, on_keydown, data);
//	mlx_hook(data->win, 4, 0, on_mousedown, data);
	mlx_hook(data->win, 17, 0, exit_fractol, data);
}

//Colors the pixel in the coordinates (X, Y) of a given image
void	img_pixel_put(t_data *data, int x, int y, int color)
{
	char	*pixel;

	if (data->px_bits != 32)
		color = mlx_get_color_value(data->mlx, color);
	if (x < WIN_WIDTH && y < WIN_HEIGHT && x >= 0 && y >= 0)
	{
		pixel = data->img_addr + (y * data->line_bytes)
			+ (x * (data->px_bits / 8));
		if (pixel == NULL)
			e_print_exit("Error(1): Bad allocated pixel", data);
		*(unsigned int *)pixel = color;
	}
}
