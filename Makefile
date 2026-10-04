# **************************************************************************** #
#                                                                              #
#                                                        :::      ::::::::     #
#    Makefile                                          :+:      :+:    :+:     #
#                                                    +:+ +:+         +:+       #
#    By: kseltenr <kseltenr@student.42.fr>         #+#  +:+       +#+          #
#                                                +#+#+#+#+#+   +#+             #
#    Created: 2026/09/26 11:59:16 by kseltenr         #+#    #+#               #
#    Updated: 2026/10/05 00:35:39 by kseltenr        ###   ########.fr         #
#                                                                              #
# **************************************************************************** #

NAME		= 42_ft_printf.a

CC			= cc
AR			= ar
ARFLAGS		= rcs
CFLAGS		= -Wall -Wextra -Werror
CPPFLAGS	= -MMD -MP -I inc -I libft
DEBUG		?= 0
RM		= rm -f

JOBS		?= $(shell nproc)
MAKEFLAGS	+= -j $(JOBS) -l $(JOBS)

ifeq ($(DEBUG),1)
CFLAGS		+= -g3
CPPFLAGS	+= -DDEBUG=1
endif

SRC_DIR		= src
OBJ_DIR		= obj
INC_DIR		= inc
LIBFT_DIR	= libft

LIBFT		= $(LIBFT_DIR)/libft.a
SRCS		= $(SRC_DIR)/ft_printf.c $(SRC_DIR)/convertion.c
OBJS		= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
DEPS		= $(OBJS:.o=.d)

COMPILE_DB	= compile_commands.json

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	cp $(LIBFT) $(NAME)
	$(AR) $(ARFLAGS) $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c Makefile
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) -r $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) clean

re:
	$(MAKE) fclean
	$(MAKE) all

-include $(DEPS)

.PHONY: all clean fclean re
.DEFAULT_GOAL := all
