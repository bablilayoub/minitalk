NAME = minitalk
CFLAGS = -Wall -Wextra -Werror
LIBS = ./includes/ft_printf/libftprintf.a ./includes/libft/libft.a
HEADER = minitalk.h
BONUS_HEADER = minitalk_bonus.h
CC = cc

all: $(NAME)
	@echo "You are ready to go !"

$(NAME): comp_start client server

comp_start:
	@echo "Preparing libraries ..."
	@cd ./includes/libft && make
	@cd ./includes/ft_printf && make

client: client.c $(HEADER)
	@echo "Making client ..."
	@$(CC) $(CFLAGS) client.c $(LIBS) -o client
	@echo "Client is ready !"

server: server.c $(HEADER)
	@echo "Making server ..."
	@$(CC) $(CFLAGS) server.c $(LIBS) -o server
	@echo "Server is ready !"

client_bonus: client_bonus.c $(BONUS_HEADER)
	@echo "Making bonus client ..."
	@$(CC) $(CFLAGS) client_bonus.c $(LIBS) -o client_bonus
	@echo "Bonus client is ready !"

server_bonus: server_bonus.c $(BONUS_HEADER)
	@echo "Making bonus server ..."
	@$(CC) $(CFLAGS) server_bonus.c $(LIBS) -o server_bonus
	@echo "Bonus server is ready !"

bonus: comp_start client_bonus server_bonus

clean:
	@echo "Cleaning ..."
	@rm -f server client
	@rm -f server_bonus client_bonus
	@cd ./includes/libft && make clean
	@cd ./includes/ft_printf && make clean
	@echo "Done with cleaning"

fclean : clean
	@echo "Force cleaning ..."
	@rm -f server client
	@rm -f server_bonus client_bonus
	@cd ./includes/libft && make fclean
	@cd ./includes/ft_printf && make fclean
	@echo "Done with force cleaning"

re: fclean all

.PHONY: all comp_start clean fclean re