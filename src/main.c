/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 23:19:33 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/31 18:12:34 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		stack_len;

	stack_len = initialize_stacks(argc, argv, &a, &b);
	if (a != NULL)
	{
		if (!is_stack_sorted(a))
			lis_based_sorting(&a, &b, stack_len);
	}
	else
		ft_putstr_fd("Error\n", STDERR_FILENO);
	clear_list(&a);
	clear_list(&b);
	return (0);
}
