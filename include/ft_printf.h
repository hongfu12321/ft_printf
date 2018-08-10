/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 23:00:59 by fhong             #+#    #+#             */
/*   Updated: 2018/08/09 22:53:29 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>

# define HASH		args->hash
# define MINUS		args->minus
# define PLUS		args->plus
# define SPACE		args->space
# define ZERO		args->zero
# define FLAG		HASH + MINUS + PLUS + SPACE + ZERO
# define NEGATIVE	args->negative
# define WIDTH		args->width
# define PRECISION	args->precision
# define LENGTH		args->length
# define SPECIFIER	args->specifier
# define TRUE(x, y)	x > y ? x - y : 0

typedef struct		s_arg
{
	int				hash;
	int				minus;
	int				plus;
	int				space;
	int				zero;
	int				width;
	int				precision;
	char			length;
	int				negative;
	char			specifier;
}					t_arg;

typedef size_t		(*t_func)(va_list ap, t_arg *args);

/*
**	main.c
*/

size_t				get_args(va_list ap, char **format);
size_t				print_format(va_list args, char *format, size_t char_size);
size_t				ft_printf(const char *format, ...);

/*
** tools.c
*/

void				initial_args(t_arg *args);
void				print_args(t_arg *args);
void				free_args(t_arg *args);
void				reset_flag(t_arg *args);

/*
** is_function.c
*/

int					is_specifier(char c);
int					is_length(char c);
int					is_character(char c);

/*
** get_args.c
*/

void				handle_flag(char **format, t_arg *args);
void				handle_width(char **format, t_arg *args, va_list ap);
void				handle_precision(char **format, t_arg *args, va_list ap);
void				handle_length(char **format, t_arg *args);

/*
** get_handle_finc.c
*/

size_t				handle_specifier(char **format, t_arg *args, va_list ap);

/*
** get_nbr_length.c
*/

intmax_t			get_signed_nbr_length(va_list ap, t_arg *args);
uintmax_t			get_unsigned_nbr_length(va_list ap, t_arg *args);

/*
** handle
*/

size_t				handle_str(va_list ap, t_arg *args);
size_t				handle_wstr(va_list ap, t_arg *args);
size_t				handle_char(va_list ap, t_arg *args);
size_t				handle_wchar(va_list ap, t_arg *args);
size_t				handle_int(va_list ap, t_arg *args);
size_t				handle_unsigned(va_list ap, t_arg *args);
size_t				handle_escape(va_list ap, t_arg *args);
size_t				handle_octal(va_list ap, t_arg *args);
size_t				handle_hex(va_list ap, t_arg *args);
size_t				handle_ptr(va_list ap, t_arg *args);

# define BLACK		"\033[0;30m"
# define BLUE		"\033[0;34m"
# define CYAN		"\033[1;36m"
# define DARKYELLOW	"\033[0;33m"
# define GREEN		"\033[0;32m"
# define GREY		"\033[1;30m"
# define LAVENDER	"\033[1;35m"
# define LIGHTBLUE	"\033[0;36m"
# define LIGHTGREY	"\033[0;37m"
# define LIME		"\033[1;32m"
# define MAGENTA	"\033[0;35m"
# define PINK		"\033[1;31m"
# define PURPLE		"\033[1;34m"
# define RED		"\033[0;31m"
# define UNDERLINE	"\033[4m"
# define WHITE		"\033[1;37m"
# define YELLOW		"\033[1;33m"
# define RESET		"\033[0m"

#endif
