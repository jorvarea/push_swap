/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:13:03 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/16 18:09:21 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*extract_input(int input_size, char **input, bool *read_error)
{
	t_list *stack;
	t_list *new_element;
	int number;
	int	i;

	stack = NULL;
	read_error = false;
	i = 0;
	while (i < input_size && !read_error)
	{
		// think if there's something to clean if there's a read error
		number = ft_atoi(input[i], &read_error);
		if (!read_error)
		{
			new_element = list_new_element(number);
			list_add_back(&stack, new_element);
		}
		i++;
	}
}
