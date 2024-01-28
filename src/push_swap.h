/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 23:19:58 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/28 17:53:12 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "push_swap_utils.h"

void	stack_selection_sort(t_list **a, t_list **b, int stack_len);
int	    longest_increasing_subsequence_algorithm(t_list *head);

#endif