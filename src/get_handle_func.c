/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_handle_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 19:02:53 by fhong             #+#    #+#             */
/*   Updated: 2018/07/30 23:12:52 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../include/ft_printf.h"

static void	get_handle_func(t_func *func)
{
	func['s'] = &handle_str;
	func['S'] = &handle_wstr;
	func['p'] = &handle_ptr;
	func['d'] = &handle_int;
	func['D'] = &handle_int;
	func['i'] = &handle_int;
	func['o'] = &handle_octal;
	func['O'] = &handle_octal;
	func['u'] = &handle_unsigned;
	func['U'] = &handle_unsigned;
	func['x'] = &handle_hex;
	func['X'] = &handle_hex;
	func['c'] = &handle_char;
	func['Z'] = &handle_char;
	func['C'] = &handle_wchar;
	func['%'] = &handle_escape;
}

size_t		handle_specifier(char **format, t_arg *args, va_list ap)
{
	static t_func	funcs[128] = {0};
	char			c;

	c = **format;
	args->specifier[0] = c;
	if (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' ||
		c == 'i' || c == 'o' || c == 'O' || c == 'u' || c == 'U' ||
		c == 'x' || c == 'X' || c == 'c' || c == 'C' || c == '%')
		get_handle_func(funcs);
	else
	{
		if (c == '+' || c == '-' || c == '0' || c == ' ' || c == '#' ||
			c == '.' || c == 'h' || c == 'l' || c == 'j' || c == 'z')
			return (-1);
		else
			return (0);
	}
	(*format)++;
	return (funcs[(int)c](ap, args));
}
