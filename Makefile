# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aerrajiy <aerrajiy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/15 21:11:24 by aerrajiy          #+#    #+#              #
#    Updated: 2023/01/17 11:45:02 by aerrajiy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CFLAGS = -Wall -Wextra -Werror
CC = cc
MLX = -lmlx -framework OpenGL -framework AppKit

RM = rm -f

SRC = tools/utils_libft.c tools/utils_mlx.c \
      source/events/move_event.c source/events/zoom_event.c \
	  source/fractal_src/julia.c source/fractal_src/mandel_brot.c source/fractal_src/burning_ship.c \
	  source/fract-ol.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(MLX) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all