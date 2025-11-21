NAME = push_swap
NAME_BONUS = 

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
		src/utils.c \
		src/validate.c

SRC_BONUS = src_bonus/so_long_bonus.c \
		src_bonus/clear_bonus.c \
		src_bonus/render_map_bonus.c\
		src_bonus/handle_map_bonus.c\
		src_bonus/validate_arguments_bonus.c\
		src_bonus/game_bonus.c\
		src_bonus/interaction_bonus.c\
		src_bonus/validate_map_bonus.c\
		src_bonus/utils_bonus.c

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS) $(LIBFT)
	$(CC) $(OBJ_BONUS) $(LIBFT) -o $(NAME_BONUS)

clean:
	rm -f $(OBJ) $(OBJ_BONUS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	make fclean -C $(LIBFT_DIR)

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re
