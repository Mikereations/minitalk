/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aba-nabi <aba-nabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 18:23:50 by aba-nabi          #+#    #+#             */
/*   Updated: 2022/04/15 20:50:03 by aba-nabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdint.h>
#include "printf/libftprintf.h"

void	sigusr1_handler(int sig, siginfo_t *info, void *context)
{
	if (g_spy.bit == 0)
	{
		g_spy.bit = 1 << 7;
		g_spy.byte = 0;
	}
	g_spy.byte += g_spy.bit;
	g_spy.bit >>= 1;
	kill(info->si_pid, SIGUSR2);
}

void	sigusr2_handler(int sig, siginfo_t *info, void *context)
{
	if (g_spy.bit == 0)
	{
		g_spy.bit = 1 << 7;
		g_spy.byte = 0;
	}
	g_spy.bit >>= 1;
	if (!g_spy.byte && g_spy.bit == 0)
		kill(info->si_pid, SIGUSR1);
	else
		kill(info->si_pid, SIGUSR2);
}

void	listener(void)
{
	int i;

	i = 0;
	while (1)
	{
		pause();
		if (!g_spy.bit)
		{
			if (!g_spy.byte)
				write(1, "\n", 1);
			else
				write(1, &(g_spy.byte), sizeof(g_spy.byte));
			g_spy.bit = 1 << 7;
			g_spy.byte = 0;
		}
	}
}

int		main(void)
{
	struct sigaction	usr1a;
	struct sigaction	usr2a;

	usr1a.sa_flags = SA_SIGINFO;
	usr2a.sa_flags = SA_SIGINFO;
	g_spy.byte = 0;
	g_spy.bit = 1 << 7;
	usr1a.__sigaction_u.__sa_sigaction = sigusr1_handler;
	usr2a.__sigaction_u.__sa_sigaction = sigusr2_handler;
	sigaction(SIGUSR1, &usr1a, NULL);
	sigaction(SIGUSR2, &usr2a, NULL);
	ft_printf("The server started : the process ID is : %d\n", getpid());
	listener();
	return (0);
}
