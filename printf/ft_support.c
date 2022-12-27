/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_support.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aba-nabi <aba-nabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 19:28:17 by aba-nabi          #+#    #+#             */
/*   Updated: 2022/01/28 01:41:24 by aba-nabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static t_flags	*capture_the_flag(const char *s, t_flags *flags, char *t)
{
	while (*s)
	{
		t[0] = *s;
		if (*s == '+')
			flags->plus = 1;
		else if (*s == '-')
			flags->minu = 1;
		else if (*s == '0')
			flags->xero = 1;
		else if (*s == '#')
			flags->hash = 1;
		else if (*s == ' ')
			flags->spac = 1;
		else if (*s == '.')
		{
			flags->dott = 1;
			flags->digs = ft_atoi(s + 1);
		}
		else if (ft_strnstr("uidxXpcs%", t, 9))
			break ;
		s++;
	}
	return (flags);
}

const char	*initiate_flag(const char *s, t_flags *flags)
{
	char	t[2];

	if (*s)
	{
		t[1] = 0;
		flags->dott = 0;
		flags->hash = 0;
		flags->minu = 0;
		flags->plus = 0;
		flags->spac = 0;
		flags->xero = 0;
		flags->digs = -1;
		flags = capture_the_flag(&(*s), flags, t);
		t[0] = *s;
		while (!ft_strnstr("uidxXpcs%", t, 9))
		{
			s++;
			t[0] = *s;
		}
	}
	return (s);
}
