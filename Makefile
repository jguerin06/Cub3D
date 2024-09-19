# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/19 10:29:40 by jguerin           #+#    #+#              #
#    Updated: 2024/09/19 11:38:12 by jguerin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS =	srcs/ft_check.c \
			srcs/ft_error.c \
			srcs/ft_init.c \
			srcs/ft_map_utils.c \
			srcs/ft_map.c \
			srcs/ft_parsing.c \
			srcs/ft_split.c \
			srcs/ft_utils.c \
			srcs/main.c \
			GNL/get_next_line_utils.c \
			GNL/get_next_line.c

OBJS = $(SRCS:.c=.o)

# ------------------------------ Flags -------------------------------

CC = @gcc -Wall -Wextra -Werror

# ------------------------------ Colors ------------------------------

# Colors

GREY 	 := "\033[1;30m"
RED 	 :=	"\033[1;31m"
GREEN 	 := "\033[1;32m"
YELLOW 	 := "\033[1;33m"
BLUE	 :=	"\033[1;36m"
PURPLE	 :=	"\033[1;35m"
WHITE	 :=	"\033[1;37m"
END		 :=	"\033[0;0m"

# ------------------------------ Messages ------------------------------

MAKE_MESS		= • Make :

FILES_OK		= has been successfully compiled!

FILES_DELETE	= • Clean : please make am fclean to delete cub3d

FCLEAN_DELETE	= • Fclean : cub3D was been successfully deleted!
                                             

# ------------------------------ so_long --------------------------------

all: $(NAME)

bonus : all

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME) MLX42/build/libmlx42.a -I include -lglfw -L /Users/$$USER/.brew/opt/glfw/lib
	@echo ${GREEN}"$(MAKE_MESS) $(NAME) $(FILES_OK)"${END}

# ------------------------------ Rules -----------------------------------

clean:
	@rm -rf ${OBJS}
	
	@echo ${RED}"$(FILES_DELETE)"${END}

fclean: clean 
	@rm -rf $(NAME)
	@echo ${RED}"$(FCLEAN_DELETE)"${END}

re : fclean all
