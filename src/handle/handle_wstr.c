/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 22:24:59 by fhong             #+#    #+#             */
/*   Updated: 2018/08/02 00:16:14 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../include/ft_printf.h"

size_t	handle_wstr_width(t_arg *args, wchar_t *wstr, size_t str_len)
{
	size_t width;

	if (!*wstr)
		str_len = 0;
	width = (size_t)ft_atoi((const char *)args->width);
	if (width > str_len)
	{
		if (!MINUS)
			ft_put_char_times(' ', TRUE(width, str_len));
		ft_putnwstr(wstr, str_len);
		if (MINUS)
			ft_put_char_times(' ', TRUE(width, str_len));
		str_len = width;
	}
	else
		ft_putnwstr(wstr, str_len);
	return (str_len);
}

size_t	handle_wstr(va_list ap, t_arg *args)
{
	wchar_t	*wstr;
	size_t	precision;
	size_t	str_len;

	wstr = va_arg(ap, wchar_t *);
	precision = ft_atoi((const char *)args->precision);
	str_len = ft_wstrlen(wstr);
	if (args->precision[0])
		return (handle_wstr_width(args, wstr, precision));
	return (handle_wstr_width(args, wstr, str_len));
}
