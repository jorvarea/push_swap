/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:36:06 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/18 21:43:12 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "get_next_line.h"
#include "libft.h"
#include "push_swap_utils.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	char	*line;
	bool	instruction_error;
	bool 	is_sorted;

	initialize_stacks(argc, argv, &a, &b);
	if (a != NULL)
	{
		ft_printf("Initial state:\n");
		print_stacks(a, b);
		line = "";
		while (line && line[0] != '\n' && !instruction_error)
		{
			line = get_next_line(STDIN_FILENO);
			process_instruction(line, &a, &b, &instruction_error);
			free(line);
			ft_printf("Current state:\n");
			print_stacks(a, b);
		}
	}
	is_sorted = is_stack_sorted(a);
	if (a != NULL && !instruction_error && b == NULL && is_sorted)
		ft_printf("OK\n");
	else if (a != NULL && !instruction_error)
		ft_printf("KO\n");
	else
		ft_putstr_fd("Error\n", STDERR_FILENO);
	clear_list(&a);
	clear_list(&b);
	return (0);
}
