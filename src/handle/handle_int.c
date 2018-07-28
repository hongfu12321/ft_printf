/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 11:43:55 by fhong             #+#    #+#             */
/*   Updated: 2018/07/26 21:53:51 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../include/ft_printf.h"

void	print_nbr(int negative, char flag, intmax_t nbr, size_t nbr_len, size_t precision, size_t width)
{
	if (flag == '+')
	{
		ft_put_char_times(' ', width - precision - 1);
		negative == 1 ? write(1, "-", 1) : write(1, "+", 1);
		ft_put_char_times('0', precision - nbr_len);
		ft_putnbr_uintmax_t(nbr);
	}
	else if (flag == ' ')
	{
		ft_put_char_times(' ', width - precision - 1);
		negative == 1 ? write(1, "-", 1) : write(1, " ", 1);
		ft_put_char_times('0', precision - nbr_len);
		ft_putnbr_uintmax_t(nbr);
	}
	else
	{
		ft_put_char_times(' ', (negative == 1 ? width - 1 : width) - precision);
		negative == 1 ? write(1, "-", 1) : write(1, "", 1);
		ft_put_char_times('0', precision - nbr_len);
		ft_putnbr_uintmax_t(nbr);
	}
}

size_t	handle_int_flag(t_arg *args, intmax_t nbr, size_t nbr_len, size_t precision, size_t width)
{
	if (args->flag[0] == '0' && !args->precision)
	{
		if (args->negative == 1)
			write(1, "-", 1);
		args->negative == 1 ? ft_put_char_times('0', width - (precision += 1)) 
			: ft_put_char_times('0', width - precision);
		ft_putnbr_uintmax_t(nbr);
		return ((width > precision ? width : precision));
	}
	print_nbr(args->negative, args->flag[0], nbr, nbr_len, precision, width);
	if (args->flag[0] == '+' || args->flag[0] == ' ')
		return (width > precision ? width : precision + 1);
	else
	{
		if (args->negative)
			return (width > precision ? width : precision);
		return (width > precision ? width : precision + 1);
	}
}

size_t	handle_int_width(t_arg *args, intmax_t nbr, size_t nbr_len, size_t precision)
{
	size_t	width;

	width = ft_atoi((const char *)args->width);
	if (args->flag[0] == '-')
	{
		if (args->negative == 1)
			write(1, "-", 1);
		ft_put_char_times('0', precision - nbr_len);
		ft_putnbr_uintmax_t(nbr);
		args->negative == 1 ? ft_put_char_times(' ', width - (precision += 1)) 
			: ft_put_char_times(' ', width - precision);
	}
	else
		return (handle_int_flag(args, nbr, nbr_len, precision, width));
	return ((width > precision ? width : precision));
}

size_t	handle_int(va_list ap, t_arg *args)
{
	intmax_t	nbr;
	size_t		precision;
	size_t		nbr_len;

	nbr = get_signed_nbr_length(ap, args);
	if (nbr < 0)
	{
		nbr = -nbr;
		args->negative = 1;
	}
	precision = ft_atoi((const char *)args->precision);
	nbr_len = ft_intlen_base(nbr, 10);
	if (precision < nbr_len && args->precision)
		return (handle_int_width(args, nbr, nbr_len, nbr_len));
	return (handle_int_width(args, nbr, nbr_len, precision));
}
