/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 15:41:27 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/13 16:21:03 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_struct.h"
#include "ft_printf.h"

static int max(int a, int b)
{
    return(a * (a >= b) + b * (b > a));
}

static void print_dashed_line(int lenght)
{
    int i;

    i = 0;
    while (i < lenght)
    {
        ft_printf("-");
        i++;
    }
}

void print_stacks(t_stack *a, t_stack *b)
{
    int max_stack_lenght;

    max_stack_lenght = max(a->nelms, b->nelms);
    print_dashed_line(80);
    
    ft_printf("- -\n");
    ft_printf("a b\n");
    print_dashed_line(80);
}