/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeskhai <maeskhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:39:23 by maeskhai          #+#    #+#             */
/*   Updated: 2024/11/30 11:04:17 by maeskhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int	ft_puthexa(unsigned int n, char format)
{
	int		count;
	char	*s;

	s = "0123456789abcdef";
	count = 0;
	if (format == 'X')
		s = "0123456789ABCDEF";
	if (n < 16)
		count += ft_putchar(s[n]);
	else
	{
		count += ft_puthexa(n / 16, format);
		count += ft_putchar(s[n % 16]);
	}
	return (count);
}
