/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvachon <alvachon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:29:06 by alvachon          #+#    #+#             */
/*   Updated: 2022/10/26 12:56:40 by alvachon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_node	*take_multi_args_count(int ac, char **av)
{
	t_node	*head;
	int		i;
	int		integer;

	head = NULL;
	i = 0;
	while (av[i] && ac)
	{
		if (!size(ft_atol(av[i])))
			return (av_error(&head, "Error\n"));
		if (!valid_content(av, i))
			return (av_error(&head, "Error\n"));
		integer = ft_atoi(av[i]);
		if (head == NULL)
			head = ft_add_to_empty(head, integer);
		else if (unique(integer, &head) && i == 1)
			head = ft_add_to_one(head, integer);
		if (!unique(integer, &head) && i == 1)
			return (av_error(&head, "Error\n"));
		else if (i >= 2)
			head = loop_add(head, integer);
		i++;
	}
	return (head);
}

t_node	*take_one_arg_count(char **av)
{
	t_node	*head;
	int		ac;

	ac = 0;
	av = ft_split(*av, ' ');
	while (av[ac])
		ac++;
	head = take_multi_args_count(ac, av);
	ft_free_table((void ***)&av);
	return (head);
}

t_node	*ft_check_params(int ac, char **av)
{
	if (ac == 2)
		return (take_one_arg_count(av));
	return (take_multi_args_count(ac, av));
}

int	main(int ac, char **av)
{
	t_all	info;

	info.l_a = ft_check_params(ac, av + 1);
	info.l_b = NULL;
	if (!info.l_a || !solved_by_index(&info))
		return (0);
	if (info.count == 0 || info.count == 1 || sorted(info.l_a))
	{
		ft_list_destroyer(&info.l_a);
		return (0);
	}
	if (info.count == 2)
		in_place_two(L_A, &info);
	else if (info.count == 3)
		in_place_three(L_A, &info);
	else if (info.count <= 25)
		insertion_sort(&info);
	else if (info.count <= 250)
		sandwich_sort(&info, 25);
	else
		sandwich_sort(&info, 50);
	ft_list_destroyer(&info.l_a);
	return (0);
}
