/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 23:19:58 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/30 14:31:36 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "libft.h"
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

// stack_selection_sort
void	stack_selection_sort(t_list **a, t_list **b, int stack_len);

// longest_increasing_subsequence
int		*longest_increasing_subsequence(int *numbers, int size);

// moves_utils
void	free_moves(t_moves *moves);
void	calculate_moves_b(t_list *b, int *moves_b);
void	calculate_moves_a(t_list *a, t_list *b, int *moves_a);
int		total_moves(int *moves_a, int *moves_b, int index);

// execute_optimal_move
void	execute_optimal_move(t_list **a, t_list **b, t_moves *moves,
			int optimal_index);

// lis_based_sorting
int		optimal_move_index(t_list **b, int *moves_a, int *moves_b);
void	push_unsorted(t_list **a, t_list **b, int *lis, int stack_len);
void	insert_unsorted(t_list **a, t_list **b);
void	lis_based_sorting(t_list **a, t_list **b, int stack_len);

#endif