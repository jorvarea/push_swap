/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:13:03 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/19 14:12:25 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	is_duplicate(t_list *head, int number)
{
	t_list	*current;
	bool	is_duplicate;

	is_duplicate = false;
	current = head;
	while (current)
	{
		if (current->number == number)
			is_duplicate = true;
		current = current->next;
	}
	return (is_duplicate);
}

static void	parse_and_store(t_list **stack, char *input, bool *error)
{
	t_list	*new_element;
	int		number;

	number = ft_atoi(input, error);
	if (!*error)
	{
		new_element = list_new_element(number);
		*error = new_element == NULL || is_duplicate(*stack,
				new_element->number);
		if (!*error)
			list_add_back(stack, new_element);
	}
}

t_list	*extract_input(int input_size, char **input)
{
	t_list	*stack;
	bool	error;
	int		i;

	stack = NULL;
	error = false;
	i = 0;
	while (i < input_size && !error)
	{
		parse_and_store(&stack, input[i], &error);
		i++;
	}
	if (error)
	{
		clear_list(&stack);
		stack = NULL;
	}
	return (stack);
}

void	initialize_stacks(int argc, char **argv, t_list **a, t_list **b)
{
	*a = extract_input(argc - 1, &argv[1]);
	*b = NULL;
}
