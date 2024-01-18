/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:36:06 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/18 20:31:18 by jorvarea         ###   ########.fr       */
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

	a = extract_input(argc - 1, &argv[1]);
	b = NULL;
	if (a != NULL)
	{
		ft_printf("Initial state:\n");
		print_stacks(a, b);
		line = get_next_line(0);
		while (line && line[0] != '\n' && !instruction_error)
		{
			process_instruction(line, &a, &b, &instruction_error);
			ft_printf("Current state:\n");
			print_stacks(a, b);
			line = get_next_line(0);
		}
	}
	if (a == NULL || instruction_error)
		ft_putstr_fd("Error\n", STDERR_FILENO);
	return (0);
}
