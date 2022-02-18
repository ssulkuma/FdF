# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssulkuma <ssulkuma@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 15:11:52 by ssulkuma          #+#    #+#              #
#    Updated: 2022/02/18 19:12:56 by ssulkuma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC_FILES = main.c read.c read_02.c
OBJ_FILES = $(patsubst %.c, %.o, $(SRC_FILES))
HEADERS = -I ./minilibx -I ./libft
LIB = -L ./minilibx -lmlx -L ./libft -lft
FLAGS = -Wall -Wextra -Werror
FRAMEWORK = -framework OpenGL -framework AppKit
GCH = fdf.h.gch

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ_FILES)
	make -C ./libft
	gcc $(FLAGS) -c $(SRC_FILES) $(HEADERS)
	gcc $(FLAGS) -o $(NAME) $(OBJ_FILES) $(LIB) $(FRAMEWORK)

clean:
	make -C ./libft clean
	/bin/rm -f $(OBJ_FILES)
	/bin/rm -f $(GCH)

fclean: clean
	make -C ./libft fclean
	/bin/rm -f $(NAME)
re: fclean all
