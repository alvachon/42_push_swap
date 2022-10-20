/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_circ_ll.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvachon <alvachon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:35:00 by alvachon          #+#    #+#             */
/*   Updated: 2022/10/20 14:07:06 by alvachon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLY_CIRC_LL_H
# define DOUBLY_CIRC_LL_H

# include <unistd.h>
# include <stdlib.h>

# define MAX 2147483647
# define MIN -2147483648

typedef struct s_node
{
	int				data;
	int				index;
	struct s_node	*link_next;
	struct s_node	*link_prev;	
}	t_node;

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
}	t_bool;

/*creating_nodes.c*/
/*Creating a node to anempty struct. Circularly linked.*/
t_node	*ft_add_to_empty(t_node *head, int data);
/*Creating a node to one. Redirect the link for circular. */
t_node	*ft_add_to_one(t_node *head, int data);
/*Creating node and add the rest of the list after. Relink circular.*/
t_node	*ft_add_at_end(t_node *head, t_node *queue, int data);
/* Relink circular for each node */
t_node	*relink_circular(t_node **new, t_node **old, t_node **top, t_node **h);

#endif