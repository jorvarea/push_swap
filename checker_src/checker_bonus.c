/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:36:06 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/29 11:54:08 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "get_next_line.h"
#include "libft.h"
#include "push_swap_utils.h"

static void	clear_lists(t_list **a, t_list **b)
{
	clear_list(a);
	clear_list(b);
}

static void	handle_output(bool a_is_null, bool b_is_null,
		bool instruction_error, bool is_sorted)
{
	if (!a_is_null && !instruction_error && b_is_null && is_sorted)
		ft_printf("OK\n");
	else if (!a_is_null && !instruction_error)
		ft_printf("KO\n");
	else
		ft_putstr_fd("Error\n", STDERR_FILENO);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	char	*line;
	bool	instruction_error;
	bool	keep_going;

	check_empty_arguments(argc);
	initialize_stacks(argc, argv, &a, &b);
	instruction_error = false;
	if (a != NULL)
	{
		keep_going = true;
		while (keep_going && !instruction_error)
		{
			line = get_next_line(STDIN_FILENO);
			keep_going = line && line[0] != '\n';
			if (line)
			{
				process_instruction(line, &a, &b, &instruction_error);
				free(line);
			}
		}
	}
	handle_output(a == NULL, b == NULL, instruction_error, is_stack_sorted(a));
	clear_lists(&a, &b);
	return (0);
}
