/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 23:55:36 by fhong             #+#    #+#             */
/*   Updated: 2018/07/29 02:08:57 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../include/ft_printf.h"

size_t	handle_wchar(va_list ap, t_arg *args)
{
	wchar_t	wc;
	size_t	width;

	width = (size_t)ft_atoi((const char *)args->width);
	wc = va_arg(ap, wchar_t);
	if (MINUS)
	{
		ft_putwchar(wc);
		ft_put_char_times(' ', width - 1);
	}
	else
	{
		ft_put_char_times(' ', width - 1);
		ft_putwchar(wc);
	}
	if (width == 0)
		return (1);
	return (width);
}
