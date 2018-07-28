/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 23:55:36 by fhong             #+#    #+#             */
/*   Updated: 2018/07/24 23:59:36 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../include/ft_printf.h"

size_t	handle_wchar(va_list ap, t_arg *args)
{
	wchar_t	c;
	size_t	width;

	if (!ft_strcmp((const char *)args->length, "l"))
		return (handle_wstr(ap, args));
	if (args->flag || args->precision)
	{
		if (args->flag)
			ft_putstr("flag results in undefined behavior with 's' conversion specifier");
		else
			ft_putstr("precision results in undefined behavior with 's' conversion specifier");
		return (-1);
	}
	c = va_arg(ap, int);
	width = (size_t)ft_atoi((const char *)args->width);
	if (width > 0)
		ft_put_char_times(' ', width - 1);
	else
		width = 1;
	ft_putwchar(c);
	return (width);
}
