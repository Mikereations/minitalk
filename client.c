/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aba-nabi <aba-nabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 18:02:25 by aba-nabi          #+#    #+#             */
/*   Updated: 2022/04/15 19:24:02 by aba-nabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft/libft.h"

void	singal_error(void)
{
	write(1, "Error recieving a signal\n", 26);
	exit(1);
}

void	activate_signal(char c, int pid)
{
	uint8_t	mask;
	int		bc;

	bc = 1;
	mask = 1 << 7;
	while (mask)
	{
		if (c & mask)
		{
			if (kill(pid, SIGUSR1) == -1)
				singal_error();
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				singal_error();
		}
		mask >>= 1;
		bc++;
		pause();
		usleep(600);
	}
}

void	send_message(char *message, int pid)
{
	int		i;

	i = 0;
	while (message[i])
	{
		activate_signal(message[i], pid);
		i++;
	}
	activate_signal(message[i], pid);
}

void	sigusr_handler(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	write(1, "Finshed writing the sent message\n", 34);
}

int		main(int argc, char **argv)
{
	struct sigaction	sa;
	struct sigaction	sa2;
	int					pid;

	if (argc != 3)
	{
		write(1, "invalid number of parameters\n", 29);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	sa.sa_flags = SA_SIGINFO;
	sa2.sa_flags = SA_SIGINFO;
	sa.__sigaction_u.__sa_sigaction = sigusr_handler;
	sa2.__sigaction_u.__sa_sigaction = sigusr2_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa2, NULL);
	send_message(argv[2], pid);
	return (0);
}
