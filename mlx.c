/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:21:04 by dpalacio          #+#    #+#             */
/*   Updated: 2022/05/12 11:57:51 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//Holds the hooks for every event controlling the program
void	hook_control(t_data *data)
{
	mlx_hook(data->win, 2, 0, on_keydown, data);
//	mlx_hook(data->win, 3, 0, on_keyup, data);
	mlx_hook(data->win, 4, 0, on_mousedown, data);
//	mlx_hook(data->win, 5, 0, on_mouseup, data);
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

//Initializes necesary data for ploting and drawing the fractal
void	data_init(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "fractol");
	data->img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->img_addr = mlx_get_data_addr(data->img, &data->px_bits,
			&data->line_bytes, &data->endian);
	data->r_min = -2.75;
	data->r_max = -0.25;
	data->i_min = -1.25;
	data->i_max = 1.25;
	data->width = WIN_WIDTH;
	data->height = WIN_HEIGHT;
	data->max_iter = 50;
}

//Chooses the fractal to but put in the window
void	fractal_to_window(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	if (ft_strcmp(data->fractal, "mandelbrot") == 0)
		mandelbrot(data);
	else if (ft_strcmp(data->fractal, "julia") == 0)
		ft_putstr("Here should be Julia");
	else
		e_print_exit("Valid fractals:\n - mandelbrot\n - julia\n", data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
