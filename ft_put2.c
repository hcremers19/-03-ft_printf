#include "ft_printf.h"

void	ft_putunbr_fd(unsigned int n, int fd)
{
	if (n >= 0 && n < 10)
		ft_putchar_fd(n + '0', fd);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putunbr_fd(-n, fd);
	}
	else
	{
		ft_putunbr_fd(n / 10, fd);
		ft_putunbr_fd(n % 10, fd);
	}
}

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

void	ft_putlong_base(unsigned long nbr, char *base)
{
	unsigned int	len;

	len = ft_strlen(base);
	if (0 <= nbr && nbr <= (len - 1))
		ft_putchar_fd(base[nbr], 1);
	else if (nbr < 0)
	{
		ft_putchar_fd('-', 1);
		ft_putlong_base(-nbr, base);
	}
	else
	{
		ft_putlong_base(nbr / len, base);
		ft_putlong_base(nbr % len, base);
	}
}
