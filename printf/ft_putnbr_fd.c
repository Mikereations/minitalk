/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aba-nabi <aba-nabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 17:56:00 by aba-nabi          #+#    #+#             */
/*   Updated: 2022/01/28 03:08:35 by aba-nabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	*ft_putnbr(int n, int *total)
{
	char	c;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*total) += 11;
		return (total);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		(*total)++;
		n = -n;
	}
	c = n % 10 + '0';
	if (n > 9)
	{
		n = n / 10 ;
		total = ft_putnbr(n, total);
	}
	(*total)++;
	ft_putchar_fd(c, 1);
	return (total);
}
