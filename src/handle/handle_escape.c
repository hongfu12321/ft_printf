/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_escape.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 17:16:06 by fhong             #+#    #+#             */
/*   Updated: 2018/07/27 20:47:14 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../include/ft_printf.h"

size_t	handle_escape(va_list ap, t_arg *args)
{
	size_t	width;

	if (ap)
		;
	width = (size_t)ft_atoi((const char *)args->width);
	if (args->flag[0] != '-')
		ft_put_char_times(' ', width - 1);
	ft_putchar('%');
	if (args->flag[0] == '-')
		ft_put_char_times(' ', width - 1);
	if (width != 0)
		return (width);
	return (1);
}
