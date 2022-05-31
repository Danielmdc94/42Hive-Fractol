/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:37:41 by dpalacio          #+#    #+#             */
/*   Updated: 2022/05/31 19:59:29 by dpalacio         ###   ########.fr       */
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
	int	x;
	int	y;
	int	iter;

	x = 100 * structs->id;
	y = 0;
	iter = 0;
	while (x < 100 * (structs->id + 1))
	{
		while (y < WIN_HEIGHT)
		{
			iter = choose_fractal(structs->data, x, y, iter);
			img_pixel_put(structs->data, x, y, iter_color(structs->data, iter));
			iter = 0;
			y++;
		}
		y = 0;
		x++;
	}
}

void	fractal_to_window(t_data *data)
{
	char	*temp;

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
