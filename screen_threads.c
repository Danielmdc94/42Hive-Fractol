/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:37:41 by dpalacio          #+#    #+#             */
/*   Updated: 2022/06/13 16:41:24 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	get_pixel(t_thread *structs);
static void	fractal_to_window(t_data *data);
static void	display_ui(t_data *data);

/* Creates 10 threads so that each takes care of rendering 1/10th of the screen
 * by calling get_pixel() */
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

/* Iterates through every pixel(depending on the thread) and applies the
 * correspondent fractal ecuation on it by calling choose_fractal(), then,
 * based on its result, picks a color to put on each pixel by callin color() */
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

/* Called once per frame, clears the window and redraws on it by calling
 * screen_threads() and dislay_ui() */
int	render_frame(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	screen_threads(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	display_ui(data);
	return (1);
}

/* Draws the controls and related info on the screen */
static void	display_ui(t_data *data)
{
	char	*temp;

	temp = ft_itoa(data->max_iter);
	mlx_string_put(data->mlx, data->win, 25, 15, WHITE, "Max. iterations:");
	mlx_string_put(data->mlx, data->win, 195, 15, WHITE, temp);
	free(temp);
	temp = ft_itoa(data->zoom);
	mlx_string_put(data->mlx, data->win, 25, 40, WHITE, "Zoom level:");
	mlx_string_put(data->mlx, data->win, 145, 40, WHITE, temp);
	free(temp);
	temp = ft_itoa(data->escape);
	mlx_string_put(data->mlx, data->win, 25, 65, WHITE, "Escape value:");
	mlx_string_put(data->mlx, data->win, 165, 65, WHITE, temp);
	free(temp);
	mlx_string_put(data->mlx, data->win, 25, 865, WHITE, "Quit program: ESC");
	mlx_string_put(data->mlx, data->win, 25, 890, WHITE, "Move: Dir. arrows");
	mlx_string_put(data->mlx, data->win, 25, 915, WHITE, "Max iter: - & +");
	mlx_string_put(data->mlx, data->win, 25, 940, WHITE, "Escape val: [ & ]");
	mlx_string_put(data->mlx, data->win, 25, 965, WHITE,
		"Color method: 'option'");
	mlx_string_put(data->mlx, data->win, 700, 940, WHITE, "Zoom: Mouse wheel");
	mlx_string_put(data->mlx, data->win, 700, 965, WHITE,
		"Lock Julia: Left click");
	mlx_string_put(data->mlx, data->win, 700, 15, WHITE,
		"Change fractal: 0, 1, 2 & 3");
}
