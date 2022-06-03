/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:03:10 by dpalacio          #+#    #+#             */
/*   Updated: 2022/06/03 16:44:08 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	iter_color(t_data *data, int iter)
{
	if (iter == data->max_iter)
		return (BLACK);
	else
		return (iter * RED / 50);
}

int	distance_color(t_data *data)
{
	return (data->distance * 10);
}
