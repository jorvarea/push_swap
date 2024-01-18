/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_list_element.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:19:02 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/16 14:56:13 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*list_new_element(int number)
{
	t_list	*list_element;

	list_element = malloc(sizeof(t_list));
	if (list_element != NULL)
	{
		list_element->number = number;
		list_element->next = NULL;
	}
	return (list_element);
}
