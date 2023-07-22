/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrajiy <aerrajiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:41:21 by aerrajiy          #+#    #+#             */
/*   Updated: 2023/01/19 17:47:12 by aerrajiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

int	mouse_cursor(int x, int y, t_vars **vars)
{
	if (x >= 0 && x <= WIDTH && y >= 0 && y <= HEIGHT && (*vars)->julia_move)
	{
		(*vars)->control.fixed_i = (double) y / HEIGHT * 2 - 1;
		(*vars)->control.fixed_r = (double) x / WIDTH * 2 - 1;
	}
	return (0);
}

int	mouse_events(int key, int x, int y, t_vars **vars)
{
	(void)x;
	(void)y;
	(*vars)->control.zoom_scale = 2 * ((*vars)->control.zoom / 10);
	if (key == 4)
		(*vars)->control.zoom = ((*vars)->control.zoom + \
		(*vars)->control.zoom_scale);
	if (key == 5)
		(*vars)->control.zoom = ((*vars)->control.zoom - \
		(*vars)->control.zoom_scale);
	if (key == 3)
	{
		(*vars)->control.zoom = 0.5;
		(*vars)->control.move_x = -250;
		(*vars)->control.move_y = 0;
	}
	if (key == 2)
	{
		if ((*vars)->julia_move)
			(*vars)->julia_move = 0;
		else
			(*vars)->julia_move = 1;
	}
	return (0);
}
