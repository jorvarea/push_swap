/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 23:19:58 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/29 14:38:23 by jorvarea         ###   ########.fr       */
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
	int	*previous_in_sequence;
	int	*lis;
	int	size;
}		t_lis_arrays;

void	stack_selection_sort(t_list **a, t_list **b, int stack_len);
void    lis_based_sorting(t_list **a, t_list **b, int stack_len);
int		*longest_increasing_subsequence(int *numbers, int size);

#endif