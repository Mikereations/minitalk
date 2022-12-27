NAME = minitalk

SOURCES = client.c utils.c

SERVER = server.c

OBJECTS = $(SOURCES:.c=.o);

CFLAGS = -Wall -Werror -Wall

CC = gcc

PRINTF = ./printf/libftprintf.a

${NAME} :
	$(MAKE) -C ./printf
	${CC} ${CFLAGS} -o client $(SOURCES)
	${CC} ${CFLAGS} -o server $(SERVER) $(PRINTF)


all : ${NAME}

clean :
	$(MAKE) clean -C ./printf

bonus : $(NAME)

fclean : clean
	rm -f server client

re : fclean all
