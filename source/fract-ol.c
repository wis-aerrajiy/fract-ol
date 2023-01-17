/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrajiy <aerrajiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 21:16:12 by aerrajiy          #+#    #+#             */
/*   Updated: 2023/01/17 23:11:20 by aerrajiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	run_fractal(t_vars **vars)
{
	int	(*do_fractals[3])(t_vars *vars, int x, int y);
	int	x;
	int	y;

	mlx_clear_window((*vars)->mlx, (*vars)->win);
	do_fractals[0] = &mandelbrot_set;
	do_fractals[1] = &julia_set;
	do_fractals[2] = &burningship_set;
	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			(*do_fractals[(*vars)->selected_fractal])(*vars, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window((*vars)->mlx, (*vars)->win, (*vars)->img.img, 0, 0);
	return (0);
}

void	we_dont_do_that_here(void)
{
	ft_putstr_fd("\x1B[31m WIS [Usage ] :~ \x1B[34m./fract-ol \
[ fractal name ]\n", 1);
	ft_putstr_fd("\x1B[31m WIS [types ] :~ \x1B[32m{ [mandelbrot] | \
[burningship] or [julia] }\n", 1);
	exit(0);
}

void	init(t_vars **vars)
{
	(*vars)->control.zoom_scale = 1;
	(*vars)->control.move_x = 0;
	(*vars)->control.move_y = 0;
	(*vars)->control.zoom = 0.7;
	(*vars)->selected_color = 0xCCCCFF;
	(*vars)->mlx = mlx_init();
	(*vars)->win = mlx_new_window((*vars)->mlx, WIDTH, HEIGHT, "fract-ol");
	(*vars)->img.img = mlx_new_image((*vars)->mlx, WIDTH, HEIGHT);
	(*vars)->img.addr = mlx_get_data_addr(
			(*vars)->img.img,
			&(*vars)->img.bits_per_pixel,
			&(*vars)->img.line_length,
			&(*vars)->img.endian
			);
}

void	check_and_init(t_vars **vars)
{
	char	*fractals[3];

	fractals[0] = "mandelbrot";
	fractals[1] = "julia";
	fractals[2] = "burningship";
	if ((*vars)->argc < 2)
		we_dont_do_that_here();
	(*vars)->control.fixed_r = -0.70176;
	(*vars)->control.fixed_i = -0.3842;
	if (ft_strcmp((*vars)->argv[1], fractals[0]))
		(init(vars), (*vars)->selected_fractal = 0);
	else if (ft_strcmp((*vars)->argv[1], fractals[1]))
		(init(vars), (*vars)->selected_fractal = 1);
	else if (ft_strcmp((*vars)->argv[1], fractals[2]))
		(init(vars), (*vars)->selected_fractal = 2);
	else
		we_dont_do_that_here();
}

int	main(int argc, char *argv[])
{
	t_vars	*vars;

	vars = (t_vars *)malloc(sizeof(t_vars));
	vars->argc = argc;
	vars->argv = argv;
	check_and_init(&vars);
	mlx_hook(vars->win, 2, 1L << 0, keyboard_events, &vars);
	mlx_hook(vars->win, 6, 1L << 2, mouse_cursor, &vars);
	mlx_hook(vars->win, 17, 1L << 0, close_it, &vars);
	mlx_mouse_hook(vars->win, mouse_events, &vars);
	mlx_loop_hook(vars->mlx, run_fractal, &vars);
	mlx_loop(vars->mlx);
	return (0);
}
