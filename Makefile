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


D_OBJ = ./obj/
D_SRC = ./srcs/
D_INC = ./include/
D_LIB = ./libft/

SRC_NAMES = main.c
HEADERS = $(D_INC)rtv1.h $(D_LIB)libft.h
LIBFT = $(D_LIB)libft.a
SRCS = $(addprefix $(D_SRC), $(SRC_NAMES))
OBJ = $(addprefix $(D_OBJ), $(SRC_NAMES:.c=.o))

L_DIR = -I ./include -I /usr/local/include -I
MLX_FLAGS = -lft -L $(D_LIB) -lmlx -framework OpenGL -framework AppKit
HEAD_FLAGS = -I. -I ./libft/ -I ./include
MATH_FLAGS = -lm
# CC_FLAGS = -Wall -Werror -Wextra -O0


all:	$(NAME) 

$(NAME): $(D_OBJ) $(OBJ) $(HEADERS)
		@ make -C  $(D_LIB
		@ for i in {16..50} ; do echo -en "\e[38;5;${i}m#\e[0m" ; done ; echo && echo -e "\e[32m ---> Libft was built <---" && for i in {16..50} ; do echo -en "\e[38;5;${i}m#\e[0m" ; done ; echo
		@ $(CC) $(CC_FLAGS) $(OBJ) $(L_DIR) -r $(LIBFT) $(MLX_FLAGS) -o $(NAME) $(MATH_FLAGS)

$(D_OBJ):
		@ mkdir $(D_OBJ)

$(D_OBJ)%.o: $(D_SRC)%.c $(HEADERS)
		@ $(CC) $(CC_FLAGS) $(HEAD_FLAGS) -c $< -o $@

clean:
		@ make -C $(D_LIB) clean
		@ rm -rf $(D_OBJ)

fclean:
		@ make -C $(D_LIB) fclean
		@ rm -rf $(D_OBJ)
		@ rm -f $(NAME)

re: fclean all

norm: clean
	norminette $(D_SRC) $(D_INC)