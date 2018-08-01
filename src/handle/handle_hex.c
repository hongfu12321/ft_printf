/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 22:06:34 by fhong             #+#    #+#             */
/*   Updated: 2018/08/01 15:59:34 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../include/ft_printf.h"

void	hex_output(uintmax_t nbr, char specifier)
{
	if (specifier == 'x')
		ft_putnbr_uintmax_t_base(nbr, "0123456789abcdef");
	else
		ft_putnbr_uintmax_t_base(nbr, "0123456789ABCDEF");
}

void	print_hex(t_arg *args, uintmax_t nbr, size_t nbr_len, size_t precision)
{
	size_t	width;

	width = ft_atoi((const char *)args->width);
	if (PLUS == 1 || SPACE == 1)
	{
		ft_put_char_times(' ', width - precision - 1);
		PLUS ? write(1, "+", 1) : write(1, " ", 1);
	}
	ft_put_char_times('0', TRUE(precision, nbr_len));
	hex_output(nbr, args->specifier[0]);
}

size_t	hex_flag(t_arg *args, uintmax_t nbr, size_t nbr_len, size_t precision)
{
	size_t	width;

	width = ft_atoi((const char *)args->width);
	if (!ZERO && !MINUS)
		ft_put_char_times(' ', TRUE(width, (HASH + precision)));
	if (HASH && nbr != 0)
		args->specifier[0] == 'x' ? write(1, "0x", 2) : write(1, "0X", 2);
	if (ZERO && !MINUS)
		ft_put_char_times('0', TRUE(width, (HASH + precision)));
	if (nbr != 0)
		print_hex(args, nbr, nbr_len, precision);
	if (PLUS == 1 || SPACE == 1)
		return (width > HASH + precision + 1 ? width - HASH : precision + 1);
	else
		return (width > precision + HASH ? width - HASH : precision);
}

size_t	hex_minus(t_arg *args, uintmax_t nbr, size_t nbr_len, size_t precision)
{
	size_t	length;
	size_t	width;

	width = ft_atoi((const char *)args->width);
	if (nbr != 0)
		length = HASH;
	else
		length = 0;
	length += hex_flag(args, nbr, nbr_len, precision);
	if (MINUS)
		ft_put_char_times(' ', TRUE(width, (HASH + precision)));
	return (length);
}

size_t	handle_hex(va_list ap, t_arg *args)
{
	uintmax_t	nbr;
	size_t		precision;
	size_t		nbr_len;

	nbr = get_unsigned_nbr_length(ap, args);
	precision = ft_atoi((const char *)args->precision);
	nbr_len = ft_uintlen_base(nbr, 16);
	if (nbr == 0 && !args->precision[0] && !args->width[0])
	{
		write(1, "0", 1);
		return (1);
	}
	if (nbr == 0)
		return (hex_minus(args, nbr, 0, 0));
	if (precision < nbr_len || nbr == 0)
		return (hex_minus(args, nbr, nbr_len, nbr_len));
	return (hex_minus(args, nbr, nbr_len, precision));
}
