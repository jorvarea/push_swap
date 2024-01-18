# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 19:52:12 by jorvarea          #+#    #+#              #
#    Updated: 2024/01/18 03:27:30 by jorvarea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					= push_swap

LIBFT_DIR 				= lib/libft
GET_NEXT_LINE_DIR		= lib/get_next_line
PRINTF_DIR 				= lib/printf
PUSH_SWAP_UTILS_DIR 	= lib/push_swap_utils

LIBFT 					= $(LIBFT_DIR)/libft.a
GET_NEXT_LINE			= $(GET_NEXT_LINE_DIR)/get_next_line.a
PRINTF 					= $(PRINTF_DIR)/printf.a
PUSH_SWAP_UTILS 		= $(PUSH_SWAP_UTILS_DIR)/push_swap_utils.a

CC						= gcc
CFLAGS 					= -Wall -Werror -Wextra -I$(LIBFT_DIR) -I$(GET_NEXT_LINE_DIR) -I$(PRINTF_DIR) -I$(PUSH_SWAP_UTILS_DIR)
SOURCE_DIR 				= src
SOURCE_FILES   			= $(wildcard $(SOURCE_DIR)/*.c)
OBJECT_DIR 				= obj
OBJECT_FILES			= $(SOURCE_FILES:$(SOURCE_DIR)/%.c=$(OBJECT_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJECT_FILES) $(LIBFT) $(GET_NEXT_LINE) $(PRINTF) $(PUSH_SWAP_UTILS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECT_FILES) $(LIBFT) $(GET_NEXT_LINE) $(PRINTF) $(PUSH_SWAP_UTILS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(GET_NEXT_LINE):
	$(MAKE) -C $(GET_NEXT_LINE_DIR)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

$(PUSH_SWAP_UTILS):
	$(MAKE) -C $(PUSH_SWAP_UTILS_DIR)

$(OBJECT_DIR)/%.o: $(SOURCE_DIR)/%.c
	mkdir -p $(OBJECT_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJECT_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(GET_NEXT_LINE_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean
	$(MAKE) -C $(PUSH_SWAP_UTILS_DIR) clean
	
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(GET_NEXT_LINE_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean
	$(MAKE) -C $(PUSH_SWAP_UTILS_DIR) fclean
	
re: fclean all

.PHONY: all clean fclean re