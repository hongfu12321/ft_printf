/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 21:56:28 by fhong             #+#    #+#             */
/*   Updated: 2018/07/26 23:23:04 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../include/ft_printf.h"

void	print_octal(char flag, uintmax_t nbr, size_t nbr_len, size_t precision, size_t width)
{
	if (flag == '+' || flag == ' ')
	{
		ft_put_char_times(' ', width - precision - 1);
		flag == '+' ? write(1, "+", 1) : write(1, " ", 1);
		ft_put_char_times('0', precision - nbr_len);
		ft_putnbr_base(nbr, "01234567");
	}
	else if (flag == '#')
	{
		ft_put_char_times(' ', width - precision - 1);
		write(1, "0", 1);
		ft_put_char_times('0', precision - nbr_len);
		ft_putnbr_base(nbr, "01234567");
	}
	else
	{
		ft_put_char_times(' ', width - precision);
		ft_put_char_times('0', precision - nbr_len);
		ft_putnbr_base(nbr, "01234567");
	}
}

size_t	handle_octal_flag(t_arg *args, uintmax_t nbr, size_t nbr_len, size_t precision, size_t width)
{
	if (args->flag[0] == '0' && !args->precision)
	{
		ft_put_char_times('0', width - precision);
		ft_putnbr_base(nbr, "01234567");
		return ((width > precision ? width : precision));
	}
	print_octal(args->flag[0], nbr, nbr_len, precision, width);
	if (args->flag[0] == '+' || args->flag[0] == ' ')
		return (width > precision ? width : precision + 1);
	else
	{
		if (args->negative)
			return (width > precision ? width : precision);
		return (width > precision ? width : precision + 1);
	}
}

size_t	handle_octal_width(t_arg *args, uintmax_t nbr, size_t nbr_len, size_t precision)
{
	size_t	width;

	width = ft_atoi((const char *)args->width);
	if (args->flag[0] == '-')
	{
		ft_put_char_times('0', precision - nbr_len);
		ft_putnbr_base(nbr, "01234567");
		ft_put_char_times(' ', width - precision);
	}
	else
		return (handle_octal_flag(args, nbr, nbr_len, precision, width));
	return ((width > precision ? width : precision));
}

size_t	handle_octal(va_list ap, t_arg *args)
{
	uintmax_t	nbr;
	size_t		precision;
	size_t		nbr_len;

	nbr = get_unsigned_nbr_length(ap, args);
	precision = ft_atoi((const char *)args->precision);
	nbr_len = ft_intlen_base(nbr, 8);
	if (precision < nbr_len && args->precision)
		return (handle_octal_width(args, nbr, nbr_len, nbr_len));
	return (handle_octal_width(args, nbr, nbr_len, precision));
}
