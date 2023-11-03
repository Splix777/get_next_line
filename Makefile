SRCS =	get_next_line.c \
		get_next_line_utils.c

SRCSB = get_next_line_bonus.c \
		get_next_line_utils_bonus.c

NAME = gnl.a

OBJS_DIR = objs/
OBJS = $(SRCS:.c=.o)
OBJECTS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))

OBJSB = $(SRCSB:.c=.o)
OBJECTS_BONUS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJSB))

CC = gcc

CC_FLAGS = -Wall -Wextra -Werror

$(OBJS_DIR)%.o : %.c get_next_line.h
	@mkdir -p $(OBJS_DIR)
	@echo "Compiling: $<"
	@$(CC) $(CC_FLAGS) -c $< -o $@

$(NAME): $(OBJECTS_PREFIXED)
	@ar rcs $(NAME) $(OBJECTS_PREFIXED)
	@echo "Complete"

all: $(NAME)

clean:
	@rm -rf $(OBJS_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

bonus: $(OBJECTS_BONUS_PREFIXED)

$(OBJECTS_BONUS_PREFIXED): $(OBJS_DIR)%.o : %.c get_next_line_bonus.h
	@echo "Compiling Bonus: $<"
	@$(CC) $(CC_FLAGS) -c $< -o $@

.PHONY: all clean fclean re bonus
