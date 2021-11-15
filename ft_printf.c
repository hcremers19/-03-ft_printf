/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:14:56 by hcremers          #+#    #+#             */
/*   Updated: 2021/11/08 16:15:01 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	sub_ft_printf(const char *str, int i, int count, va_list arg)
{			
	if (str[i] == '%')
		count = ft_printf_putchar('%', count);
	else if (str[i] == 'd' || str[i] == 'i')
		count = ft_printf_putnbr(va_arg(arg, int), count);
	else if (str[i] == 'c')
		count = ft_printf_putchar(va_arg(arg, int), count);
	else if (str[i] == 's')
		count = ft_printf_putstr(va_arg(arg, char *), count);
	else if (str[i] == 'u')
		count = ft_printf_putunbr(va_arg(arg, unsigned int), count);
	else if (str[i] == 'x')
		count = ft_printf_putnbr_base(va_arg(arg, unsigned int), count, 'x');
	else if (str[i] == 'X')
		count = ft_printf_putnbr_base(va_arg(arg, unsigned int), count, 'X');
	else if (str[i] == 'p')
		count = ft_printf_putaddress(va_arg(arg, unsigned long), count);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	arg;
	int		count;

	i = 0;
	count = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] != '%')
		{
			ft_putchar_fd(str[i], 1);
			count++;
		}
		else
		{
			i++;
			count = sub_ft_printf(str, i, count, arg);
		}
		i++;
	}
	va_end(arg);
	return (count);
}
/*
int	main(void)
{
	char	*str;
	int		itg;
	char	ctr;

	str = "string";
	itg = -2147483648;
	ctr = 'e';
	ft_printf("String:		%s	%p\n", NULL, NULL);
	ft_printf("Character:	%c	%%\n", ctr);
	ft_printf("Integer:	%d	%i	%u	%x	%X\n\n", itg, itg, itg, itg, itg);
	printf("String:		%s	%p\n", NULL, NULL);
	printf("Character:	%c	%%\n", ctr);
	printf("Integer:	%d	%i	%u	%x	%X\n\n", itg, itg, itg, itg, itg);
	ft_printf("%d\n", ft_printf(" %X \t", -1));
	printf("%d\n", printf(" %X \t", -1));
	ft_printf("%d\n", ft_printf(" %s \t", NULL));
	printf("%d\n", printf(" %s \t", NULL));
	return (0);
}
//  LONG_MAX =  2147483647
//  LONG_MIN = -2147483648
// ULONG_MAX =  4294967295
//-ULONG_MAX = -4294967295
*/