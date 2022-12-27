/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aba-nabi <aba-nabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:11:40 by aba-nabi          #+#    #+#             */
/*   Updated: 2022/01/28 04:20:22 by aba-nabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_flags
{
	char	plus;
	char	hash;
	char	spac;
	char	xero;
	char	dott;
	char	minu;
	int		digs;
}	t_flags;

int			ft_printf(const char *str, ...);
int			*ft_putnbr_b(unsigned long long nbr, char *base, int *total);
const char	*initiate_flag(const char *s, t_flags *flags);
size_t		ft_strlen(const char *s);
char		*ft_strchr(const char *s, int c);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
int			ft_atoi(const char *str);
char		*ft_itoa(int n);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
int			*ft_putnbr(int n, int *total);

#endif
