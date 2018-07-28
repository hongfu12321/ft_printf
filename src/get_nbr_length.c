/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nbr_length.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 16:19:18 by fhong             #+#    #+#             */
/*   Updated: 2018/07/27 20:37:52 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../include/ft_printf.h"

intmax_t	get_signed_nbr_length(va_list ap, t_arg *args)
{
	intmax_t	nbr;
	char		*length;

	length = args->length;
	nbr = va_arg(ap, intmax_t);
	if (length[0] == 'h' && length[1] != 'h' && args->specifier[0] != 'D')
		nbr = (short int)nbr;
	else if ((length[0] == 'l' && length[1] != 'l') || args->specifier[0] == 'D')
		nbr = (long int)nbr;
	else if (length[0] == 'h' && length[1] != 'h')
		nbr = (signed char)nbr;
	else if (length[0] == 'l' && length[1] == 'l')
		nbr = (long long int)nbr;
	else if (length[0] == 'j')
		nbr = (intmax_t)nbr;
	else if (length[0] == 'z')
		nbr = (size_t)nbr;
	else
		nbr = (int)nbr;
	return (nbr);
}

uintmax_t	get_unsigned_nbr_length(va_list ap, t_arg *args)
{
	uintmax_t	nbr;
	char		*length;

	length = args->length;
	nbr = va_arg(ap, uintmax_t);
	if (length[0] == 'h' && length[1] != 'h' && args->specifier[0] != 'D')
		nbr = (unsigned short int)nbr;
	else if ((length[0] == 'l' && length[1] != 'l') || args->specifier[0] == 'D')
		nbr = (unsigned long int)nbr;
	else if (length[0] == 'h' && length[1] != 'h')
		nbr = (unsigned char)nbr;
	else if (length[0] == 'l' && length[1] == 'l')
		nbr = (unsigned long long int)nbr;
	else if (length[0] == 'j')
		nbr = (uintmax_t)nbr;
	else if (length[0] == 'z')
		nbr = (size_t)nbr;
	else
		nbr = (unsigned int)nbr;
	return (nbr);
}
