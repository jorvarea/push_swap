/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 01:54:29 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/16 18:08:19 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "printf.h"

void	print_stacks(t_list *a, t_list *b);
t_list	*extract_input(int input_size, char **input, bool *read_error);

void	swap_top_stack(t_list **head);
void	push_top_stack(t_list **dest_head, t_list **src_head);
void	rotate_stack_up(t_list **head);
void	rotate_stack_down(t_list **head);

#endif
