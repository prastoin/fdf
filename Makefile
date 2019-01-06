# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amerrouc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/21 16:50:34 by amerrouc          #+#    #+#              #
#    Updated: 2019/01/06 11:39:20 by prastoin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = main.c parser.c

OBJ = $(SRC:.c=.o)

FLAG = -Wall -Wextra -Werror

LIB = libft/libft.a

INC = -I./libft/

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	gcc $(FLAG) $(LIB) $(INC) $(OBJ) -o $(NAME)

$(LIB):
	make -C libft/ fclean
	make -C ./libft/

%.o: %.c
	gcc $(FLAG) $(INC) -o $@ -c $<

clean:
	make -C libft/ clean
	rm -rf $(OBJ)

fclean: clean
	make -C libft/ fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all
