/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrajiy <aerrajiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:42:35 by aerrajiy          #+#    #+#             */
/*   Updated: 2023/01/17 23:00:44 by aerrajiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

int	close_it(t_vars *vars)
{
	(void)vars;
	exit(0);
}

int	keyboard_events(int key, t_vars **vars)
{
	printf("key: %d", key);
	(*vars)->control.move_scale = 30 / (*vars)->control.zoom;
	if (key == 53)
		exit(0);
	if (key == 11)
		(*vars)->selected_color = 265;
	if (key == 5)
		(*vars)->selected_color = 256;
	if (key == 15)
		(*vars)->selected_color = 0xFF3A00;
	if (key == 38)
		(*vars)->selected_fractal = 1;
	if (key == 35)
		(*vars)->selected_fractal = 2;
	if (key == 46)
		(*vars)->selected_fractal = 0;
	if (key == 123)
		(*vars)->control.move_x -= (*vars)->control.move_scale;
	if (key == 124)
		(*vars)->control.move_x += (*vars)->control.move_scale;
	if (key == 125)
		(*vars)->control.move_y += (*vars)->control.move_scale;
	if (key == 126)
		(*vars)->control.move_y -= (*vars)->control.move_scale;
	return (0);
}
