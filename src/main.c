/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 23:19:33 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/01 02:00:03 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		stack_size;

	stack_size = initialize_stacks(argc, argv, &a, &b);
	if (a != NULL)
	{
		if (!is_stack_sorted(a))
			lis_based_sorting(&a, &b, stack_size);
	}
	else
		ft_putstr_fd("Error\n", STDERR_FILENO);
	clear_list(&a);
	clear_list(&b);
	return (0);
}
