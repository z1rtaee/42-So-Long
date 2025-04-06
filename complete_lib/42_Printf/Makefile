NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRCS = ft_printf.c
OBJS = $(SRCS:.c=.o)
AR = ar -rcs

%.o: %.c
	$(CC) $(CFLAGS) -I. -c $(<) -o $(@)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)

all: $(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

comp: fclean all
	@$(CC) $(CFLAGS) test.c $(NAME) 

run: comp
	@./a.out
	@make fclean --no-print-directory
	@rm -f a.out

.PHONY: all clean fclean re comp run