NAME = push_swap

CC = cc
CFLAGS = -g -Wall -Wextra -Werror -Ilibft -Iincludes

SRC = src/bubble_sort.c \
		src/discretization.c \
		src/handle_a.c \
		src/handle_b.c \
		src/handle_both.c \
		src/handle_linked_list.c \
		src/init_stack.c \
		src/push_swap.c \
		src/radix_sort.c \
		src/sort_cases.c \
		src/utils.c \
		src/validate.c

OBJ = $(SRC:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

N ?= 500

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

test:
	@ARGS=$$(shuf -i 1-10000 -n $(N) | tr '\n' ' ' | sed 's/ $$//'); \
	echo "Testing with $(N) numbers:"; \
	echo "Total of commands:"; \
	./push_swap "$$ARGS" | wc -l; \
	echo "Results:"; \
	./push_swap "$$ARGS" | ./checker_linux "$$ARGS"

.PHONY: all clean fclean re test
