# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 19:52:12 by jorvarea          #+#    #+#              #
#    Updated: 2023/11/14 20:45:39 by jorvarea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= libftprintf.a
LIBFT 				= libft/libft.a
CC					= gcc
CFLAGS				= -Wall -Werror -Wextra
SOURCE_FILES   		= $(wildcard ft_*.c)
OBJECT_FILES		= $(SOURCE_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECT_FILES) $(LIBFT) ft_printf.h
	@cp $(LIBFT) .
	@mv libft.a $(NAME)
	@ar -rcs $(NAME) $(OBJECT_FILES)

$(LIBFT):
	@$(MAKE) -C libft

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJECT_FILES)
	@$(MAKE) -C libft clean
	
fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C libft fclean
	
re: fclean all

.PHONY: all clean fclean re