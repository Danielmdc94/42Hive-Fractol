/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:21:04 by dpalacio          #+#    #+#             */
/*   Updated: 2022/06/03 19:36:39 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//Holds the hooks for every event controlling the program
void	hook_control(t_data *data)
{
	mlx_hook(data->win, 2, 0, on_keydown, data);
	mlx_hook(data->win, 4, 0, on_mousedown, data);
	mlx_hook(data->win, 6, 0, on_mousemove, data);
	mlx_hook(data->win, 17, 0, exit_fractol, data);
	mlx_loop_hook(data->mlx, render_frame, data);
	mlx_loop(data->mlx);
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

//Initializes necesary data for ploting and drawing the fractal
void	data_init(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "fractol");
	data->img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->img_addr = mlx_get_data_addr(data->img, &data->px_bits,
			&data->line_bytes, &data->endian);
	data->mouse_lock = 0;
	data->color_mode = 1;
	fractals_init(data);
}
