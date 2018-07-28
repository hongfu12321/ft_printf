/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 21:34:08 by fhong             #+#    #+#             */
/*   Updated: 2018/07/27 00:06:53 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../include/ft_printf.h"

size_t	handle_str_width(t_arg *args, char *str, size_t str_len)
{
	size_t width;

	width = (size_t)ft_atoi((const char *)args->width);
	if (width > str_len)
	{
		ft_put_char_times(' ', width - str_len);
		ft_putnstr(str, str_len);
		str_len = width;
	}
	else
		ft_putnstr(str, str_len);
	return (str_len);
}

size_t	handle_str(va_list ap, t_arg *args)
{
	char	*str;
	size_t	precision;
	size_t	str_len;

	if (!ft_strcmp((const char *)args->length, "l"))
		return (handle_wstr(ap, args));
	if (!(str = va_arg(ap, char *)))
		ft_strcpy(str, "(null)");
	precision = ft_atoi((const char *)args->precision);
	str_len = ft_strlen(str);
	if (precision > str_len && args->precision)
		return (handle_str_width(args, str, precision));
	return (handle_str_width(args, str, str_len));
}
