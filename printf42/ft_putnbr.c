/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeskhai <maeskhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:39:30 by maeskhai          #+#    #+#             */
/*   Updated: 2024/11/30 11:04:24 by maeskhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	long	nb;
	int		total;

	total = 0;
	nb = n;
	if (nb < 0)
	{
		total += ft_putchar('-');
		nb *= -1;
	}
	if (nb > 9)
	{
		total += ft_putnbr(nb / 10);
		total += ft_putchar((nb % 10) + 48); 
	}
	else
		total += ft_putchar(nb + 48);
	return (total);
}
