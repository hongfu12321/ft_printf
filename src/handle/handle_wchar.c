/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 23:55:36 by fhong             #+#    #+#             */
/*   Updated: 2018/07/31 20:44:08 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../include/ft_printf.h"

size_t	handle_wchar(va_list ap, t_arg *args)
{
	wchar_t	wc;
	size_t	width;

	wc = va_arg(ap, int);
	width = (size_t)ft_atoi((const char *)args->width);
	if (!MINUS && width > 0)
	{
		if (ZERO)
			ft_put_char_times('0', width - 1);
		else
			ft_put_char_times(' ', width - 1);
	}
	ft_putwchar(wc);
	if (MINUS && width > 0)
		ft_put_char_times(' ', width - 1);
	if (width == 0)
		return (1);
	return (width);
}
