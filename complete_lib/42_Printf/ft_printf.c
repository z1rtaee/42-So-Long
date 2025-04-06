/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpires-r <bpires-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:11:28 by bpires-r          #+#    #+#             */
/*   Updated: 2024/11/21 18:06:37 by bpires-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	res;

	res = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (*s)
	{
		res = res + write(1, &*s, 1);
		s++;
	}
	return (res);
}

int	ft_putnbr(long n, int base, char *base_str)
{
	int	res;

	res = 0;
	if (n < 0 && base == 10)
	{
		res = res + write(1, "-", 1);
		n = -n;
	}
	if (n >= base)
		res = res + ft_putnbr(n / base, base, base_str);
	res = res + write(1, &base_str[n % base], 1);
	return (res);
}

int	ft_putptr(unsigned long int p, int prefix, char *base_str)
{
	int		res;

	res = 0;
	if (!p)
		return (ft_putstr("(nil)"));
	if (prefix == 1)
		res = res + write(1, "0x", 2);
	if (p >= 16)
		res = res + ft_putptr(p / 16, 0, base_str);
	res = res + write(1, &base_str[p % 16], 1);
	return (res);
}

int	ft_format(const char *s, va_list arg_lst)
{
	int	c;

	c = 0;
	if (*s == 'c')
	{
		c = va_arg(arg_lst, int);
		return (write(1, &c, 1));
	}
	else if (*s == 's')
		return (ft_putstr(va_arg(arg_lst, char *)));
	else if (*s == 'd' || *s == 'i')
		return (ft_putnbr(va_arg(arg_lst, int), 10, DECIMAL));
	else if (*s == 'u')
		return (ft_putnbr(va_arg(arg_lst, unsigned int), 10, DECIMAL));
	else if (*s == 'X')
		return (ft_putnbr(va_arg(arg_lst, unsigned int), 16, HEXA_UP));
	else if (*s == 'x')
		return (ft_putnbr(va_arg(arg_lst, unsigned int), 16, HEXA_LOW));
	else if (*s == 'p')
		return (ft_putptr(va_arg(arg_lst, unsigned long int), 1, HEXA_LOW));
	else if (*s == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	int		res;
	va_list	arg_lst;
	size_t	i;

	if (!s)
		return (-1);
	i = 0;
	res = 0;
	va_start(arg_lst, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			res = res + ft_format(&s[i], arg_lst);
		}
		else
			res = res + write(1, &s[i], 1);
		s++;
	}
	va_end (arg_lst);
	return (res);
}

// int	main(void)
// {
// 	char *s = NULL;
// 	ft_printf("%d\n", 23);
// 	ft_printf("%s\n", s);
// 	printf("%s\n", s);
// 	ft_printf("%p\n",s);
// 	printf("%p\n", s);
// 	return (0);
// }
