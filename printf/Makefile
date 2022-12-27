# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aba-nabi <aba-nabi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/22 12:33:29 by aba-nabi          #+#    #+#              #
#    Updated: 2022/01/28 12:49:50 by aba-nabi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -*-MakeFile -*-
NAME = libftprintf.a 
FILES = ft_printf.c ft_support.c ft_putnbr_base.c ft_putnbr_fd.c ft_putstr_fd.c ft_putchar_fd.c ft_atoi.c ft_strnstr.c ft_strnstr.c ft_strchr.c ft_strlen.c 
OBJS = ${FILES:.c=.o}

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

.c.o :
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME} : ${OBJS}
	ar rcs ${NAME} ${OBJS}

all : ${NAME}

bonus : ${OBJS}
	ar rcs ${NAME} ${OBJS}
clean:
	${RM} ${OBJS}

fclean : clean
	${RM} $(NAME)
re: fclean all
