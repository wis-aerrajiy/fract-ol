/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrajiy <aerrajiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 20:30:22 by aerrajiy          #+#    #+#             */
/*   Updated: 2023/01/19 18:36:00 by aerrajiy         ###   ########.fr       */
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
# define BLUE 11
# define RED 5
# define SKY 15

# define WIDTH 1000
# define HEIGHT 1000
# define MAX_ITER 100

# define KEY_ESC 53
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_RIGHT 123
# define KEY_LEFT 124
# define JULIA 38
# define MANDELBROT 35
# define BURNING_SHIP 46
# define ZERO 82

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
	int			julia_move;
	int			argc;
	char		**argv;
	int			selected_fractal;
	int			select_color;
	int			color_m;
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
void	check_colors(t_vars **vars);

int		burningship_set( t_vars *vars, int x, int y);
int		mandelbrot_set( t_vars *vars, int x, int y);
int		julia_set( t_vars *vars, int x, int y);

int		keyboard_events(int key, t_vars **vars);
void	make_move(int key, t_vars **vars);
void	change_colors(int key, t_vars **vars);
void	change_fractal(int key, t_vars **vars);
void	set_data_to(int *data1, int value, int *data2, int value2);

int		mouse_events(int key, int x, int y, t_vars **vars);
int		mouse_cursor(int x, int y, t_vars **vars);
int		close_it(t_vars *vars);

#endif