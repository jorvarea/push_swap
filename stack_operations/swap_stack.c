/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 01:47:09 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/13 14:54:46 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_operations.h"

void	swap_top_stack(t_stack *s)
{
	if (s->nelms >= 2)
	{
		ft_swap(&s->elms[0], &s->elms[1]);
		ft_printf("s%c\n", s->id);
	}
}

void	swap_top_stack_both(t_stack *s1, t_stack *s2)
{
	swap_top_stack(s1);
	swap_top_stack(s2);
	if (s1->nelms >= 2 || s2->nelms >= 2)
		ft_printf("ss\n");
}
