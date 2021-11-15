/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:58:15 by hcremers          #+#    #+#             */
/*   Updated: 2021/11/15 13:58:18 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_putchar(char c, int count)
{
	ft_putchar_fd(c, 1);
	count++;
	return (count);
}

int	ft_printf_putstr(char *str, int count)
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

int	ft_printf_putnbr(int i, int count)
{
	ft_putnbr_fd(i, 1);
	if (i > 0)
		count = count + ft_intlen(i);
	else if (i <= 0)
		count = count + ft_intlen(i) + 1;
	return (count);
}
