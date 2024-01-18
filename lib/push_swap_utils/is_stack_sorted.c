/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_stack_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:37:54 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/18 21:01:57 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

bool is_stack_sorted(t_list *head)
{
    t_list *previous;
    t_list *current;
    bool is_sorted;

    is_sorted = true;
    previous = head;
    if (head != NULL)
        current = head->next;
    while(previous && current && is_sorted)
    {
        if (previous->number > current->number)
            is_sorted = false;
        previous = current;
        current = current->next;
    }
    return (is_sorted);
}
