/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel_brot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrajiy <aerrajiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:38:28 by aerrajiy          #+#    #+#             */
/*   Updated: 2023/01/17 23:12:29 by aerrajiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

int	mandelbrot_set( t_vars *vars, int x, int y)
{
	t_complex	c;
	t_complex	z;
	int			iter;
	double		tmp;
	double		zoom;

	zoom = vars->control.zoom;
	z.imag = 0;
	z.real = 0;
	iter = 0;
	c.real = (x - WIDTH / 2) / (0.5 * zoom * WIDTH) + \
	((vars->control.move_x * 3) / WIDTH / 2);
	c.imag = (y - HEIGHT / 2) / (0.5 * zoom * HEIGHT) - \
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
