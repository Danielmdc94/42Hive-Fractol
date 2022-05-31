/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:03:10 by dpalacio          #+#    #+#             */
/*   Updated: 2022/05/30 14:17:54 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	iter_color(t_data *data, int iter)
{
	if (iter == data->max_iter)
		data->color = BLACK;
	else
		data->color = iter * RED / 50;
	return (1);
}

int	distance_color(t_data *data)
{
	return (1);
}
