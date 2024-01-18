/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:34:09 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/16 17:37:51 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	list_size(t_list *head)
{
	t_list	*current;
	int		i;

	current = head;
	i = 0;
	while (current != NULL)
	{
		current = current->next;
		i++;
	}
	return (i);
}
