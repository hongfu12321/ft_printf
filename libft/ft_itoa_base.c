/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 21:04:10 by fhong             #+#    #+#             */
/*   Updated: 2018/07/30 21:54:21 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(intmax_t value, int base)
{
	char	*str;
	int		size;
	char	tab[] = "0123456789ABCDEF";
	int		flag;

	flag = 0;
	size = 0;
	if (base < 2 || base > 16)
		return (0);
	if (value < 0 && base == 10)
		flag = 1;
	size = ft_intlen_base(value, base) + flag;
	str = ft_strnew(size);
	if (flag == 1)
	{
		str[0] = '-';
		value = -value;
	}
	while (size > flag)
	{
		str[size - 1] = tab[value % base];
		size--;
		value /=base;
	}
	return (str);
}
