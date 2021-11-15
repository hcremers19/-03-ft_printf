/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:58:23 by hcremers          #+#    #+#             */
/*   Updated: 2021/11/15 13:58:25 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_putunbr(unsigned int i, int count)
{
	ft_putunbr_fd(i, 1);
	if (i)
		count = count + ft_uintlen(i);
	else
		count = count + 1;
	return (count);
}

int	ft_printf_putnbr_base(unsigned int i, int count, char c)
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

int	ft_printf_putaddress(unsigned long i, int count)
{
	ft_putstr_fd("0x", 1);
	ft_putlong_base(i, "0123456789abcdef");
	if (i)
		count = count + 2 + ft_uintlen_base(i, ft_strlen("0123456789abcdef"));
	else
		count = count + 3;
	return (count);
}
