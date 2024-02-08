/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iksaiz-m <iksaiz-m@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:25:26 by iksaiz-m          #+#    #+#             */
/*   Updated: 2024/02/08 16:57:39 by iksaiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

int	ft_printf(char const *string, ...);
int	ft_putstr(char *s);
int	ft_putnbr(long n);
int	ft_hexnumber(unsigned int n, char *base);
int	ft_address(unsigned long n, char *base);

#endif
