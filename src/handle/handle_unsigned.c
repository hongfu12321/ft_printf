/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 16:58:21 by fhong             #+#    #+#             */
/*   Updated: 2018/07/26 21:55:43 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../include/ft_printf.h"

void	print_unsigned(char flag, uintmax_t nbr, size_t nbr_len, size_t precision, size_t width)
{
	if (flag == '+')
	{
		ft_put_char_times(' ', width - precision - 1);
		write(1, "+", 1);
		ft_put_char_times('0', precision - nbr_len);
		ft_putnbr_uintmax_t(nbr);
	}
	else if (flag == ' ')
	{
		ft_put_char_times(' ', width - precision - 1);
		write(1, " ", 1);
		ft_put_char_times('0', precision - nbr_len);
		ft_putnbr_uintmax_t(nbr);
	}
	else
	{
		ft_put_char_times(' ', width - precision);
		write(1, "", 1);
		ft_put_char_times('0', precision - nbr_len);
		ft_putnbr_uintmax_t(nbr);
	}
}

size_t	handle_unsigned_flag(t_arg *args, uintmax_t nbr, size_t nbr_len, size_t precision, size_t width)
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
	print_unsigned(args->flag[0], nbr, nbr_len, precision, width);
	if (args->flag[0] == '+' || args->flag[0] == ' ')
		return (width > precision ? width : precision + 1);
	else
	{
		if (args->negative)
			return (width > precision ? width : precision);
		return (width > precision ? width : precision + 1);
	}
}

size_t	handle_unsigned_width(t_arg *args, uintmax_t nbr, size_t nbr_len, size_t precision)
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
		return (handle_unsigned_flag(args, nbr, nbr_len, precision, width));
	return ((width > precision ? width : precision));
}

size_t	handle_unsigned(va_list ap, t_arg *args)
{
	uintmax_t	nbr;
	size_t		precision;
	size_t		nbr_len;

	nbr = get_unsigned_nbr_length(ap, args);
	precision = ft_atoi((const char *)args->precision);
	nbr_len = ft_intlen_base(nbr, 10);
	if (precision < nbr_len && args->precision)
		return (handle_unsigned_width(args, nbr, nbr_len, nbr_len));
	return (handle_unsigned_width(args, nbr, nbr_len, precision));
}
