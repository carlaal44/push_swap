NAME = push_swap
BONUS = checker

# COLORS
RED		=	\033[91;1m
GREEN	=	\033[92;1m
CLEAR	=	\033[0m

CFLAGS = -Wall -Werror -Wextra -g3 -Ilibft/includes #-fsanitize=address
CC = cc
RM = rm -f

LIBFTA = libft/libft.a
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)


SRCS = $(addprefix ./source/, push_swap.c \
		movements/push.c movements/reverse_rotate.c movements/rotate.c movements/swap.c utils/free_matrix.c \
		stack/stack_creator.c stack/stack_properties.c stack/stack_sort.c stack/stack_utils.c stack/stack_setters.c)

SRCS_BONUS = $(addprefix ./source/, bonus/checker.c \
		movements/push.c movements/reverse_rotate.c movements/rotate.c movements/swap.c \
		stack/stack_creator.c stack/stack_properties.c stack/stack_utils.c)

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all : $(NAME)

bonus : $(BONUS)

$(NAME) : $(OBJS)
	@make all -sC ./libft
	@echo "$(GREEN)Compiling Libft.$(CLEAR)"
	@$(CC) $(CFLAGS) $(OBJS) -I ../push_swap.h $(LIBFTA) -o $(NAME)
	@echo "$(GREEN)Push Swap Compiled.$(CLEAR)"

$(BONUS) : $(OBJS_BONUS)
	@make all -sC ./libft
	@echo "$(GREEN)Compiling Libft.$(CLEAR)"
	@$(CC) $(CFLAGS) $(OBJS_BONUS) -I ../push_swap.h $(LIBFTA) -o $(BONUS)
	@echo "$(GREEN)Checker Compiled.$(CLEAR)"

clean:
	@$(RM) $(OBJS)
	@$(RM) $(OBJS_BONUS)
	@make clean -sC libft
	@echo "$(RED)All Objs Deleted.$(CLEAR)"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(BONUS)
	@$(RM) $(LIBFTA)
	@echo "$(RED)Everything Deleted.$(CLEAR)"

re: fclean all

.PHONY: all clean fclean re