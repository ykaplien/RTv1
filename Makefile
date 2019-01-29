#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykaplien <ykaplien@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/10 15:12:42 by ykaplien          #+#    #+#              #
#    Updated: 2018/12/10 15:12:44 by ykaplien         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc
NAME = RTv1
MATH_FLAGS = -lm
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
# CC_FLAGS = -Wall -Werror -Wextra
OBJ_DIR = ./obj/
INC_DIR = ./inc/

SRC_NAMES = main.c
LIBFT = ./libft/libft.a
SRCS = $(addprefix ./srcs/, $(SRC_NAMES))
OBJ = $(SRCS:%.o=%.c)


all:	$(NAME) 

$(NAME): $(OBJ) $(LIBFT)
			$(CC) $(CC_FLAGS) $(OBJ) -I ./inc -I /usr/local/include -I -r $(LIBFT) -L /usr/local/lib $(MLX_FLAGS) -o $(NAME) $(MATH_FLAGS)
			@echo "\033[35;1m• \033[0mCompilation $(NAME) ...\033[55G\c" 
			@echo "\033[37;1m[\033[32mDONE!\033[37m]\033[0m"

$(OBJ_DIR)%.o:%.c $(LIBFT) $(INC_DIR)rtv1.h
			$(CC) $(CC_FLAGS) -o $@ -c $< $(HEADERS)
			@echo "\033[35;1m• \033[0mCreating object files ...\033[55G\c" 
			@echo "\033[37;1m[\033[32mDONE!\033[37m]\033[0m"

$(LIBFT):
			make -C $(LIBFT_DIR)

clean:
			rm -f $(OBJ)
			make clean -C $(LIBFT_DIR)
			@echo "\033[35;1m• \033[0mRemoving object files ...\033[55G\c" 
			@echo "\033[37;1m[\033[32mDONE!\033[37m]\033[0m"

fclean: clean
			rm -f $(NAME)
			make fclean -C $(LIBFT_DIR)
			@echo "\033[35;1m• \033[0mRemoving $(NAME) ...\033[55G\c"
			@echo "\033[37;1m[\033[32mDONE!\033[37m]\033[0m"

re: fclean all