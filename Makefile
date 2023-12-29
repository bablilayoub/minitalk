NAME			=	minitalk
CFLAGS			=	-Wall -Wextra -Werror
LIBS			=	./includes/ft_printf/libftprintf.a ./includes/libft/libft.a
HEADER			=	minitalk.h
BONUS_HEADER	=	minitalk_bonus.h
CC				=	cc

all: $(NAME)

$(NAME): comp_start client server

comp_start:
	cd ./includes/libft && make
	cd ./includes/ft_printf && make

client: client.c utils.c $(HEADER)
	$(CC) $(CFLAGS) client.c utils.c $(LIBS) -o client

server: server.c utils.c $(HEADER)
	$(CC) $(CFLAGS) server.c utils.c $(LIBS) -o server

client_bonus: client_bonus.c utils_bonus.c $(BONUS_HEADER)
	$(CC) $(CFLAGS) client_bonus.c utils_bonus.c $(LIBS) -o client_bonus

server_bonus: server_bonus.c utils_bonus.c $(BONUS_HEADER)
	$(CC) $(CFLAGS) server_bonus.c utils_bonus.c $(LIBS) -o server_bonus

bonus: comp_start client_bonus server_bonus

clean:
	rm -f server client
	rm -f server_bonus client_bonus
	cd ./includes/libft && make clean
	cd ./includes/ft_printf && make clean

fclean : clean
	rm -f server client
	rm -f server_bonus client_bonus
	cd ./includes/libft && make fclean
	cd ./includes/ft_printf && make fclean

re: fclean all

.PHONY: comp_start clean