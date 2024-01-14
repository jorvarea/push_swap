/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:31:59 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/14 17:32:15 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_utils.h"

void	free_stacks(t_stack *a, t_stack *b)
{
	if (a->elms != NULL)
		free(a->elms);
	if (b->elms != NULL)
		free(b->elms);
	a->capacity = 0;
	b->capacity = 0;
	a->nelms = 0;
	b->nelms = 0;
	a->elms = NULL;
	b->elms = NULL;
}
