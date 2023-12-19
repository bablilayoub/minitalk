LIBS = ./includes/libftprintf.a ./includes/libft.a
CFLASG = -Wall -Wextra -Werror
NAME = minitalk

$(NAME): client server

all: $(NAME)

client: client.c
	cc $(CFLASG) client.c $(LIBS) -o client

server: server.c
	cc $(CFLASG) server.c $(LIBS) -o server

clean:
	rm -f server client

fclean : clean

re: clean all