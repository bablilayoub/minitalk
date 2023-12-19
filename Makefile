NAME = minitalk
CFLAGS = -Wall -Wextra -Werror
LIBS = ./includes/ft_printf/libftprintf.a ./includes/libft/libft.a
HEADER = minitalk.h
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

clean:
	@echo "Cleaning ..."
	@rm -f server client
	@cd ./includes/libft && make clean
	@cd ./includes/ft_printf && make clean
	@echo "Done with cleaning"

fclean : clean
	@echo "Force cleaning ..."
	@cd ./includes/libft && make fclean
	@cd ./includes/ft_printf && make fclean
	@echo "Done with force cleaning"

re: fclean all

.PHONY: all comp_start clean fclean re