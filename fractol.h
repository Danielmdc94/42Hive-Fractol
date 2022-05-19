/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:11:18 by dpalacio          #+#    #+#             */
/*   Updated: 2022/05/19 20:33:15 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "get_next_line.h"
# include "mlx.h"
# include <math.h>
# include <fcntl.h>

/*----RESOLUTION----*/
# define WIN_WIDTH	1920
# define WIN_HEIGHT	1080

/*------COLORS------*/
# define WHITE		0xFFFFFF
# define BLACK		0x000000
# define RED		0xFF0000
# define GREEN		0x00FF00
# define BLUE		0x0000FF
# define YELLOW		0xFFFF00
# define CYAN		0x00FFFF
# define MAGENTA	0xFF00FF

/*-------DATA-------*/
typedef struct s_data{
	void	*mlx;
	void	*win;
	void	*img;
	int		px_bits;
	int		line_bytes;
	int		endian;
	char	*img_addr;
	char	*fractal;
	double	r_min;
	double	r_max;
	double	i_min;
	double	i_max;
	int		mouse_x;
	int		mouse_y;
	int		width;
	int		height;
	int		max_iter;
	double	zoom;
	double	distance;
	int		color;

}				t_data;

/*-------DATA-------*/
void	e_print_exit(char *e_string, t_data *data);
int		exit_fractol(t_data *data);

/*-------MLX--------*/
void	hook_control(t_data *data);
void	img_pixel_put(t_data *data, int x, int y, int color);
void	data_init(t_data *data);
void	fractal_to_window(t_data *data);
int		render_frame(t_data *data);

/*----MANDELBROT----*/
void	mandelbrot(t_data *data);
double	map_imaginary(int y, t_data *data);
double	map_real(int x, t_data *data);

/*----MANDELBROT----*/
void	julia(t_data *data);
/*-----CONTROLS-----*/
int		on_keydown(int key, t_data *data);
int		on_mousedown(int button, int x, int y, t_data *data);
int		on_mousemove(int x, int y, t_data *data);

/*-----KEYBOARD-----*/
void	move_camera(int key, t_data *data);
void	max_iter(int key, t_data *data);

/*------MOUSE-------*/
void	zoom(int button, int x, int y,  t_data *data);

#endif
