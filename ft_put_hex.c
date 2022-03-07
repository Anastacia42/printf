/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansilva- <ansilva-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:37:20 by ansilva-          #+#    #+#             */
/*   Updated: 2022/03/07 15:02:48 by ansilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_hex(unsigned long n, char format)
{
	int		i;
	char	*s;
	char	*base;

	i = 0;
	if (n == 0)
		return (i += ft_putstr("0"));
	if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	s = ft_put_base_hex(n, base);
	i += ft_putstr(s);
	free (s);
	return (i);
}