/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrajiy <aerrajiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:28:22 by aerrajiy          #+#    #+#             */
/*   Updated: 2023/01/17 23:14:24 by aerrajiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	color_system(int x, int y, t_vars *vars, int iteration)
{
	if (iteration == MAX_ITER)
		my_mlx_pixel_put(&vars->img, x, y, BLACK);
	else
		my_mlx_pixel_put(&vars->img, x, y, (vars)->selected_color * iteration);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
