# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anabaoui <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/20 01:58:59 by anabaoui          #+#    #+#              #
#    Updated: 2020/01/20 18:50:06 by anabaoui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC_PATH = src

SRC_NAME = main.c fractol.c keys_hook.c mandelbrot.c \
		   julia.c ship.c quatro.c penta.c \
		instruction.c guide_btn.c mouse_hook.c

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ = $(addprefix $(SRC_PATH)/,$(OBJ_NAME))

CC = gcc -Wall -Wextra -Werror

LIB = -L ./libft -lft -lpthread -L ./miniLibX -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME) : $(OBJ) lib_ft
	@$(CC) $(LIB) $(OBJ) -o $(NAME)

lib_ft :
	@make -C libft

$(SRC_PATH)/%.o : $(SRC_PATH)/%.c
	@$(CC) -c $< -o $@
	@echo "Fractol : $< \033[1;32mDone\033[0m"

clean :
	@make clean -C libft
	@rm -rf $(OBJ)

fclean : clean
	@make fclean -C libft
	@rm -rf $(NAME)

re : fclean all
