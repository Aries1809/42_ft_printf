# **************************************************************************** #
#                                                                              #
#                                                        :::      ::::::::     #
#    Makefile                                          :+:      :+:    :+:     #
#                                                    +:+ +:+         +:+       #
#    By: kseltenr <kseltenr@student.42.fr>         #+#  +:+       +#+          #
#                                                +#+#+#+#+#+   +#+             #
#    Created: 2026/09/26 11:59:16 by kseltenr         #+#    #+#               #
#    Updated: 2026/10/06 15:54:52 by kseltenr        ###   ########.fr         #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
NAME_B		= libftprintf_bonus.a

CC			= cc
AR			= ar
ARFLAGS		= rcs
CFLAGS		= -Wall -Wextra -Werror
CPPFLAGS	= -MMD -MP -I inc -I libft
CPPFLAGS_B	= -MMD -MP -I inc_bonus -I libft
DEBUG		?= 0
RM		= rm -f

JOBS		?= $(shell nproc)
MAKEFLAGS	+= -j $(JOBS) -l $(JOBS)

ifeq ($(DEBUG),1)
CFLAGS		+= -g3
CPPFLAGS	+= -DDEBUG=1
endif

SRC_DIR		= src
SRC_B_DIR	= src_bonus
OBJ_DIR		= obj
OBJ_B_DIR	= obj_bonus
INC_DIR		= inc
INC_B_DIR	= inc_bonus
LIBFT_DIR	= libft

LIBFT		= $(LIBFT_DIR)/libft.a
SRCS		= $(SRC_DIR)/ft_printf.c $(SRC_DIR)/convertion.c $(SRC_DIR)/helpers.c
SRCS_B		= $(SRC_B_DIR)/ft_printf_bonus.c
OBJS		= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJS_B		= $(SRCS_B:$(SRC_B_DIR)/%.c=$(OBJ_B_DIR)/%.o)
DEPS		= $(OBJS:.o=.d) $(OBJS_B:.o=.d)

COMPILE_DB	= compile_commands.json

all: $(NAME)

bonus: $(NAME_B)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME_B): $(OBJS_B) $(LIBFT)
	cp $(LIBFT) $(NAME_B)
	$(AR) $(ARFLAGS) $@ $^

$(NAME): $(OBJS) $(LIBFT)
	cp $(LIBFT) $(NAME)
	$(AR) $(ARFLAGS) $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c Makefile
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJ_B_DIR)/%.o: $(SRC_B_DIR)/%.c Makefile
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(CPPFLAGS_B) -c $< -o $@

clean:
	$(RM) -r $(OBJ_DIR) $(OBJ_B_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME) $(NAME_B)
	$(MAKE) -C $(LIBFT_DIR) clean

re:
	$(MAKE) fclean
	$(MAKE) all

-include $(DEPS)

.PHONY: all clean fclean re bonus
.DEFAULT_GOAL := all
