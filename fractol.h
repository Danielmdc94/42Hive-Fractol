/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:11:18 by dpalacio          #+#    #+#             */
/*   Updated: 2022/06/13 16:33:35 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <math.h>
# include <pthread.h>

/*----RESOLUTION----*/
# define WIN_WIDTH	1000
# define WIN_HEIGHT	1000
# define ZOOM		0.1f

/*------COLORS------*/
# define WHITE		0xFFFFFF
# define BLACK		0x000000
# define RED		0xFF0000
# define BLUE		0x0000FF

/*-STARTING VALUES--*/
typedef struct s_start
{
	long double	r_min;
	long double	r_max;
	long double	i_min;
	long double	i_max;
}				t_start;

/*-------DATA-------*/
typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	int			px_bits;
	int			line_bytes;
	int			endian;
	char		*img_addr;
	int			fractal;
	long double	r_min;
	long double	r_max;
	long double	i_min;
	long double	i_max;
	t_start		start;
	long double	escape;
	int			mouse_x;
	int			mouse_y;
	int			mouse_lock;
	int			max_iter;
	long double	zoom;
	long double	distance;
	int			color_mode;
}				t_data;

/*------THREAD------*/
typedef struct s_thread
{
	t_data	*data;
	int		id;
}				t_thread;

/*------PIXEL-------*/
typedef struct s_pixel
{
	int			x;
	int			y;
	int			iter;
	long double	distance;
}				t_pixel;

/*-------MAIN-------*/
void		e_print_exit(char *e_string, t_data *data);
int			exit_fractol(t_data *data);

/*-------MLX--------*/
void		hook_control(t_data *data);
void		img_pixel_put(t_data *data, int x, int y, int color);
void		data_init(t_data *data);

/*--SCREEN THREADS--*/
void		screen_threads(t_data *data);
int			render_frame(t_data *data);

/*-----FRACTALS-----*/
int			choose_fractal(t_data *data, t_pixel *pixel);

/*--FRACTALS INIT---*/
void		fractals_init(t_data *data);

/*------UTILS-------*/
long double	ft_abscomplex(long double zr, long double zi);
long double	get_distance(t_data *data, long double zr, long double zi);
long double	map_real(int x, t_data *data);
long double	map_imaginary(int y, t_data *data);

/*-----CONTROLS-----*/
int			on_keydown(int key, t_data *data);
int			on_mousedown(int button, int x, int y, t_data *data);
int			on_mousemove(int x, int y, t_data *data);

/*-----KEYBOARD-----*/
void		move_camera(int key, t_data *data);
void		max_iter(int key, t_data *data);
void		change_colors(int key, t_data *data);
void		change_fractal(int key, t_data *data);
void		change_escape(int key, t_data *data);

/*------MOUSE-------*/
void		zoom(int button, int x, int y, t_data *data);
void		modify_complex(int button, int x, int y, t_data *data);
void		mouse_lock(int button, int x, int y, t_data *data);

/*------COLOR-------*/
int			color(t_data *data, t_pixel *pixel);
int			iter_color(t_data *data, int iter);
int			distance_color(t_data *data, long double distance);

#endif
