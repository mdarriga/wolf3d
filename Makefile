# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdarriga <mdarriga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/29 17:55:37 by mdarriga          #+#    #+#              #
#    Updated: 2015/02/03 14:25:30 by mdarriga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d
CCLIB = -Llibft -lft -L/usr/X11/lib -lmlx -lXext -lX11
CFLAGS = -Wall -Werror -Wextra
CC = gcc

SRC +=	main.c
SRC +=	get_next_line.c
SRC +=	init_var.c
SRC +=	init_var2.c
SRC +=	key_func.c
SRC +=	get_map.c
SRC +=	tools.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/ re
	@$(CC) $(CCLIB) -o $(NAME) $(OBJ) -I /usr/X11/include/X11/x.h

clean:
	@make -C libft clean
	@rm -f $(OBJ)

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
