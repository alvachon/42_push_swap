/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvachon <alvachon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:51:15 by alvachon          #+#    #+#             */
/*   Updated: 2022/10/19 18:02:04 by alvachon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	write_op(char *message)
{
	write(1, message, ft_strlen(message));
}

void	ft_display(t_node *head)
{
	t_node	*top;

	top = head;
	if (top == NULL)
	{
		printf(" null\n");
		return ;
	}
	while (top->link_next != head)
	{
		printf("%d ", top->data);
		top = top->link_next;
	}
	printf("%d ", top->data);
	printf("\n");
}