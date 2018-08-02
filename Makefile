# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhong <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/27 16:20:58 by fhong             #+#    #+#              #
#    Updated: 2018/08/02 14:39:05 by fhong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKE = make -C
NAME = libftprintf.a
LIB = libft/
FLAGS = -Wall -Wextra -Werror
CC = gcc
HEADER = -I /include

#When compiling. you need to add your .a lib
CFILES =		src/ft_printf.c\
				src/get_args.c\
				src/get_handle_func.c\
				src/get_nbr_length.c\
				src/tools.c\
				src/is_function.c\
				src/handle/handle_int.c\
				src/handle/handle_char.c\
				src/handle/handle_wchar.c\
				src/handle/handle_str.c\
				src/handle/handle_wstr.c\
				src/handle/handle_hex.c\
				src/handle/handle_ptr.c\
				src/handle/handle_octal.c\
				src/handle/handle_unsigned.c\
				src/handle/handle_escape.c\

#These options are here in case the lib needs to be recompiled.
#LIBM, LIBC, LIBF will run rules re, clean and fclean inside the libft folder
LIBM = $(MAKE) $(LIB)
LIBR = $(MAKE) $(LIB) re
LIBC = $(MAKE) $(LIB) clean
LIBF = $(MAKE) $(LIB) fclean
OBJECTS = $(CFILES:.c=.o)
OBJ_DIR = objects

DFLAGS = $(CFLAGS) -g $(LIBD) $(CFILES) -o
DNAME = $(NAME)_debug
DOBJS = $(CFILES:.c = .o)
# export DRAGS=01.map
all: $(NAME)

$(NAME):
	@$(LIBM)
	@$(CC) $(FLAG) -c $(CFILES) $(HEADER)
	@cp libft/libft.a $(NAME)
	@ar rcs $(NAME) *.o
	@ranlib $(NAME)
	@mkdir $(OBJ_DIR)
	@mv *.o $(OBJ_DIR)
	@echo "\033[33mLib File \"libftprintf.a\" Created\033[0m"

clean:
	@$(LIBC)
	@/bin/rm -rf $(OBJ_DIR)
	@echo "\033[31mft_printf Object File Removed\033[0m"

fclean:
	@$(LIBF)
	@/bin/rm -f $(NAME) *.a
	@/bin/rm -rf $(OBJ_DIR)
	@rm -rf $(NAME)
	@rm -f $(DNAME)
	@rm -rf $(DNAME).dSYM
	@echo "\033[31mft_printf: Removed exacutable & .o files\033[0m"

re: fclean all



debug: $(DNAME)

$(DNAME): fclean
	@$(LIBM)
	$(CC) $(DFLAGS) $(DNAME)
	# lldb $(DNAME) $(DARGS)

# tell Make that they're not associated with files
.PHONY: all clean fclean re debug
