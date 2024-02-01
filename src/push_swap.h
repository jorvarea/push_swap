/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 23:19:58 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/01 20:20:25 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "libft.h"
# include "push_swap_utils.h"

typedef struct s_lis_arrays
{
	int		*numbers;
	int		*lis_ending_at;
	int		*previous;
	int		*lis;
	int		size;
}			t_lis_arrays;

typedef struct s_moves
{
	int		*a;
	int		*b;
}			t_moves;

// stack_selection_sort
void		stack_selection_sort(t_list **a, t_list **b, int stack_len);

// moves_utils
void		free_moves(t_moves *moves);
void		calculate_moves_b(t_list *b, int *moves_b);
void		calculate_moves_a(t_list *a, t_list *b, int *moves_a);

// execute_optimal_move_utils
void		move_plus_plus(t_list **a, t_list **b, t_moves *moves,
				int optimal_index);
void		move_plus_minus(t_list **a, t_list **b, t_moves *moves,
				int optimal_index);
void		move_minus_plus(t_list **a, t_list **b, t_moves *moves,
				int optimal_index);
void		move_minus_minus(t_list **a, t_list **b, t_moves *moves,
				int optimal_index);

// longest_increasing_subsequence_utils
void		find_lis(t_lis_arrays *arrays, int *lis_size);
int			*longest_increasing_subsequence(int *numbers, int stack_size,
				int *lis_size);
void		execute_optimal_move(t_list **a, t_list **b, t_moves *moves,
				int optimal_index);
void		lis_based_sorting(t_list **a, t_list **b, int stack_len);
void		push_unsorted(t_list **a, t_list **b, int *lis, int lis_size);
int			optimal_move_index(t_list **b, int *moves_a, int *moves_b);
void		insert_unsorted(t_list **a, t_list **b);
void		put_min_first(t_list **a, int size_a);

#endif