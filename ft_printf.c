/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansilva- <ansilva-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 11:31:00 by ansilva-          #+#    #+#             */
/*   Updated: 2022/03/04 16:00:43 by ansilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	conversion(va_list args, char format)
{
	int	i;

	i = 0;
	if (format == 'c')
		i += ft_putchar((char)va_arg(args, int));
	else if (format == 's')
		i += ft_putstr(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		i += ft_put_di(va_arg(args, int));
	else if (format == '%')
		i += ft_putchar('%');
	else if (format == 'u')
		i += ft_put_u(va_arg(args, unsigned int));
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		index;

	va_start(args, format);
	index = 0;
	i = 0;
	while (format[index])
	{
		if (format[index] == '%')
			i += conversion(args, format[++index]);
		else
			i += ft_putchar(format[index]);
		index++;
	}
	va_end(args);
	return (i);
}

int	main(void)
{
	char			c;
	char			*s;
	int				d;
	int				i;
	unsigned int	ui;

	c = '0';
	s = "string123";
	d = 2147483647;
	i = -2147483648;
	ui = 12345;
	ft_printf("Meu printf para\nc: %c\ns: %s\nporcento: %%\ndi: %d e %i\nu: %u\n", c, s, d, i, ui);
	ft_printf("---------------\n");
	printf("Original para\nc: %c\ns: %s\nporcento: %%\ndi: %d e %i\nu: %u\n", c, s, d, i, ui);
	return (0);
}