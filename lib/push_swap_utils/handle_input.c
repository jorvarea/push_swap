/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:13:03 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/19 22:10:32 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	is_duplicate(t_list *head, int number)
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

t_list	*extract_input(int input_count, char **input, int *stack_size)
{
	t_list	*stack;
	char	**splitted_input;
	bool	error;
	int		i;
	int 	j;

	stack = NULL;
	error = false;
	*stack_size = 0;
	i = 0;
	while (i < input_count && !error)
	{
		splitted_input = ft_split(input[i], ' ');
		error = splitted_input == NULL;
		if (!error)
		{
			j = 0;
			while (splitted_input[j])
			{
				parse_and_store(&stack, splitted_input[j], &error);
				(*stack_size)++;
				free(splitted_input[j]);
				j++;
			}
			free(splitted_input);
			splitted_input = NULL;
		}
		i++;
	}
	if (error)
	{
		clear_list(&stack);
		stack = NULL;
	}
	return (stack);
}

void	initialize_stacks(int argc, char **argv, t_list **a, t_list **b,
		int *stack_size)
{
	*a = extract_input(argc - 1, &argv[1], stack_size);
	*b = NULL;
}
