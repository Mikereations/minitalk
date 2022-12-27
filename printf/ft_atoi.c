/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aba-nabi <aba-nabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 23:50:19 by aba-nabi          #+#    #+#             */
/*   Updated: 2022/01/28 02:44:38 by aba-nabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_atoi(const char *str)
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
