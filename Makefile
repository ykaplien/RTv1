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

NAME = RTv1
SRCS = srcs/main.c\

FLAGS = -Wall -Werror -Wextra
HEADER = fdf.h
OBJS = $(SRCS:.c=.o)

all: $(NAME) 

$(NAME):
	@ make -C libft re
	@ gcc  -lmlx -framework OpenGL -framework AppKit $(SRCS) libft/libft.a -o $(NAME) -lm

%.o:%.c
	@ gcc -o $@ -c $< -I ./libft/

clean:
	@ make -C libft clean

fclean: clean
	@ rm -f $(NAME)
	@ make -C libft fclean

re: fclean all