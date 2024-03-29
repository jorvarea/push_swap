/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:41:58 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/01 20:16:43 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_moves(t_moves *moves)
{
	if (moves->a)
		free(moves->a);
	if (moves->b)
		free(moves->b);
}

void	calculate_moves_b(t_list *b, int *moves_b)
{
	int	size;
	int	i;

	size = list_size(b);
	i = 0;
	while (i < size)
	{
		if (i <= size / 2)
			moves_b[i] = i;
		else
			moves_b[i] = -(size - i);
		i++;
	}
}

static int	find_insertion_position(t_list *a, t_list *node, t_element *min)
{
	t_list	*current;
	int		i;
	bool	keep_going;

	i = min->index;
	current = min->node;
	keep_going = true;
	while (current->number < node->number && keep_going)
	{
		current = current->next;
		i++;
		if (current == NULL)
		{
			current = a;
			i = 0;
		}
		if (current == min->node)
			keep_going = false;
	}
	return (i);
}

void	calculate_moves_a(t_list *a, t_list *b, int *moves_a)
{
	t_list		*current_b;
	t_element	min;
	int			size_a;
	int			insertion_index;
	int			i;

	size_a = list_size(a);
	i = 0;
	current_b = b;
	while (current_b)
	{
		find_min(a, &min);
		insertion_index = find_insertion_position(a, current_b, &min);
		if (insertion_index <= size_a / 2)
			moves_a[i] = insertion_index;
		else
			moves_a[i] = -(size_a - insertion_index);
		current_b = current_b->next;
		i++;
	}
}
