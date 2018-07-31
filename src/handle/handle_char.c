/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 23:01:30 by fhong             #+#    #+#             */
/*   Updated: 2018/07/30 23:11:35 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../include/ft_printf.h"

size_t	handle_char(va_list ap, t_arg *args)
{
	char	c;
	size_t	width;

	if (!ft_strcmp((const char *)args->length, "l"))
		return (handle_wstr(ap, args));
	if (args->specifier[0] == 'Z')
		c = 'Z';
	else
		c = va_arg(ap, int);
	width = (size_t)ft_atoi((const char *)args->width);
	if (!MINUS && width > 0)
	{
		if (ZERO)
			ft_put_char_times(' ', width - 1);
		else
			ft_put_char_times(' ', width - 1);
	}
	ft_putchar(c);
	if (MINUS && width > 0)
		ft_put_char_times(' ', width - 1);
	if (width == 0)
		return (1);
	return (width);
}
