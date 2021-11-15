#include "ft_printf.h"

int	ft_intlen(int n)
{
	int	count;

	count = 0;
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}

int	ft_uintlen(unsigned int n)
{
	int	count;

	count = 0;
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

int	ft_uintlen_base(unsigned long n, int base)
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
