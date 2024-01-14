/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 01:54:29 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/14 17:54:45 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stack_operations.h"
# include "stack_utils.h"
# include <stdbool.h>

void	print_stacks(t_stack *a, t_stack *b);
void	extract_input(t_stack *s, int stack_size, char **input,
			bool *read_error);

#endif
