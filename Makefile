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

client: client.c $(HEADER)
	$(CC) $(CFLAGS) client.c $(LIBS) utils.c -o client

server: server.c $(HEADER)
	$(CC) $(CFLAGS) server.c $(LIBS) utils.c -o server

client_bonus: client_bonus.c $(BONUS_HEADER)
	$(CC) $(CFLAGS) client_bonus.c $(LIBS) utils_bonus.c -o client_bonus

server_bonus: server_bonus.c $(BONUS_HEADER)
	$(CC) $(CFLAGS) server_bonus.c $(LIBS) utils_bonus.c -o server_bonus

bonus: client_bonus server_bonus

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