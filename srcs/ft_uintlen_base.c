/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uintlen_base                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 18:45:05 by hcremers          #+#    #+#             */
/*   Updated: 2021/11/10 18:45:07 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_uintlen_base(unsigned int n, int base)
{
	int	count;

	count = 0;
	while (n)
	{
		n = n / base;
		count++;
	}
	return (count);
}
