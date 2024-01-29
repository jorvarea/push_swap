/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 23:19:58 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/29 23:51:04 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "push_swap_utils.h"

typedef struct s_lis_arrays
{
	int	*numbers;
	int	*lis_ending_at;
	int	*previous;
	int	*lis;
	int	size;
}		t_lis_arrays;

typedef struct s_moves
{
	int	*a;
	int	*b;
}		t_moves;

void	stack_selection_sort(t_list **a, t_list **b, int stack_len);
void	insert_unsorted(t_list **a, t_list **b);
void	lis_based_sorting(t_list **a, t_list **b, int stack_len);
int		*longest_increasing_subsequence(int *numbers, int size);

#endif