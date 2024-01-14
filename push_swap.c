/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 23:19:33 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/13 23:21:44 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Idea for algorithm: Kinda like selection sort. You look for the lowest number in the stack and rotate until
you get it to the top, then push it to b. We can rotate up or down depending on what's faster. When a is empty,
push everything to it */