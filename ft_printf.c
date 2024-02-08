/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iksaiz-m <iksaiz-m@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:40:09 by iksaiz-m          #+#    #+#             */
/*   Updated: 2024/02/08 17:01:27 by iksaiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conversion(va_list arg, char format)
{
	if (format == 'c')
		return (write(1, &(char){va_arg(arg, int)}, 1));
	if (format == 's')
		return (ft_putstr(va_arg(arg, char *)));
	if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(arg, int)));
	if (format == 'u')
		return (ft_putnbr(va_arg(arg, unsigned int)));
	if (format == 'p')
	{
		return (write(1, "0x", 2) + ft_address(va_arg(arg, unsigned long),
				"0123456789abcdef"));
	}
	if (format == 'x')
		return (ft_hexnumber(va_arg(arg, unsigned int), "0123456789abcdef"));
	if (format == 'X')
		return (ft_hexnumber(va_arg(arg, unsigned int), "0123456789ABCDEF"));
	if (format == '%')
		return (write(1, &format, 1));
	return (0);
}

int	ft_printf(char const *string, ...)
{
	va_list	arg;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(arg, string);
	while (string[i] != '\0')
	{
		if (string[i] == '%')
		{
			i++;
			len += ft_conversion(arg, string[i]);
		}
		else
			len += write(1, &string[i], 1);
		if (string[i] != '\0')
			i++;
	}
	va_end(arg);
	return (len);
}

/* int main()
{
	//int str = 1000;
	printf("original: %d\n", 2147483647);
 	ft_printf("mio: %d\n", 2147483647);
	//printf("\n%X ", 9223372036854775807LL);
 	//printf("\n%p", &str);
 	return (0);
} */