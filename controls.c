/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 20:17:24 by dpalacio          #+#    #+#             */
/*   Updated: 2022/05/10 20:46:21 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	on_keydown(int key, t_data *data)
{
	if (key == 53)
	{
		exit_fractol(data);
	}

	if (key == 123)
	{
	}
	if (key == 124)
	{
	}
	if (key == 125)
	{
	}
	if (key == 126)
	{
	}
	draw(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	ft_putnbr(key);
	ft_putchar('\n');
	return (1);
}
