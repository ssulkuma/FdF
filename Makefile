# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssulkuma <ssulkuma@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 15:11:52 by ssulkuma          #+#    #+#              #
#    Updated: 2022/02/15 17:13:31 by ssulkuma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC_FILES = main.c
OBJ_FILES = $(patsubst %.c, %.o, $(SRC_FILES))
HEADERS = -I ./minilibx
LIB = -L ./minilibx -lmlx
FLAGS = -Wall -Wextra -Werror
FRAMEWORK = -framework OpenGL -framework AppKit

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	gcc -c $(FLAGS) $(SRC_FILES) $(HEADERS)
	gcc $(FLAGS) -o $(NAME) $(OBJ_FILES) $(LIB) $(FRAMEWORK)

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)
re: fclean all
