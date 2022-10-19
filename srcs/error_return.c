/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_return.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvachon <alvachon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:11:39 by alvachon          #+#    #+#             */
/*   Updated: 2022/10/19 17:26:47 by alvachon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		error(char *message)
{
	if (1)
		write(0, message, ft_strlen(message));
	return (FALSE);
}

void	*null_error(char *message)
{
	error(message);
	return (NULL);
}

void	*av_error(t_node **list, char *message)
{
	ft_list_destroyer(list);
	return (null_error(message));
}