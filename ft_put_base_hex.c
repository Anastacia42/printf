/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_base_hex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansilva- <ansilva-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 10:58:15 by ansilva-          #+#    #+#             */
/*   Updated: 2022/03/08 14:37:25 by ansilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_put_base_hex(unsigned int nb, char *base)
{
	int				len;
	size_t			len_base;
	unsigned int	n;
	char			*s;

	n = nb;
	len = 0;
	len_base = ft_strlen(base);
	while (n > 0)
	{
		n /= len_base;
		len++;
	}
	s = malloc(sizeof(*s) * (len + 1));
	if (s == NULL)
		return (NULL);
	while (nb > 0)
	{
		s[--len] = base[nb % len_base];
		nb /= len_base;
	}
	s[len_base - 1] = '\0';
	return (s);
}
