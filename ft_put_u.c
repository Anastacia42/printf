/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansilva- <ansilva-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:51:28 by ansilva-          #+#    #+#             */
/*   Updated: 2022/03/04 15:19:58 by ansilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_put_u(unsigned int n)
{
	int		i;
	char	*s;
	char	*base;

	i = 0;
	base = "0123456789";
	s = ft_put_base(n, base);
	i += ft_putstr(s);
	free (s);
	return (i);
}