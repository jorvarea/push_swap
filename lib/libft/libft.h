/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 15:50:43 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/01 01:00:47 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				number;
	struct s_list	*next;
}					t_list;

bool				ft_isspace(char c);
bool				ft_isdigit(int c);
int					ft_max(int a, int b);
int					ft_min(int a, int b);
int					ft_abs(int x);
void				ft_swap(int *a, int *b);
int					ft_atoi(const char *str, bool *read_error);
int					ft_strcmp(const char *s1, const char *s2);
void				ft_putstr_fd(char *str, int fd);
int					ft_count_words(char const *str, char delimiter);
char				**ft_split(char const *str, char delimiter);

void				clear_list(t_list **head);
void				list_add_back(t_list **head, t_list *new_element);
void				list_add_front(t_list **head, t_list *new_head);
t_list				*list_last(t_list *head);
int					list_size(t_list *head);
t_list				*list_new_element(int number);
t_list				*list_extract_first(t_list **head);
t_list				*list_extract_last(t_list *head);

#endif
