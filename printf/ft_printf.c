/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aba-nabi <aba-nabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:32:49 by aba-nabi          #+#    #+#             */
/*   Updated: 2022/01/28 04:06:42 by aba-nabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static const char	*get_there(const char *s, int *total)
{
	char	*loc;

	loc = ft_strchr(s, '%');
	if (loc)
	{
		while (s < loc)
		{
			write(1, s++, 1);
			(*total)++;
		}
		s++;
	}
	else
	{
		while (*s)
		{
			write(1, s++, 1);
			(*total)++;
		}
	}
	return (s);
}

static int	*ifs(char c, long long d, int *total, t_flags *f)
{
	if (c == 'p' || (c == 'x' && f->hash * d) || (c == 'X' && f->hash * d))
	{
		if (c == 'X' && (unsigned int)d)
			write(1, "0X", 2);
		else if (c == 'x' && (unsigned int)d)
			write(1, "0x", 2);
		else
			write(1, "0x", 2);
		(*total) += 2;
	}
	else if ((int)d >= 0 && (c == 'i' || c == 'd') && (f->plus || f->spac))
	{
		if (f->plus)
			write(1, "+", 1);
		else if (f->spac)
			write(1, " ", 1);
		(*total)++;
	}
	return (total);
}

static void	handle_numbers(char c, long long int d, int *total, t_flags *f)
{
	total = ifs(c, d, total, f);
	if (c == 'p')
		ft_putnbr_b((unsigned long long)d, "0123456789abcdef", total);
	else if (c == 'x')
		total = ft_putnbr_b((unsigned int)d, "0123456789abcdef", total);
	else if (c == 'X')
		total = ft_putnbr_b((unsigned int)d, "0123456789ABCDEF", total);
	else if (c == 'u')
		total = ft_putnbr_b((unsigned int)d, "0123456789", total);
	else
	{
		total = ft_putnbr((int)d, total);
	}
}

static void	handle_strings(char c, char *s, int *total, int flag)
{
	if (flag)
	{
		if (s)
		{
			(*total) += ft_strlen(s);
			ft_putstr_fd(s, 1);
		}
		else
		{
			(*total) += 6;
			write(1, "(null)", 6);
		}
	}
	else
	{
		(*total) += 1;
		ft_putchar_fd(c, 1);
	}
}

int	ft_printf(const char *s, ...)
{
	va_list	pa;
	t_flags	f;
	int		t;

	t = 0;
	va_start(pa, s);
	while (*s)
	{
		s = get_there(s, &t);
		s = initiate_flag(s, &f);
		if (*s == 'x' || *s == 'X')
			handle_numbers(*s, va_arg(pa, unsigned int), &t, &f);
		if (*s == 'i' || *s == 'd' || *s == 'u' || *s == 'p')
			handle_numbers(*s, va_arg(pa, long long int), &t, &f);
		else if (*s == 'c')
			handle_strings(va_arg(pa, int), 0, &t, 0);
		else if (*s == 's')
			handle_strings(0, va_arg(pa, char *), &t, 1);
		else if (*s == '%')
			handle_strings('%', 0, &t, 0);
		if (*s)
			s++;
	}
	va_end(pa);
	return (t);
}
