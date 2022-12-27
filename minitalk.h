/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aba-nabi <aba-nabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 18:03:14 by aba-nabi          #+#    #+#             */
/*   Updated: 2022/04/14 18:44:41 by aba-nabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdint.h>

typedef struct		s_listener{
	uint8_t			bit;
	char			byte;
}					t_listener;

static t_listener	g_spy;
int					ft_atoi(const char *str);
void				sigusr2_handler(int sig, siginfo_t *info, void *context);

#endif
