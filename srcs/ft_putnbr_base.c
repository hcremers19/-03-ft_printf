/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:54:19 by hcremers          #+#    #+#             */
/*   Updated: 2021/11/10 14:54:22 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr_base(unsigned int nbr, char *base)
{
	unsigned int	len;

	len = ft_strlen(base);
	if (0 <= nbr && nbr <= (len - 1))
		ft_putchar_fd(base[nbr], 1);
	else if (nbr < 0)
	{
		ft_putchar_fd('-', 1);
		ft_putnbr_base(-nbr, base);
	}
	else
	{
		ft_putnbr_base(nbr / len, base);
		ft_putnbr_base(nbr % len, base);
	}
}
