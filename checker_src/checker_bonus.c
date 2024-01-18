/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:36:06 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/18 14:39:44 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"
#include "ft_printf.h"
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
    char *line;

	a = extract_input(argc - 1, &argv[1]);
	b = NULL;
    ft_printf("Initial state:\n");
	print_stacks(a, b);
    line = get_next_line(0);
    ft_printf("Line %s", line);
	return (0);
}
