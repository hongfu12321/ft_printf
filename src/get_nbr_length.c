/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nbr_length.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 16:19:18 by fhong             #+#    #+#             */
/*   Updated: 2018/08/01 15:56:33 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../include/ft_printf.h"

intmax_t	get_signed_nbr_length(va_list ap, t_arg *args)
{
	intmax_t	nbr;
	char		*length;

	length = args->length;
	if (!(nbr = va_arg(ap, intmax_t)))
		return (0);
	if (!ft_strcmp(length, "h") && args->specifier[0] != 'D')
		nbr = (short int)nbr;
	else if (!ft_strcmp(length, "l") || args->specifier[0] == 'D')
		nbr = (long int)nbr;
	else if (!ft_strcmp(length, "hh"))
		nbr = (signed char)nbr;
	else if (!ft_strcmp(length, "ll"))
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
	if (!ft_strcmp(length, "h") && SPECIFIER[0] != 'U' && SPECIFIER[0] != 'O')
		nbr = (unsigned short)nbr;
	else if (!ft_strcmp(length, "l") || SPECIFIER[0] == 'U' ||
			SPECIFIER[0] == 'O')
		nbr = (unsigned long int)nbr;
	else if (!ft_strcmp(length, "hh"))
		nbr = (unsigned char)nbr;
	else if (!ft_strcmp(length, "ll"))
		nbr = (unsigned long long int)nbr;
	else if (length[0] == 'j')
		nbr = (uintmax_t)nbr;
	else if (length[0] == 'z')
		nbr = (size_t)nbr;
	else
		nbr = (unsigned int)nbr;
	return (nbr);
}
