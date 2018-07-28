/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 15:47:04 by fhong             #+#    #+#             */
/*   Updated: 2018/07/26 11:18:47 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../include/ft_printf.h"

void	handle_flag(char **format, t_arg *args)
{
	if (**format == '-' || **format == '+' || **format == ' ' ||
			**format == '#' || **format == '0')
	{
		ft_strncpy(args->flag, *format, 1);
		(*format)++;
	}
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
				tmp = args->precision;
				args->precision = ft_strjoin(args->precision, buf);
				free(tmp);
				free(buf);
				(*format)++;
			}
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
