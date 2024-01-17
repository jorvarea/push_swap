/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:13:03 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/17 16:55:12 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*extract_input(int input_size, char **input)
{
	t_list *stack;
	t_list *new_element;
	bool read_error;
	int number;
	int	i;

	stack = NULL;
	read_error = false;
	i = 0;
	while (i < input_size && !read_error)
	{
		number = ft_atoi(input[i], &read_error);
		if (!read_error)
		{
			new_element = list_new_element(number);
			// need to check the null allocation, could write another function and create malloc_error, could eliminate i and use input_size--
			list_add_back(&stack, new_element);
		}
		i++;
	}
	if (read_error)
	{
		clear_list(&stack);
		stack = NULL;
	}
	return (stack);
}
