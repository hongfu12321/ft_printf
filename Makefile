# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhong <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/27 16:20:58 by fhong             #+#    #+#              #
#    Updated: 2018/07/27 18:23:09 by fhong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = ft_printf
W = -Wall -Wextra -Werror
LIBFT_INCLUDE = ./libft/libft.h
FT_PRINTF_INCLUDE = ./include/ft_printf.h
SRC = ./libft/*.c \
	  ./src/*.c \
	  ./src/handle/*.c \

OBJ = *.o

all: $(NAME)
$(NAME):
	make -C libft
	gcc -o $(NAME) $(W) $(SRC) -Llibft -lft -I ft_printf.h

clean:
	make clean -C libft
	/bin/rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	/bin/rm -f $(NAME)

re: fclean all
.PHONY: all clean fclean re
