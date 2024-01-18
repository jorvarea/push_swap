/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:36:06 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/18 13:38:10 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"
#include "ft_printf.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = extract_input(argc - 1, &argv[1]);
	b = NULL;
    ft_printf("Initial state:\n");
	print_stacks(a, b);
	return (0);
}