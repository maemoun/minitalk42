/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeskhai <maeskhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:07:20 by maeskhai          #+#    #+#             */
/*   Updated: 2025/02/10 11:56:10 by maeskhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signum, siginfo_t *info, void *context)
{
	static int		i;
	static char		c;

	(void)context;
	c = c << 1;
	if (signum == SIGUSR1)
		c = c | 1;
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		c = 0;
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	action;

	ft_printf("SERVER PID = %d\n", getpid());
	action.sa_sigaction = handler;
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (2025)
	{
		pause();
	}
	return (EXIT_SUCCESS);
}
