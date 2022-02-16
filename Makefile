# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssulkuma <ssulkuma@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 15:11:52 by ssulkuma          #+#    #+#              #
#    Updated: 2022/02/16 11:40:00 by ssulkuma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC_FILES = main.c
OBJ_FILES = $(patsubst %.c, %.o, $(SRC_FILES))
HEADERS = -I ./minilibx -I ./libft
LIB = -L ./minilibx -lmlx -L ./libft -lft
FLAGS = -Wall -Wextra -Werror
FRAMEWORK = -framework OpenGL -framework AppKit

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	make -C ./libft
	gcc -c $(FLAGS) $(SRC_FILES) $(HEADERS)
	gcc $(FLAGS) -o $(NAME) $(OBJ_FILES) $(LIB) $(FRAMEWORK)

clean:
	make -C ./libft clean
	/bin/rm -f $(OBJ_FILES)

fclean: clean
	make -C ./libft fclean
	/bin/rm -f $(NAME)
re: fclean all
