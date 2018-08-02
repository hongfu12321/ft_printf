/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_escape.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 17:16:06 by fhong             #+#    #+#             */
/*   Updated: 2018/08/02 00:29:33 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../include/ft_printf.h"

size_t	handle_escape(va_list ap, t_arg *args)
{
	size_t	width;

	(void)ap;
	width = (size_t)ft_atoi((const char *)args->width);
	if (!MINUS)
	{
		if (ZERO == 0)
			ft_put_char_times(' ', width - 1);
		else
			ft_put_char_times('0', width - 1);
	}
	ft_putchar('%');
	if (MINUS)
		ft_put_char_times(' ', width - 1);
	if (width != 0)
		return (width);
	return (1);
}
