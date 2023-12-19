MANDA_SRCS =    ft_atoi.c

NAME = libft.a
HEADER = libft.h
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBC = ar rcs
RM = rm -f
MANDA_OBJ = $(MANDA_SRCS:.c=.o)

$(NAME): $(MANDA_OBJ)
	@$(LIBC) $(NAME) $(MANDA_OBJ)

all: $(NAME)

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(MANDA_OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: clean