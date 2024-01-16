/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 23:19:33 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/16 18:10:23 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Idea for algorithm: Kinda like selection sort. 
You look for the lowest number in the stack and rotate until you get it 
to the top, then push it to b. We can rotate up or down depending on 
what's faster. When a is empty, push everything to it */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	a;
	t_list	b;
	bool	read_error;
	bool	malloc_error;

	/* need to rewrite
	// think if there's something to clean if there's a read error
	initialize_stacks(&a, &b, argc - 1, &malloc_error);
	extract_input(&a, argc - 1, &argv[1], &read_error);
	if (malloc_error || read_error)
		free_stacks(&a, &b);
	*/
}

