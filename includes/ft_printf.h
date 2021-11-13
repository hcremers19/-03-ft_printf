/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:22:06 by hcremers          #+#    #+#             */
/*   Updated: 2021/11/08 16:22:12 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

void	ft_putnbr_base(unsigned int nbr, char *base);
int		ft_printf(const char *str, ...);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putunbr_fd(unsigned int n, int fd);
void	ft_putstr_fd(char *str, int fd);
size_t	ft_strlen(const char *s);
int		ft_intlen(int n);
int		ft_uintlen(unsigned int n);
int		ft_uintlen_base(unsigned int n, int base);

#endif