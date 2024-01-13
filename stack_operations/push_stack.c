/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:20:20 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/13 14:43:15 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_operations.h"

void	push_top_stack(t_stack *dest, t_stack *src)
{
	if (src->nelms > 0)
	{
		insert_top_stack(dest, src->elms[0]);
		remove_top_stack(src);
		ft_printf("p%c\n", dest->id);
	}
}
