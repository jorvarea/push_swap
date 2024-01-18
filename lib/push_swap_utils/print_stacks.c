/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 15:41:27 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/18 02:02:04 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#define DASH_LINE_LENGHT 80

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

void	print_stacks(t_list *a, t_list *b)
{
	print_dashed_line(DASH_LINE_LENGHT);
	while (a != NULL || b != NULL)
	{
		if (a != NULL)
		{
			ft_printf("%d ", a->number);
			a = a->next;
		}
		else
			ft_printf("  ");
		if (b != NULL)
		{
			ft_printf("%d", b->number);
			b = b->next;
		}
		ft_printf("\n");
	}
	ft_printf("- -\n");
	ft_printf("a b\n");
	print_dashed_line(DASH_LINE_LENGHT);
}
