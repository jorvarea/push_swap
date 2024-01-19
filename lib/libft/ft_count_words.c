/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:47:18 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/19 18:52:25 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_words(char const *str, char delimiter)
{
	int	word_count;

	word_count = 0;
	while (*str)
	{
		if (*str != delimiter)
		{
			word_count++;
			while (*str && *str != delimiter)
				str++;
		}
		else
			str++;
	}
	return (word_count);
}
