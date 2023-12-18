LIBS = ./includes/libftprintf.a ./includes/libft.a
CFLASG = -Wall -Wextra -Werror

all: client server


client: client.c $(LIBS)
	cc $(CFLASG) client.c $(LIBS) -o client

server: server.c $(LIBS)
	cc $(CFLASG) server.c $(LIBS) -o server

clean:
	rm -f server client

fclean : clean

re: clean all