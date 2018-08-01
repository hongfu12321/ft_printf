/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 15:10:05 by fhong             #+#    #+#             */
/*   Updated: 2018/08/01 16:46:52 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../include/ft_printf.h"

void	initial_args(t_arg *args)
{
	args->flag = ft_size_t_new(5);
	HASH = 0;
	MINUS = 0;
	PLUS = 0;
	SPACE = 0;
	ZERO = 0;
	args->width = ft_strnew(1);
	args->precision = ft_strnew(1);
	args->length = ft_strnew(2);
	args->negative = 0;
	args->specifier = ft_strnew(1);
}

void	print_args(t_arg *args)
{
	ft_printf("negative = %d\n", args->negative);
	ft_printf("hash = %zu\n", args->flag[0]);
	ft_printf("minus = %zu\n", args->flag[1]);
	ft_printf("plus = %zu\n", args->flag[2]);
	ft_printf("space = %zu\n", args->flag[3]);
	ft_printf("zero = %zu\n", args->flag[4]);
	ft_printf("width = %s\n", args->width);
	ft_printf("precision = %s\n", args->precision);
	ft_printf("length = %s\n", args->length);
	ft_printf("specifier = %s\n", args->specifier);
}

void	free_args(t_arg *args)
{
	ft_memdel((void **)&args->flag);
	ft_memdel((void **)&args->width);
	ft_memdel((void **)&args->precision);
	ft_memdel((void **)&args->length);
	ft_memdel((void **)&args->specifier);
	ft_memdel((void **)&args);
}

void	reset_flag(t_arg *args)
{
	HASH = 0;
	MINUS = 0;
	PLUS = 0;
	SPACE = 0;
	ZERO = 0;
	NEGATIVE = 0;
}
