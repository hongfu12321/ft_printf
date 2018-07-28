/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 22:24:59 by fhong             #+#    #+#             */
/*   Updated: 2018/07/26 00:24:03 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../include/ft_printf.h"

size_t	handle_wstr_width(t_arg *args, wchar_t *wstr, size_t wstr_len)
{
	size_t width;

	width = (size_t)ft_atoi((const char *)args->width);
	if (width > wstr_len)
	{
		ft_put_char_times(' ', width - wstr_len);
		ft_putnwstr(wstr, wstr_len);
		wstr_len = width;
	}
	else
		ft_putnwstr(wstr, wstr_len);
	return (wstr_len);
}

size_t	handle_wstr(va_list ap, t_arg *args)
{
	wchar_t	*wstr;
	size_t	precision;
	size_t	wstr_len;

	wstr = va_arg(ap, wchar_t *);
	if (args->flag[0])
	{
		ft_putstr("flag results in undefined behavior with 's' conversion specifier");
		return (-1);
	}
	precision = ft_atoi((const char *)args->precision);
	wstr_len = ft_wstrlen(wstr);
	if (precision > wstr_len && args->precision)
		return (handle_wstr_width(args, wstr, precision));
	return (handle_wstr_width(args, wstr, wstr_len));
}
