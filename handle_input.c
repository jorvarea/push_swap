/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:13:03 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/14 17:52:24 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack_utils.h"

void	extract_input(t_stack *s, int stack_size, char **input,
		bool *read_error)
{
	int	i;

	read_error = false;
	i = 0;
	while (i < stack_size && (s->nelms + 1 <= s->capacity) && !read_error)
	{
		s->elms[i] = ft_atoi(input[i], &read_error);
		i++;
		s->nelms++;
	}
}
