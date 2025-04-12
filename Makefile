### COLOURS ###
PINK 	= \e[1;35m
PURPLE	= \e[0;95m
WHITE   = \e[1;37m
DEFAULT = \e[0m

### VARIABLES ###
NAME			= so_long

CC				= cc
CFLAGS			= -Wall -Wextra -Werror -g

SRCS	 		= $(SRC_DIR)so_long.c $(SRC_DIR)parsing.c $(SRC_DIR)free_exit_error.c $(SRC_DIR)map_utils.c \
				  $(SRC_DIR)mlx_init.c $(SRC_DIR)load_images.c
SRC_DIR			= src/

OBJS 			= $(SRCS:%.c=%.o)

### COMPLETE LIB ###
LIBFT_PATH		= complete_lib/42_Libft/
LIBFT			= $(LIBFT_PATH)libft.a
FT_PRINTF_PATH	= complete_lib/42_Printf/
FT_PRINTF		= $(FT_PRINTF_PATH)libftprintf.a
GNL_PATH		= complete_lib/42_GNL/
GNL				= $(GNL_PATH)libgnl.a
PERSONAL_LIBS	= -lft -lgnl -lftprintf

### MLX COMPILE FLAGS ###
MLX_CC			= -L complete_lib/minilibx-linux -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
MLX_INC			= -I/usr/include -Imlx_linux -O3 

INCLUDE			= -I inc/

### RULES ###
%.o: 			%.c
				@$(CC) $(CFLAGS) $(MLX_INC) -c $(<) -o $(@)

all: 			$(NAME)

$(NAME): 		$(OBJS) $(LIBFT) $(FT_PRINTF) $(GNL)
				@echo "$(WHITE)Bringing $(PINK)$(NAME)$(WHITE) to life!$(DEFAULT)"
				@echo "$(WHITE)Creating $(PINK)$(NAME)'s$(WHITE) executable...$(DEFAULT)"
				@$(CC) $(CFLAGS) $(OBJS)  $(MLX_CC) -L$(LIBFT_PATH) -L$(FT_PRINTF_PATH) -L$(GNL_PATH) $(PERSONAL_LIBS) -o $(NAME)
				@echo "$(PINK)$(NAME) was born!$(DEFAULT)"



### MAKE LIB ###
$(LIBFT):
				@make -s -C $(LIBFT_PATH)

$(FT_PRINTF):
				@make -s -C $(FT_PRINTF_PATH)

$(GNL):
				@make -s -C $(GNL_PATH)

### CLEAN RULES ###
clean:
				@make -s -C $(LIBFT_PATH) clean
				@make -s -C $(FT_PRINTF_PATH) clean
				@make -s -C $(GNL_PATH) clean
				@rm -rf $(OBJS)
				@echo "$(WHITE)✩°｡⋆ $(PINK)Files Cleaned$(WHITE) ⋆｡°✩ \n \
	(\ (\    \n \
( ~_•)    \n \
(っ▄︻▇〓▄︻┻┳═ ─ ҉.  \n \
 /　 )  / \    \n \
(/￣∪  /   \ $(DEFAULT)"

fclean: 		clean
				@make -s -C $(LIBFT_PATH) fclean
				@make -s -C $(FT_PRINTF_PATH) fclean
				@make -s -C $(GNL_PATH) fclean
				@rm -f $(NAME)
				@echo "$(WHITE)⋆˚࿔ Executable Killed˚⋆♡$(DEFAULT)"

re: 			fclean all

.PHONY: 		all clean fclean re