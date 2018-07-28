/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 22:06:34 by fhong             #+#    #+#             */
/*   Updated: 2018/07/27 21:09:20 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../include/ft_printf.h"

void	hex_output(uintmax_t nbr, char specifier)
{
	if (specifier == 'x')
		ft_putnbr_base(nbr, "0123456789abcdef");
	else
		ft_putnbr_base(nbr, "0123456789ABCDEF");
}

void	print_hex(t_arg *args, uintmax_t nbr, size_t nbr_len, size_t precision, size_t width)
{
	if (args->flag[0] == '+' || args->flag[0] == ' ')
	{
		ft_put_char_times(' ', width - precision - 1);
		args->flag[0] == '+' ? write(1, "+", 1) : write(1, " ", 1);
	}
	else if (args->flag[0] == '#')
	{
		ft_put_char_times(' ', width - precision - 2);
		args->specifier[0] == 'x' ? write(1, "0x", 2) : write(1, "0X", 2);
	}
	else
		ft_put_char_times(' ', width - precision);
	ft_put_char_times('0', precision - nbr_len);
	hex_output(nbr, args->specifier[0]);
}

size_t	handle_hex_flag(t_arg *args, uintmax_t nbr, size_t nbr_len, size_t precision, size_t width)
{
	if (args->flag[0] == '0')
	{
		ft_put_char_times('0', width - precision);
		hex_output(nbr, args->specifier[0]);
		return ((width > precision ? width : precision));
	}
	print_hex(args, nbr, nbr_len, precision, width);
	if (args->flag[0] == '+' || args->flag[0] == ' ')
		return (width > precision ? width : precision + 1);
	else
	{
		if (!args->flag[0])
			return (width > precision ? width : precision);
		if (args->flag[0] == '#' && nbr != 0)
			return (width > precision ? width : precision + 2);
		return (width > precision ? width : precision + 1);
	}
}

size_t	handle_hex_width(t_arg *args, uintmax_t nbr, size_t nbr_len, size_t precision)
{
	size_t	width;

	width = ft_atoi((const char *)args->width);
	if (args->flag[0] == '-')
	{
		ft_put_char_times('0', precision - nbr_len);
		ft_putnbr_base(nbr, "0123456789abcdef");
		ft_put_char_times(' ', width - precision);
	}
	else
		return (handle_hex_flag(args, nbr, nbr_len, precision, width));
	return ((width > precision ? width : precision));
}

size_t	handle_hex(va_list ap, t_arg *args)
{
	uintmax_t	nbr;
	size_t		precision;
	size_t		nbr_len;

	nbr = get_unsigned_nbr_length(ap, args);
	if (nbr == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	precision = ft_atoi((const char *)args->precision);
	nbr_len = ft_intlen_base(nbr, 16);
	if (precision < nbr_len)
		return (handle_hex_width(args, nbr, nbr_len, nbr_len));
	return (handle_hex_width(args, nbr, nbr_len, precision));
}
