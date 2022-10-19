/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_circ_ll.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvachon <alvachon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:35:00 by alvachon          #+#    #+#             */
/*   Updated: 2022/10/19 15:22:36 by alvachon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLY_CIRC_LL_H
# define DOUBLY_CIRC_LL_H

#include <unistd.h>
#include <stdlib.h>

# define MAX 2147483647
# define MIN -2147483648

typedef struct s_node
{
	int data;
	int index;
	struct s_node *link_next;
	struct s_node *link_prev;	
}	t_node;

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
}	t_bool;

t_node	*ft_add_to_empty(t_node *head, int data);
t_node	*ft_add_to_one(t_node *head, int data);
t_node	*ft_add_at_end(t_node *head, t_node *queue, int data);

#endif