/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:24:01 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/13 14:40:53 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_operations.h"

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	insert_top_stack(t_stack *stack, int element)
{
	int	i;

	if (stack->nelms + 1 <= stack->capacity)
	{
		i = 0;
		while (i < stack->nelms)
		{
			stack->elms[stack->nelms - i] = stack->elms[stack->nelms - i - 1];
			i++;
		}
		stack->elms[0] = element;
		stack->nelms++;
	}
}

void	remove_top_stack(t_stack *stack)
{
	int	i;

	if (stack->nelms > 0)
	{
		i = 0;
		while (i < stack->nelms - 1)
		{
			stack->elms[i] = stack->elms[i + 1];
			i++;
		}
		stack->nelms--;
	}
}
