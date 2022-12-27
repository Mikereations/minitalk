/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aba-nabi <aba-nabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 18:19:08 by aba-nabi          #+#    #+#             */
/*   Updated: 2022/04/14 18:42:55 by aba-nabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		ft_atoi(const char *str)
{
	int		n;
	size_t	sum;

	sum = 0;
	n = 1;
	while ((*str == ' ' || (*str >= 9 && *str <= 13)) && *str)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			n = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		sum = sum * 10 + *str++ - '0';
	if ((sum) >= 9223372036854775807)
	{
		if (n == -1)
			return (0);
		else
			return (-1);
	}
	return (sum * n);
}

void	sigusr2_handler(int sig, siginfo_t *info, void *context)
{
	(void)sig;
}
