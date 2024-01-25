/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_increasing_subsequence.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:32:04 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/23 19:47:15 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void circular_next_element(t_list *head, t_list **current)
{
    if ((*current)->next != NULL)
        *current = (*current)->next;
    else
        *current = head;
}

t_list *longest_increasing_subsequence(t_list *head)
{
    t_list *subsequence;
    t_list *subsequence_current;
    t_list *current_i;
    t_list *current_j;
    bool error;
    
    error = false;
    current_i = head;
    while (current_i != NULL && !error)
    {
        current_j = current_i->next;
        subsequence = list_new_element(current_j->number);
        subsequence_current = subsequence;
        error = subsequence == NULL;
        while(current_j != current_i && !error)
        {
            if (current_j->number > subsequence)
            circular_next_element(head, &current_j);
        }
        current_i = current_i->next;
    }
}
