/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 23:23:38 by fhong             #+#    #+#             */
/*   Updated: 2018/07/27 00:04:46 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../include/ft_printf.h"

size_t	handle_ptr_width(t_arg *args, char *address_str, size_t str_len)
{
	size_t width;

	width = (size_t)ft_atoi((const char *)args->width);
	if (width > str_len + 2 && args->flag[0] != '-')
		ft_put_char_times(' ', width - str_len - 2);
	ft_putstr("0x");
	ft_putnstr(address_str, str_len);
	if (width > str_len + 2 && args->flag[0] == '-')
		ft_put_char_times(' ', width - str_len - 2);
	free(address_str);
	if (width > str_len + 2)
		return (width);
	return (str_len + 2);
}

size_t	handle_ptr(va_list ap, t_arg *args)
{
	uintmax_t	address_nbr;
	char		*address_str;
	size_t		precision;
	size_t		str_len;

	address_nbr = (uintmax_t)va_arg(ap, void *);
	address_str = ft_itoa_base_uint(address_nbr, "0123456789abcdef");
	precision = ft_atoi((const char *)args->precision);
	str_len = ft_strlen(address_str);
	if (precision > str_len && args->precision)
		return (handle_ptr_width(args, address_str, precision));
	return (handle_ptr_width(args, address_str, str_len));
}
