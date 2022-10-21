/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvachon <alvachon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:48:46 by alvachon          #+#    #+#             */
/*   Updated: 2022/10/21 13:44:03 by alvachon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_bool	size(long integer)
{
	if ((integer < MIN || integer > MAX))
		return (FALSE);
	return (TRUE);
}

int	ft_isdigit(int c)
{
	if (c >= 0 && c <= 127)
	{
		if (c >= '0' && c <= '9')
			return (1);
		else
			return (0);
	}
	else
		return (0);
}

t_bool	valid_content(char **av, int i)
{
	int	j;

	j = 0;
	while (av[i][j])
	{
		if ((av[i][0] == '-' || av[i][0] == '+') && j == 0)
			j++;
		if (!ft_isdigit(av[i][j]))
			return (FALSE);
		else if ((av[i][j] == '-' || av[i][j] == '+') && j != 0)
			return (FALSE);
		j++;
	}
	return (TRUE);
}

t_bool	unique(long integer, t_node **head)
{
	if (integer == (*head)->data)
		return (FALSE);
	return (TRUE);
}

t_bool	sorted(t_node *l_a)
{
	t_node	*head;

	head = l_a;
	while (l_a->link_next != head)
	{
		if (l_a->data > l_a->link_next->data)
			return (FALSE);
		l_a = l_a->link_next;
	}
	if (l_a->data < l_a->link_next->data)
		return (FALSE);
	return (TRUE);
}
