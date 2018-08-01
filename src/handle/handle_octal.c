/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 02:09:50 by fhong             #+#    #+#             */
/*   Updated: 2018/08/01 15:47:34 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../include/ft_printf.h"

size_t	oct_flag(t_arg *args, uintmax_t nbr, size_t nbr_len, size_t precision)
{
	size_t	width;

	width = ft_atoi((const char *)args->width);
	if (!ZERO && !MINUS)
		ft_put_char_times(' ', TRUE(width, (HASH + precision)));
	if (HASH)
		write(1, "0", 1);
	if (ZERO && !MINUS)
		ft_put_char_times('0', TRUE(width, (HASH + precision)));
	if (nbr != 0)
	{
		ft_put_char_times('0', TRUE(precision, nbr_len));
		ft_putnbr_uintmax_t_base(nbr, "01234567");
	}
	if (HASH && nbr == 0)
		return (1);
	if (PLUS == 1 || SPACE == 1)
		return (width - HASH > precision + 1 ? width - HASH : precision + 1);
	else
		return (width > precision + HASH ? width - HASH : precision);
}

size_t	octal_min(t_arg *args, uintmax_t nbr, size_t nbr_len, size_t precision)
{
	size_t	length;
	size_t	width;

	width = ft_atoi((const char *)args->width);
	if (nbr != 0)
		length = HASH;
	else
		length = 0;
	length += oct_flag(args, nbr, nbr_len, precision);
	if (MINUS)
		ft_put_char_times(' ', TRUE(width, (HASH + precision)));
	return (length);
}

size_t	handle_octal(va_list ap, t_arg *args)
{
	uintmax_t	nbr;
	size_t		precision;
	size_t		nbr_len;

	nbr = get_unsigned_nbr_length(ap, args);
	precision = ft_atoi((const char *)args->precision);
	nbr_len = ft_intlen_base(nbr, 8);
	if (nbr == 0 && (!args->width[0] && !args->precision[0]))
	{
		write(1, "0", 1);
		return (1);
	}
	if (HASH == 2)
		HASH = 1;
	if (nbr == 0)
		return (octal_min(args, nbr, 0, 0));
	if (precision < nbr_len || nbr == 0)
		return (octal_min(args, nbr, nbr_len, nbr_len));
	return (octal_min(args, nbr, nbr_len, precision));
}
