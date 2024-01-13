/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 02:12:30 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/13 14:57:54 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_OPERATIONS_H
# define STACK_OPERATIONS_H

# include "ft_printf.h"

typedef struct s_stack
{
	char	id;
	int		*elms;
	int		nelms;
	int		capacity;
}			t_stack;

void		ft_swap(int *a, int *b);
void		insert_top_stack(t_stack *stack, int element);
void		remove_top_stack(t_stack *stack);

void		swap_top_stack(t_stack *s);
void		swap_top_stack_both(t_stack *s1, t_stack *s2);
void		push_top_stack(t_stack *dest, t_stack *src);
void		rotate_stack_up(t_stack *s);
void		rotate_both_stacks_up(t_stack *s1, t_stack *s2);
void		rotate_stack_down(t_stack *s);
void		rotate_both_stacks_down(t_stack *s1, t_stack *s2);

#endif