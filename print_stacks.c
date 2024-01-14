/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 15:41:27 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/13 16:35:49 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stack_struct.h"
#define DASH_LINE_LENGHT 80

static int	max(int a, int b)
{
	return (a * (a >= b) + b * (b > a));
}

static void	print_dashed_line(int lenght)
{
	int	i;

	i = 0;
	while (i < lenght)
	{
		ft_printf("-");
		i++;
	}
}

void	print_stacks(t_stack *a, t_stack *b)
{
	int	i;
	int	cont_a;
	int	cont_b;
	int	max_stack_lenght;

	max_stack_lenght = max(a->nelms, b->nelms);
	print_dashed_line(DASH_LINE_LENGHT);
	i = 0;
	cont_a = 0;
	cont_b = 0;
	while (i < max_stack_lenght)
	{
		if (a->nelms >= max_stack_lenght - i)
			ft_printf("%d ", a->elms[cont_a++]);
		if (b->nelms >= max_stack_lenght - i)
			ft_printf("%d\n", b->elms[cont_b++]);
		i++;
	}
	ft_printf("- -\n");
	ft_printf("a b\n");
	print_dashed_line(DASH_LINE_LENGHT);
}
