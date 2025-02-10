/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeskhai <maeskhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:49:04 by maeskhai          #+#    #+#             */
/*   Updated: 2024/11/30 11:05:16 by maeskhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_add(unsigned long n)
{
	int		count;
	char	*s;

	count = 0;
	s = "0123456789abcdef";
	if (n < 16)
		count += ft_putchar(s[n]);
	else
	{
		count += ft_add(n / 16);
		count += ft_putchar(s[n % 16]);
	}
	return (count);
}

int	ft_putadd(void *p)
{
	unsigned long	nb;
	int				count;

	count = 0;
	nb = (unsigned long)p;
	count += ft_putstr("0x");
	count += ft_add(nb);
	return (count);
}
