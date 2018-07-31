/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 22:17:05 by fhong             #+#    #+#             */
/*   Updated: 2018/07/31 00:49:06 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../include/ft_printf.h"

int		main(void)
{
	size_t ret1;
	intmax_t a = -92233720364775808;;
	printf("-------- ft_printf --------\n");
//	ret1 =printf("%jd", -9223372036854775808);
//	printf("%jd\n", a);
	ret1 =ft_printf("%5#0jd", a);
//	ret1 = ft_printf("%ll...hhh##5%");
//	printf("\nret1 = %zu\n", ret1);
	return (0);
}
