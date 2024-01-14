/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_stacks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:29:51 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/14 17:57:00 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_utils.h"

void	initialize_stacks(t_stack *a, t_stack *b, int stack_size,
		bool *malloc_error)
{
	*malloc_error = true;
	a->id = 'a';
	b->id = 'b';
	a->nelms = 0;
	b->nelms = 0;
	a->elms = malloc(stack_size * sizeof(int));
	b->elms = malloc(stack_size * sizeof(int));
	if (a->elms != NULL && b->elms != NULL)
	{
		a->capacity = stack_size;
		b->capacity = stack_size;
	}
	else
	{
		*malloc_error = false;
		if (a->elms != NULL)
			free(a->elms);
		if (b->elms != NULL)
			free(b->elms);
		a->elms = NULL;
		b->elms = NULL;
	}
}
