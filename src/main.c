/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 23:19:33 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/28 00:54:32 by jorvarea         ###   ########.fr       */
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
		ft_printf("LIS: %d\n", longest_increasing_subsequence(a));
	else
		ft_putstr_fd("Error\n", STDERR_FILENO);
	clear_list(&a);
	clear_list(&b);
	return (0);
}
