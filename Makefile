NAME		= libftprintf.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -MMD -MP
AR			= ar rcs
RM			= rm -rf

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

SRC_DIR		= src
INC_DIR		= inc
OBJ_DIR		= obj
INCLUDES	= -I $(INC_DIR) -I $(LIBFT_DIR)

SRC			= ft_printf.c \
			  ft_printf_utils.c

BONUS_SRC	= ft_printf_bonus.c \
			  ft_parse_bonus.c \
			  ft_convert_bonus.c \
			  ft_emit_bonus.c

OBJ			= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
BONUS_OBJ	= $(addprefix $(OBJ_DIR)/, $(BONUS_SRC:.c=.o))
DEPS		= $(OBJ:.o=.d) $(BONUS_OBJ:.o=.d)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJ)
	@$(RM) .bonus

bonus: .bonus

.bonus: $(LIBFT) $(BONUS_OBJ)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(BONUS_OBJ)
	@touch .bonus

$(LIBFT): FORCE
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJ_DIR) .bonus

fclean:
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(OBJ_DIR) .bonus $(NAME)

re: fclean all

FORCE:

-include $(DEPS)

.PHONY: all bonus clean fclean re FORCE
