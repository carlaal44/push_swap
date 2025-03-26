NAME = push_swap

SRC = 	source/push_swap.c \
		source/operations/sa.c \
		source/operations/sb.c \
		source/operations/pa.c \
		source/operations/pb.c \
		source/operations/ra.c \
		source/operations/rb.c \
		source/operations/rr.c \
		source/operations/rra.c \
		source/operations/rrb.c \
		source/operations/rrr.c \
		source/optimization/optimize_moves.c \
		source/sorting/sort_small_stack.c \
		source/sorting/sort_large_stack.c \
		source/stack/free_stack.c \
		source/stack/init_stack.c \
		source/stack/pop.c \
		source/stack/push_node.c \
		source/stack/push_value.c \
		source/stack/reverse_rotate.c \
		source/stack/rotate.c \
		source/stack/swap_stack.c \
		source/utils/stack_utils.c \
		source/utils/utils1.c \
		source/utils/utils2.c \
		source/validation/validate_input.c 
	
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -I include

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re