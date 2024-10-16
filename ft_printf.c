/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:21:28 by luigi             #+#    #+#             */
/*   Updated: 2024/10/16 17:01:20 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

static void	ft_putstr(char *str, int *len)
{
	if (!str)
		str = "(null)";
	while (*str)
		*len += write(1, str++, 1);
}

static void	ft_putnbr(long nbr, int base, int *len)
{
	char	*hex = "0123456789abcdef";

	if (nbr < 0)
	{
		nbr *= -1;
		*len += write(1, "-", 1);
	}
	if (nbr >= base)
		ft_putnbr((nbr / base), base, len);
	*len += write(1, &hex[(nbr % base)], 1);
}

int		ft_printf(const char *s, ...)
{
	va_list		args;
	int			len;

	len = 0;
	va_start(args, s);
	while (*s)
	{
		if ((*s == '%') && (*s + 1) != '\0')
		{
			++s;
			if (*s == 's')
				ft_putstr(va_arg(args, char *), &len);
			else if (*s == 'd')
				ft_putnbr(va_arg(args, int), 10, &len);
			else if (*s == 'x')
				ft_putnbr(va_arg(args, unsigned int), 16, &len);
		}
		else
			len += write(1, s, 1);
		++s;
	}
	va_end(args);
	return (len);
}
//
// int main() {
// 	// char	str[1000] = "hello";
// 	// int		number = 80000000;
//
// 	int	r;
//
// 	r = 0;
// 	ft_printf("Simple test\n");
// 	ft_printf("");
// 	ft_printf("--Format---");
// 	ft_printf("---DECIMAL---\n");
// 	ft_printf("%d\n", 0);
// 	ft_printf("%d\n", 42);
// 	ft_printf("%d\n", 1);
// 	ft_printf("%d\n", 5454);
// 	ft_printf("%d\n", (int)2147483647);
// 	ft_printf("%d\n", (int)2147483648);
// 	ft_printf("%d\n", (int)-2147483648);
// 	ft_printf("%d\n", (int)-2147483649);
// 	ft_printf("---HEXA---\n");
// 	ft_printf("%x\n", 0);
// 	ft_printf("%x\n", 42);
// 	ft_printf("%x\n", 1);
// 	ft_printf("%x\n", 5454);
// 	ft_printf("%x\n", (int)2147483647);
// 	ft_printf("%x\n", (int)2147483648);
// 	ft_printf("%x\n", (int)-2147483648);
// 	ft_printf("%x\n", (int)-2147483649);
// 	ft_printf("%x\n", (int)0xFFFFFFFF);
// 	ft_printf("---STRING---\n");
// 	ft_printf("%s\n", "");
// 	ft_printf("%s\n", "toto");
// 	ft_printf("%s\n", "wiurwuyrhwrywuier");
// 	ft_printf("%s\n", NULL);
// 	ft_printf("-%s-%s-%s-%s-\n", "", "toto", "wiurwuyrhwrywuier", NULL);
// 	ft_printf("\n--Mixed---\n");
// 	ft_printf("%d%x%d%x%d%x%d%x\n", 0, 0, 42, 42, 2147483647, 2147483647, (int)-2147483648, (int)-2147483648);
// 	ft_printf("-%d-%x-%d-%x-%d-%x-%d-%x-\n", 0, 0, 42, 42, 2147483647, 2147483647, (int)-2147483648, (int)-2147483648);
// 	ft_printf("\n");
// 	ft_printf("%s%s%s%s\n", "", "toto", "wiurwuyrhwrywuier", NULL);
// 	ft_printf("-%s-%s-%s-%s-\n", "", "toto", "wiurwuyrhwrywuier", NULL);
// 	printf("written: %d\n", r);
// }
