/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrajiy <aerrajiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:28:22 by aerrajiy          #+#    #+#             */
/*   Updated: 2023/01/19 02:10:51 by aerrajiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	check_colors(t_vars **vars)
{
	static int	s = 0;

	if (s == 3)
		(*vars)->select_color = 265;
	if (s == 2)
		(*vars)->select_color = 259;
	if (s == 1)
		(*vars)->select_color = 257;
	if (s == 0)
		(*vars)->select_color = 256;
	if (s > 3)
		s = 0;
	else
		s++;
}

void	color_system(int x, int y, t_vars *vars, int iteration)
{
	if (iteration == MAX_ITER)
		my_mlx_pixel_put(&vars->img, x, y, BLACK);
	else
		my_mlx_pixel_put(&vars->img, x, y, (vars)->select_color * iteration);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
