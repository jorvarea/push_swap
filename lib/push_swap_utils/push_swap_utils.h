/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 01:54:29 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/27 23:40:21 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_UTILS_H
# define PUSH_SWAP_UTILS_H

# include "ft_printf.h"
# include "libft.h"

int		initialize_stacks(int argc, char **argv, t_list **a, t_list **b);
void	print_stacks(t_list *a, t_list *b);
void	process_instruction(char *line, t_list **a, t_list **b, bool *error);
bool	is_stack_sorted(t_list *head);
void	list2array(t_list *head, int **array, int *size);

void	swap_top_stack(t_list **head);
void	swap_top_stack_both(t_list **a, t_list **b);
void	push_top_stack(t_list **dest_head, t_list **src_head);
void	rotate_stack_up(t_list **head);
void	rotate_stack_up_both(t_list **a, t_list **b);
void	rotate_stack_down(t_list **head);
void	rotate_stack_down_both(t_list **a, t_list **b);

#endif
