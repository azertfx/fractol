# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anabaoui <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/20 01:58:59 by anabaoui          #+#    #+#              #
#    Updated: 2019/11/20 02:00:13 by anabaoui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC_PATH = src

SRC_NAME = main.c fractol.c

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ = $(addprefix $(SRC_PATH)/,$(OBJ_NAME))

CC = gcc -Wall -Wextra -Werror

LIB = -L ./libft -lft -L ./miniLibX -lmlx -framework OpenGL -framework AppKit

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
