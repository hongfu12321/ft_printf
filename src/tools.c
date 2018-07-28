/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 15:10:05 by fhong             #+#    #+#             */
/*   Updated: 2018/07/27 20:16:06 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../include/ft_printf.h"

void	initial_args(t_arg *args)
{
	args->flag = ft_strnew(1);
	args->width = ft_strnew(1);
	args->precision = ft_strnew(1);
	args->length = ft_strnew(2);
	args->negative = 0;
	args->specifier = ft_strnew(1);
}

void	print_args(t_arg *args)
{
	ft_putstr("negative: ");
	ft_putnbr(args->negative);
	ft_putstr("\n");
	ft_putstr("flag: ");
	ft_putstr(args->flag);
	ft_putstr("\n");
	ft_putstr("width: ");
	ft_putstr(args->width);
	ft_putstr("\n");
	ft_putstr("precision: ");
	ft_putstr(args->precision);
	ft_putstr("\n");
	ft_putstr("length: ");
	ft_putstr(args->length);
	ft_putstr("\n");
	ft_putstr("specifier: ");
	ft_putstr(args->specifier);
	ft_putstr("\n");
}

void	free_args(t_arg *args)
{
	free(args->flag);
	free(args->width);
	free(args->precision);
	free(args->length);
	free(args->specifier);
}
