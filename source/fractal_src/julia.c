/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrajiy <aerrajiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:39:47 by aerrajiy          #+#    #+#             */
/*   Updated: 2023/01/19 14:04:04 by aerrajiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

int	julia_set( t_vars *vars, int x, int y)
{
	t_complex	c;
	t_complex	z;
	int			iter;
	double		tmp;
	double		zoom;

	zoom = vars->control.zoom;
	c.imag = vars->control.fixed_i;
	c.real = vars->control.fixed_r;
	iter = 0;
	z.real = (x - WIDTH / 2) / (0.5 * zoom * WIDTH) + \
	((vars->control.move_x * 3) / WIDTH / 2);
	z.imag = (y - HEIGHT / 2) / (0.5 * zoom * HEIGHT) - \
	((vars->control.move_y * 3) / HEIGHT / 2);
	while (z.real * z.real + z.imag * z.imag < 4 && iter < MAX_ITER)
	{
		tmp = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = 2 * z.real * z.imag + c.imag;
		z.real = tmp;
		iter++;
	}
	color_system(x, y, vars, iter);
	return (0);
}
