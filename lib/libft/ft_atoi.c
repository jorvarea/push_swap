/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 15:47:02 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/14 16:28:49 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str, bool *read_error)
{
	int			i;
	long int	num;
	int			sign;

	*read_error = false;
	num = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		sign = (str[i] == '+') - (str[i] == '-');
		i++;
	}
	if (!ft_isdigit(str[i]))
		*read_error = true;
	while (ft_isdigit(str[i]) && num <= INT_MAX)
		num = num * 10 + (str[i++] - '0');
	if (str[i] != '\0' || num > INT_MAX)
		*read_error = true;
	return ((int)num * sign);
}
