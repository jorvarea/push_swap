# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/18 01:14:21 by jorvarea          #+#    #+#              #
#    Updated: 2024/01/18 01:35:59 by jorvarea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= libft.a
CC					= gcc
CFLAGS				= -Wall -Werror -Wextra
SOURCE_FILES   		= $(wildcard *.c)
OBJECT_DIR 			= obj
OBJECT_FILES		= $(SOURCE_FILES:%.c=$(OBJECT_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJECT_FILES) libft.h
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