/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:22:06 by hcremers          #+#    #+#             */
/*   Updated: 2022/11/09 15:53:17 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

int		ft_printf(const char *str, ...);
int		ft_printf_putchar(char c, int count);
int		ft_printf_putstr(char *str, int count);
int		ft_printf_putnbr(int i, int count);
int		ft_printf_putunbr(unsigned int i, int count);
int		ft_printf_putnbr_base(unsigned int i, int count, char c);
int		ft_printf_putaddress(unsigned long i, int count);
int		ft_intlen(int n);
size_t	ft_strlen(const char *s);
int		ft_uintlen(unsigned int n);
int		ft_uintlen_base(unsigned long n, int base);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putunbr_fd(unsigned int n, int fd);
void	ft_putnbr_base(unsigned int nbr, char *base);
void	ft_putlong_base(unsigned long nbr, char *base);

#endif