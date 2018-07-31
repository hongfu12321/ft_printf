/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 15:10:05 by fhong             #+#    #+#             */
/*   Updated: 2018/07/31 00:32:48 by fhong            ###   ########.fr       */
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
	printf("negative = %d\n", args->negative);
	printf("hash = %zu\n", args->flag[0]);
	printf("minus = %zu\n", args->flag[1]);
	printf("plus = %zu\n", args->flag[2]);
	printf("space = %zu\n", args->flag[3]);
	printf("zero = %zu\n", args->flag[4]);
	printf("width = %s\n", args->width);
	printf("precision = %s\n", args->precision);
	printf("length = %s\n", args->length);
	printf("specifier = %s\n", args->specifier);
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

int		is_specifier(char c)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' ||
		c == 'i' || c == 'o' || c == 'O' || c == 'u' || c == 'U' ||
		c == 'x' || c == 'X' || c == 'c' || c == 'C' || c == '%')
		return (1);
	return (0);
}
