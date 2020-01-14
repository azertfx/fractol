# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anabaoui <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/20 01:58:59 by anabaoui          #+#    #+#              #
#    Updated: 2020/01/13 18:06:10 by anabaoui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC_PATH = src

SRC_NAME = main.c fractol.c keys_hook.c mandelbrot.c \
		   julia.c ship.c quatro.c penta.c

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ = $(addprefix $(SRC_PATH)/,$(OBJ_NAME))

CC = gcc -Wall -Wextra -Werror

LIB = -L ./libft -lft -lpthread -L ./miniLibX -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	$(CC) $(LIB) $(OBJ) -o $(NAME)

$(SRC_PATH)/%.o : $(SRC_PATH)/%.c
	$(CC) -c $< -o $@

clean:
	make clean -C libft
	rm -rf $(OBJ)

fclean: clean
	make fclean -C libft
	rm -rf $(NAME)

re: fclean all
