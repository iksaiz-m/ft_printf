/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iksaiz-m <iksaiz-m@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:04:05 by iksaiz-m          #+#    #+#             */
/*   Updated: 2024/02/08 16:57:27 by iksaiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		i += write (1, "(null)", 6);
		return (i);
	}
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(long n)
{
	int	i;
	int	c;

	i = 0;
	c = (n % 10 + '0');
	if (n < 0)
	{
		i += write(1, "-", 1);
		i += ft_putnbr(-n);
	}
	else if (n >= 10)
	{
		i += ft_putnbr(n / 10);
		i += write(1, &c, 1);
	}
	else
	{
		c = (n + '0');
		i += write(1, &c, 1);
	}
	return (i);
}

int	ft_hexnumber(unsigned int n, char *base)
{
	int	total;

	total = 0;
	if (n >= 16)
		total += ft_hexnumber(n / 16, base);
	total += write(1, &base[n % 16], 1);
	return (total);
}

int	ft_address(unsigned long n, char *base)
{
	int	total;

	total = 0;
	if (n >= 16)
		total += ft_address(n / 16, base);
	total += write(1, &base[n % 16], 1);
	return (total);
}
