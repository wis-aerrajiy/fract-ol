/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_event.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrajiy <aerrajiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:42:35 by aerrajiy          #+#    #+#             */
/*   Updated: 2023/01/19 14:12:41 by aerrajiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

int	keyboard_events(int key, t_vars **vars)
{
	if (key == KEY_ESC)
		exit(0);
	if (key == KEY_LEFT || key == KEY_RIGHT || key == KEY_DOWN || key == KEY_UP)
		make_move(key, vars);
	if (key == JULIA || key == MANDELBROT || key == BURNING_SHIP)
		change_fractal(key, vars);
	if (key == BLUE || key == RED || key == SKY || key == ZERO)
		change_colors(key, vars);
	return (0);
}
