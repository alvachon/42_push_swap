/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvachon <alvachon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:44:34 by alvachon          #+#    #+#             */
/*   Updated: 2022/10/26 13:20:11 by alvachon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"


void	ft_action_processing(char *line, t_all *info)
{
	if (ft_strcmp(line, "sa") == 0)
		ft_sa(info->l_a, 0);
	else if (ft_strcmp(line, "sb") == 0)
		ft_sb(info->l_b, 0);
	else if (ft_strcmp(line, "ss") == 0)
		ft_ss(s, 0);
	else if (ft_strcmp(line, "pa") == 0)
		ft_pa(s, 0);
	else if (ft_strcmp(line, "pb") == 0)
		ft_pb(s, 0);
	else if (ft_strcmp(line, "ra") == 0)
		ft_ra(info->l_a, 0);
	else if (ft_strcmp(line, "rb") == 0)
		ft_rb(info->l_b, 0);
	else if (ft_strcmp(line, "rr") == 0)
		ft_rr(s, 0);
	else if (ft_strcmp(line, "rra") == 0)
		ft_rra(info->l_a, 0);
	else if (ft_strcmp(line, "rrb") == 0)
		ft_rrb(info->l_b, 0);
	else if (ft_strcmp(line, "rrr") == 0)
		ft_rrr(s, 0);
	else
		ft_error();
}


void	ft_read_action(t_all info)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line))
	{
		ft_action_processing(line, &info);
		free(line);
		line = NULL;
	}
	if (line)
	{
		free(line);
		line = NULL;
	}
}

int		ft_stack_sorted(t_stacks *s)
{
	int		i;
	int		buff;
	t_stack	*save;

	i = 0;
	save = s->a;
	while (i < (s->count_a - 1))
	{
		buff = s->a->data;
		s->a = s->a->next;
		if (buff > s->a->data)
		{
			s->a = save;
			return (0);
		}
		i++;
	}
	s->a = save;
	return (1);
}

t_bool	check_args(int ac, char **av, t_all *info)
{
	t_node	*head;
	int		i;
	int		integer;

	head = NULL;
	i = 0;
	if (ac == 2)
	{
		ac = 0;
		av = ft_split(*av, ' ');
		while (av[ac])
			ac++;
		ft_free_table((void ***)&av);
	}
	while (av[i] && ac)
	{
		if (!size(ft_atol(av[i])))
			return (FALSE);
		if (!valid_content(av, i))
			return (FALSE);
		integer = ft_atoi(av[i]);
		if (head == NULL)
			head = ft_add_to_empty(head, integer);
		else if (unique(integer, &head) && i == 1)
			head = ft_add_to_one(head, integer);
		if (!unique(integer, &head) && i == 1)
			return (FALSE);
		else if (i >= 2)
			head = loop_add(head, integer);
		i++;
	}
	info->l_a = head;
	return (TRUE);
}

int		main(int ac, char **av)
{
	t_all		info;

	if (check_args(ac, av, &info))
	{
		ft_read_action(info);
		if ((ft_stack_sorted(stacks)) && stacks->count_b == 0)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	ft_free_stack(info.l_a);
	free(info);
	free(stacks);
	return (0);
}