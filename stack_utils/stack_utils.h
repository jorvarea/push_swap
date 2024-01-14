/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:09:08 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/14 17:32:39 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_UTILS_H
# define STACK_UTILS_H

# include "stdbool.h"
# include "stdlib.h"

typedef struct s_stack
{
	char	id;
	int		*elms;
	int		nelms;
	int		capacity;
}			t_stack;

void		initialize_stacks(t_stack *a, t_stack *b, int stack_size,
				bool *malloc_error);
void		free_stacks(t_stack *a, t_stack *b);

#endif
