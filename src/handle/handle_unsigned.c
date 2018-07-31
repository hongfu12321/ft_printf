/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 21:26:30 by fhong             #+#    #+#             */
/*   Updated: 2018/07/30 13:11:31 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../include/ft_printf.h"

size_t	handle_unsigned_print(t_arg *args, uintmax_t nbr, size_t nbr_len, size_t precision)
{
	size_t	width;

	width = ft_atoi((const char *)args->width);
	if (!MINUS)
	{
	   	if (ZERO == 0)
			ft_put_char_times(' ', TRUE(width, precision));
		else
			ft_put_char_times('0', TRUE(width, precision));
	}
	ft_put_char_times('0', TRUE(precision, nbr_len));
	ft_putnbr_uintmax_t_base(nbr, "0123456789");
	if (MINUS)
		ft_put_char_times(' ', TRUE(width, precision));
	return (width > precision ? width : precision);
}

size_t	handle_unsigned(va_list ap, t_arg *args)
{
	uintmax_t	nbr;
	size_t		precision;
	size_t		nbr_len;

	nbr = get_unsigned_nbr_length(ap, args);
	precision = ft_atoi((const char *)args->precision);
	nbr_len = ft_uintlen_base(nbr, 10);
	if (nbr == 0 && !args->precision[0] && !args->width[0] && FLAG == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (nbr == 0)
		return (handle_unsigned_print(args, nbr, 1, 1));
	if (precision < nbr_len || nbr == 0)
		return (handle_unsigned_print(args, nbr, nbr_len, nbr_len));
	return (handle_unsigned_print(args, nbr, nbr_len, precision));
}
