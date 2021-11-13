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

#include "../includes/ft_printf.h"

int	printf_putchar(char c, int count)
{
	ft_putchar_fd(c, 1);
	count++;
	return (count);
}

int	printf_putnbr(int i, int count)
{
	ft_putnbr_fd(i, 1);
	if (i > 0)
		count = count + ft_intlen(i);
	else if (i <= 0)
		count = count + ft_intlen(i) + 1;
	return (count);
}

int	printf_putunbr(unsigned int i, int count)
{
	ft_putunbr_fd(i, 1);
	if (i)
		count = count + ft_uintlen(i);
	else
		count = count + 1;
	return (count);
}

int	printf_putstr(char *str, int count)
{
	if (str)
	{
		ft_putstr_fd(str, 1);
		count = count + ft_strlen(str);
	}
	else
	{
		ft_putstr_fd("(null)", 1);
		count = count + 6;
	}
	return (count);
}

int	printf_putnbr_base(unsigned int i, int count, char c)
{
	if (c == 'x')
		ft_putnbr_base(i, "0123456789abcdef");
	else if (c == 'X')
		ft_putnbr_base(i, "0123456789ABCDEF");
	if (i)
		count = count + ft_uintlen_base(i, 16);
	else
		count = count + 1;
	return (count);
}

int	printf_putaddress(unsigned long i, int count)
{
	ft_putstr_fd("0x", 1);
	ft_putlong_base(i, "0123456789abcdef");
	if (i)
		count = count + 2 + ft_uintlen_base(i, ft_strlen("0123456789abcdef"));
	else
		count = count + 3;
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
			i++;
			count++;
		}
		else
		{
			i++;
			if (str[i] == '%')
				count = printf_putchar('%', count);
			else if (str[i] == 'd' || str[i] == 'i')
				count = printf_putnbr(va_arg(arg, int), count);
			else if (str[i] == 'c')
				count = printf_putchar(va_arg(arg, int), count);
			else if (str[i] == 's')
				count = printf_putstr(va_arg(arg, char *), count);
			else if (str[i] == 'u')
				count = printf_putunbr(va_arg(arg, unsigned int), count);
			else if (str[i] == 'x')
				count = printf_putnbr_base(va_arg(arg, unsigned int), count, 'x');
			else if (str[i] == 'X')
				count = printf_putnbr_base(va_arg(arg, unsigned int), count, 'X');
			else if (str[i] == 'p')
				count = printf_putaddress(va_arg(arg, unsigned long), count);
			i++;
		}
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
	itg = 0;
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
*/
//  LONG_MIN = -2147483648
//  LONG_MAX =  2147483647
// ULONG_MAX =  4294967295
//-ULONG_MAX = -4294967295