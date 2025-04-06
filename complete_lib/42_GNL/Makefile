###VARABLES###
NAME	= libgnl.a

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g

SRCS	= get_next_line_bonus.c get_next_line_utils_bonus.c

OBJS	= $(SRCS:.c=.o)

###RULES###
%.o: %.c
		@$(CC) $(CFLAGS) -I. -c $(<) -o $(@)

$(NAME): $(OBJS)
		@ar -rcs $(NAME) $(OBJS)

all: 	$(NAME)

clean:
		@rm -rf $(OBJS)

fclean: clean
		@rm -f $(NAME)

re: 	fclean all

.PHONY: all clean fclean re