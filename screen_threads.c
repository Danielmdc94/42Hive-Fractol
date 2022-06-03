/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:37:41 by dpalacio          #+#    #+#             */
/*   Updated: 2022/06/03 19:51:39 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	get_pixel(t_thread *structs);

void	screen_threads(t_data *data)
{
	pthread_t	threads[10];
	t_thread	structs[10];
	int			id;

	id = 0;
	while (id < 10)
	{
		structs[id].id = id;
		structs[id].data = data;
		pthread_create(&threads[id], NULL, (void *)get_pixel,
			(void *)&structs[id]);
		id++;
	}
	while (id >= 0)
	{
		pthread_join(threads[id], NULL);
		id--;
	}
}

static void	get_pixel(t_thread *structs)
{
	t_pixel	pixel;

	pixel.x = 100 * structs->id;
	pixel.y = 0;
	pixel.iter = 0;
	pixel.distance = 0;
	while (pixel.x < 100 * (structs->id + 1))
	{
		while (pixel.y < WIN_HEIGHT)
		{
			choose_fractal(structs->data, &pixel);
			img_pixel_put(structs->data, pixel.x, pixel.y,
				color(structs->data, &pixel));
			pixel.iter = 0;
			pixel.y++;
		}
		pixel.y = 0;
		pixel.x++;
	}
}

void	fractal_to_window(t_data *data)
{
	char	*temp;

	mlx_clear_window(data->mlx, data->win);
	screen_threads(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	temp = ft_itoa(data->max_iter);
	mlx_string_put(data->mlx, data->win, 25, 15, WHITE, temp);
	free(temp);
	temp = ft_itoa(data->zoom);
	mlx_string_put(data->mlx, data->win, 25, 40, WHITE, temp);
	free(temp);
}

int	render_frame(t_data *data)
{
	fractal_to_window(data);
	return (1);
}
