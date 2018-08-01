/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 15:47:04 by fhong             #+#    #+#             */
/*   Updated: 2018/08/01 15:37:41 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../include/ft_printf.h"

int		varified_flag(char flag, t_arg *args)
{
	if (flag == '#')
		HASH = 2;
	else if (flag == '-')
		MINUS = 1;
	else if (flag == '+')
		PLUS = 1;
	else if (flag == ' ')
		SPACE = 1;
	else if (flag == '0')
		ZERO = 1;
	if (flag == '#' || flag == '-' || flag == '+' || flag == ' ' || flag == '0')
		return (1);
	return (0);
}

void	handle_flag(char **format, t_arg *args)
{
	while (varified_flag(**format, args))
		(*format)++;
}

void	handle_width(char **format, t_arg *args, va_list ap)
{
	char *tmp;
	char *buf;

	if (**format == '*')
	{
		tmp = args->width;
		args->width = ft_strjoin(args->width, va_arg(ap, char *));
		free(tmp);
		(*format)++;
	}
	else
		while (ft_isdigit(**format))
		{
			buf = ft_strnew(1);
			ft_strncpy(buf, *format, 1);
			tmp = args->width;
			args->width = ft_strjoin(args->width, buf);
			free(tmp);
			free(buf);
			(*format)++;
		}
}

void	handle_precision(char **format, t_arg *args, va_list ap)
{
	char *tmp;
	char *buf;

	if (**format == '.')
	{
		(*format)++;
		if (**format == '*')
		{
			args->precision = ft_strjoin(args->precision, va_arg(ap, char *));
			(*format)++;
		}
		else if (ft_isdigit(**format))
			while (ft_isdigit(**format))
			{
				tmp = args->precision;
				buf = ft_strnew(1);
				ft_strncpy(buf, *format, 1);
				args->precision = ft_strjoin(args->precision, buf);
				free(tmp);
				free(buf);
				(*format)++;
			}
		else
			args->precision[0] = '#';
	}
}

void	handle_length(char **format, t_arg *args)
{
	if (**format == 'h' || **format == 'l' || **format == 'j' ||
			**format == 'z' || **format == 't' || **format == 'L')
	{
		args->length[0] = **format;
		(*format)++;
	}
	if (args->length[0] == 'l' && **format == 'l')
	{
		args->length[1] = **format;
		(*format)++;
	}
	else if (args->length[0] == 'h' && **format == 'h')
	{
		args->length[1] = **format;
		(*format)++;
	}
}
