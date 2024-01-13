/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:09:08 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/13 16:10:07 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_STRUCT_H
# define STACK_STRUCT_H

typedef struct s_stack
{
	char	id;
	int		*elms;
	int		nelms;
	int		capacity;
}			t_stack;

#endif
