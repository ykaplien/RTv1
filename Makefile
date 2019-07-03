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

CFLAGS		= -Wall -Wextra -Werror
NAME		= RTv1
SRC_NAME 	= main.c \
				main2.c \
				main_process.c \
				parse.c \
				parse2.c \
				parse3.c \
				parse4.c \
				parse5.c \
				parse6.c \
				parse7.c \
				parse8.c \
				parse9.c \
				tools.c \
				tools2.c \
				vector_operations.c \
				vector_operations2.c \
				main_process.c \
				main_process2.c \
				main_process3.c \
				fig_data_parse.c \
				fig_perpendicular.c


LIBFT_DIR	= ./libft/
LIBFT		= ./libft/libft.a
SRC			=$(addprefix ./srcs/, $(SRC_NAME))
OBJ			= $(SRC:%.c=%.o)

.PHONY: norm all re clean fclean

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	gcc $(CFLAGS) $(OBJ) -I ./includes -I /usr/local/include -I -r $(LIBFT) -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit -o $(NAME) -lm

%.o:%.c $(LIBFT) ./includes/rtv1.h
	gcc $(CFLAGS) -c $< -o $@ -I ./includes

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all