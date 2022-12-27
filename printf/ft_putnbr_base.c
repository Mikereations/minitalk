/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aba-nabi <aba-nabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:27:14 by aba-nabi          #+#    #+#             */
/*   Updated: 2022/01/27 18:53:56 by aba-nabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	*ft_putnbr_b(unsigned long long nbr, char *base, int *total)
{
	int		v;
	char	c;
	int		arth;

	c = 0;
	v = ft_strlen(base);
	if (v)
	{
		arth = nbr % v;
		c = base[arth];
		if (nbr / v > 0)
			ft_putnbr_b(nbr / v, base, total);
		write(1, &c, 1);
		(*total)++;
		return (total);
	}
	return (total);
}
