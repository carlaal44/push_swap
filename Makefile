NAME = push_swap

SRC = 	source/push_swap.c \
		source/validation/validate_input.c \
		source/stack/init_stack \
		source/stack/push.c \
		source/stack/pop.c \
		source/stack/free_stack.c \
		source/operations/sa.c \
		source/operations/sb.c \
		source/operations/ss.c \
		source/operations/pa.b \
		source/operations/pb.c \
		source/operations/ra.c \
		source/operations/rb.c \
		source/operations/rr.c \
		source/operations/rra.c \
		source/operations/rrb.c \
		source/operations/rrr.b \
		source/sorting/sort_small_stack.c \
		source/sorting/sort_large_stack.c \
		source/sorting/optimize_moves.c \
		source/utils/utils.c
	
OBJ = $(SRC_ .c=.o)
CC = cc;
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I include

all: $(NAME)

$NAME: $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re