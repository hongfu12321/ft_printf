# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhong <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/02 10:18:57 by fhong             #+#    #+#              #
#    Updated: 2018/07/27 16:30:54 by fhong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc -c
AR = ar rc
W = -W -Wall -Wextra -Werror
SRC = *.c
OBJ = *.o

all: $(NAME)

$(NAME):
	$(CC) $(W) $(SRC)
	$(AR) $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
