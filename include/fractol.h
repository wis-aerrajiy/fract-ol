/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrajiy <aerrajiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 20:30:22 by aerrajiy          #+#    #+#             */
/*   Updated: 2023/01/17 22:46:13 by aerrajiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define BLACK 0x000000
# define WHITE 0xFFFFFF

# define WIDTH 1000
# define HEIGHT 1000
# define MAX_ITER 100

# define KEY_ESC 53
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124

typedef struct s_complex
{
	double	real;
	double	imag;
}	t_complex;

typedef struct s_control
{
	double	move_scale;
	double	zoom_scale;

	double	move_x;
	double	move_y;
	double	zoom;

	double	fixed_r;
	double	fixed_i;
}	t_control;

typedef struct s_data
{
	int		x_img;
	int		y_img;
	void	*background;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_vars
{
	int			argc;
	char		**argv;
	int			selected_fractal;
	int			selected_color;
	void		*mlx;
	void		*win;
	t_data		img;
	t_control	control;
}	t_vars;

int		ft_strcmp(const char *s1, const char *s2);
void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(const char *str);
double	ft_atof(char *str);
char	*find_dotes(char *str);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	color_system(int x, int y, t_vars *vars, int iter);

int		burningship_set( t_vars *vars, int x, int y);
int		mandelbrot_set( t_vars *vars, int x, int y);
int		julia_set( t_vars *vars, int x, int y);

int		keyboard_events(int key, t_vars **vars);
int		mouse_events(int key, int x, int y, t_vars **vars);
int		mouse_cursor(int x, int y, t_vars **vars);
int		close_it(t_vars *vars);

#endif