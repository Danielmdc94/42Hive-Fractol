/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:40:52 by dpalacio          #+#    #+#             */
/*   Updated: 2022/05/06 14:28:56 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	e_print_exit(char *e_string, t_data *data)
{
	ft_putendl(e_string);
	exit_fractol(data);
}

int	exit_fractol(t_data *data)
{
	exit(0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		e_print_exit("Usage: ./fractol <fractol_name>", &data);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, "fractol");
	data.img = mlx_new_image(data.mlx, WIN_WIDTH, WIN_HEIGHT);
	data.img_addr = mlx_get_data_addr(data.img, &data.px_bits,
			&data.line_bytes, &data.endian);
	mandelbrot(data);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	hook_control(&data);
	mlx_loop(data.mlx);
}
