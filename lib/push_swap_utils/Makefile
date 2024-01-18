# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/18 02:13:38 by jorvarea          #+#    #+#              #
#    Updated: 2024/01/18 03:15:02 by jorvarea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= push_swap_utils.a

LIBFT_DIR 			= ../libft
PRINTF_DIR 			= ../printf

CC					= gcc
CFLAGS				= -Wall -Werror -Wextra -I$(LIBFT_DIR) -I$(PRINTF_DIR)
SOURCE_FILES   		= $(wildcard *.c)
OBJECT_DIR 			= obj
OBJECT_FILES		= $(SOURCE_FILES:%.c=$(OBJECT_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJECT_FILES) push_swap_utils.h
	@ar -rcs $(NAME) $(OBJECT_FILES)

$(OBJECT_DIR)/%.o: %.c
	@mkdir -p $(OBJECT_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJECT_DIR)
	
fclean: clean
	@rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re