/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:52:49 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/13 14:53:18 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_operations.h"

void	rotate_stack_up(t_stack *s)
{
	int i;
	int	tmp;

	if (s->nelms >= 2)
	{
		tmp = s->elms[0];
		i = 0;
		while (i < s->nelms - 1)
		{
			s->elms[i] = s->elms[i + 1];
			i++;
		}
		s->elms[i] = tmp;
		ft_printf("r%c\n", s->id);
	}
}

void	rotate_both_stacks_up(t_stack *s1, t_stack *s2)
{
	rotate_stack_up(s1);
	rotate_stack_up(s2);
	if (s1->nelms >= 2 || s2->nelms >= 2)
		ft_printf("rr\n");
}

void	rotate_stack_down(t_stack *s)
{
	int	i;
	int	tmp;

	if (s->nelms >= 2)
	{
		tmp = s->elms[s->nelms - 1];
		i = 0;
		while (i < s->nelms - 1)
		{
			s->elms[s->nelms - i - 1] = s->elms[s->nelms - i - 2];
			i++;
		}
		s->elms[0] = tmp;
		ft_printf("rr%c\n", s->id);
	}
}

void	rotate_both_stacks_down(t_stack *s1, t_stack *s2)
{
	rotate_stack_down(s1);
	rotate_stack_down(s2);
	if (s1->nelms >= 2 || s2->nelms >= 2)
		ft_printf("rrr\n");
}
