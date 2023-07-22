/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrajiy <aerrajiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:09:26 by aerrajiy          #+#    #+#             */
/*   Updated: 2023/01/19 17:37:53 by aerrajiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

int	close_it(t_vars *vars)
{
	(void)vars;
	exit(0);
}

void	set_data_to(int *data1, int value, int *data2, int value2)
{
	*data1 = value;
	*data2 = value2;
}

void	change_fractal(int key, t_vars **vars)
{
	if (key == JULIA)
		(*vars)->selected_fractal = 1;
	if (key == MANDELBROT)
		(*vars)->selected_fractal = 2;
	if (key == BURNING_SHIP)
		(*vars)->selected_fractal = 0;
}

void	change_colors(int key, t_vars **vars)
{
	if (key == ZERO)
		(*vars)->color_m = 0;
	if (key == BLUE)
		set_data_to(&((*vars)->select_color), 265, &((*vars)->color_m), 1);
		(((*vars)->select_color = 265));
	if (key == RED)
		set_data_to(&((*vars)->select_color), 256, &((*vars)->color_m), 1);
	if (key == SKY)
		set_data_to(&((*vars)->select_color), 256 * \
		256 * 265, &((*vars)->color_m), 1);
}

void	make_move(int key, t_vars **vars)
{
	(*vars)->control.move_scale = 30 / (*vars)->control.zoom;
	if (key == KEY_LEFT)
		(*vars)->control.move_x -= (*vars)->control.move_scale;
	if (key == KEY_RIGHT)
		(*vars)->control.move_x += (*vars)->control.move_scale;
	if (key == KEY_DOWN)
		(*vars)->control.move_y += (*vars)->control.move_scale;
	if (key == KEY_UP)
		(*vars)->control.move_y -= (*vars)->control.move_scale;
}
