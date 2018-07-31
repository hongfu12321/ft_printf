/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 13:15:46 by fhong             #+#    #+#             */
/*   Updated: 2018/07/31 00:49:11 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../include/ft_printf.h"

size_t	get_args(va_list ap, char **format)
{
	size_t	args_len;
	t_arg	*args;

	if (!(args = (t_arg *)malloc(sizeof(t_arg) * 1)))
		return (-1);
	initial_args(args);
	while (**format)
	{
		if (**format == '+' || **format == '-' || **format == '#'
				|| **format == ' ' || **format == '0')
			handle_flag(format, args);
		else if (ft_isdigit(**format))
			handle_width(format, args, ap);
		else if (**format == '.')
			handle_precision(format, args, ap);
		else if (is_specifier(**format))
			break;
		else
			handle_length(format, args);
	}
	args_len = handle_specifier(format, args, ap);
	free_args(args);
	return (args_len);
}

size_t	print_format(va_list ap, char *format, size_t char_size)
{
	char	*percent;
	size_t	args_len;

	if (!*format)
		return (char_size);
	if (!(percent = ft_strchr(format, '%')))
	{
		ft_putstr(format);
		return (char_size + ft_strlen(format));
	}
	else if(percent > format)
	{
		ft_putnstr(format, percent - format);
		return (print_format(ap, percent, char_size + (percent - format)));
	}
	else
	{
		format++;
		if ((args_len = get_args(ap, &format)) == (size_t)(-1))
			return (0);
		return (print_format(ap, format, char_size + args_len));
	}
}

size_t	ft_printf(const char *format, ...)
{
	va_list args;
	size_t	ret;

	va_start(args, format);
	ret = print_format(args, (char *)format, 0);
	va_end(args);
	return (ret);
}
