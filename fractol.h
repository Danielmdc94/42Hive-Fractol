/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:11:18 by dpalacio          #+#    #+#             */
/*   Updated: 2022/05/06 14:23:47 by dpalacio         ###   ########.fr       */
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
# define RED		0xFF0000
# define GREEN		0x00FF00
# define BLUE		0x0000FF
# define YELLOW		0xFFFF00
# define CYAN		0x00FFFF
# define MAGENTA	0xFF00FF

/*----PLOT WINDOW---*/
# define R_MIN = -2
# define R_MAX = 1
# define I_MIN = -1
# define I_MAX = 1
# define MAXITER = 100

/*-------DATA-------*/
typedef struct s_data{
	void	*mlx;
	void	*win;
	void	*img;
	int		px_bits;
	int		line_bytes;
	int		endian;
	char	*img_addr;
}				t_data;

/*-------DATA-------*/
void	e_print_exit(char *e_string, t_data *data);
int		exit_fractol(t_data *data);

/*-------MLX--------*/
void	hook_control(t_data *data);
void	img_pixel_put(t_data *data, int x, int y, int color);

void	mandelbrot(t_data data);

#endif
