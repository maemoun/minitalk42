/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeskhai <maeskhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:01:08 by maeskhai          #+#    #+#             */
/*   Updated: 2025/02/10 12:41:14 by maeskhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	handler(int signum, siginfo_t *info, void *context)
{
	(void)context;
	static int i;
	static int j = 31;
	static char c;
	static char *str = NULL;
	static int len;
	static int index;
	static pid_t client_pid;

	if (client_pid != info->si_pid)
		client_pid = info->si_pid;

	
	if(j >= 0)
	{
		len = len << 1;
		if (signum == SIGUSR1)
			len = len | 1;
		j--;
		if (j == -1 && len > 0)
		{
			str = malloc(len + 1);
			if (!str)
				exit(1);
		}
	}
	else
	{
		c = c << 1;
        if (signum == SIGUSR1)
            c = c | 1;
        i++;

        if (i == 8)
        {
            str[index++] = c;
            c = 0;
            i = 0;

            if (index == len)
            {
                str[index] = '\0';
                ft_printf("%s\n", str);
                free(str);
                str = NULL;
                len = 0;
                j = 31;
                index = 0;
				kill(info->si_pid, SIGUSR1);
            }
        }
	}
}

int	main(void)
{
	struct	sigaction action;

	ft_printf("SERVER PID = %d\n", getpid());
	action.sa_sigaction = handler;
	action.sa_flags = SA_SIGINFO;

	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);

	while (1)
	{
		pause();
	}
	return (EXIT_SUCCESS);
}
