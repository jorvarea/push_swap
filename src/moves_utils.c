/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:41:58 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/30 13:48:29 by jorvarea         ###   ########.fr       */
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

void	calculate_moves_a(t_list *a, t_list *b, int *moves_a)
{
	t_list	*current_a;
	t_list	*current_b;
	int		size_a;
	int		i;
	int		j;

	size_a = list_size(a);
	i = 0;
	current_b = b;
	while (current_b)
	{
		j = 0;
		current_a = a;
		while (current_a && current_a->number < current_b->number)
		{
			current_a = current_a->next;
			j++;
		}
		if (j <= size_a / 2)
			moves_a[i] = j;
		else
			moves_a[i] = -(size_a - j);
		current_b = current_b->next;
		i++;
	}
}

int	total_moves(int *moves_a, int *moves_b, int index)
{
	int	min;

	if (moves_a[index] >= 0 && moves_b[index] >= 0)
		min = ft_max(moves_a[index], moves_b[index]);
	else if (moves_a[index] >= 0 && moves_b[index] < 0)
		min = moves_a[index] + ft_abs(moves_b[index]);
	else if (moves_a[index] < 0 && moves_b[index] >= 0)
		min = ft_abs(moves_a[index]) + moves_b[index];
	else
		min = ft_min(moves_a[index], moves_b[index]);
	return (min);
}
