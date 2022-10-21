/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvachon <alvachon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 12:14:27 by alvachon          #+#    #+#             */
/*   Updated: 2022/10/21 13:06:55 by alvachon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	valid_operation(char *op, t_all info)
{
	if (ft_strcmp(op, "sa") == 0)
		move_swap(L_A, &info);
	else if (ft_strcmp(op, "sb") == 0)
		move_swap(L_B, &info);
	else if (ft_strcmp(op, "ss") == 0)
		move_swap(BOTH, &info);
	else if (ft_strcmp(op, "pa") == 0)
		move_push(L_B, &info);
	else if (ft_strcmp(op, "pb") == 0)
		move_push(L_A, &info);
	else if (ft_strcmp(op, "ra") == 0)
		move_rotate(L_A, &info);
	else if (ft_strcmp(op, "rb") == 0)
		move_rotate(L_B, &info);
	else if (ft_strcmp(op, "rr") == 0)
		move_rotate(BOTH, &info);
	else if (ft_strcmp(op, "rra") == 0)
		move_reverse_rotate(L_A, &info);
	else if (ft_strcmp(op, "rrb") == 0)
		move_reverse_rotate(L_B, &info);
	else if (ft_strcmp(op, "rrr") == 0)
		move_reverse_rotate(BOTH, &info);
	else
		av_error(&info, "Error\n");
	return (FALSE);
}

int	main(int ac, char **av)
{
	t_all	info;
	char	*line;
	int		ret;

	info.l_a = ft_check_params(ac, av + 1);
	if (!info.l_a || !solved_by_index(&info))
		return (0);
	if (info.count == 0 || info.count == 1 || sorted(info.l_a))
		ft_list_destroyer(&info.l_a);
	ret = get_next_line(0, &line);
	while (ret > 0)
	{
		if (!valid_operation(line, info))
			return (av_error(info, "Error\n"));
		free(line);
		ret = get_next_line(0, &line);
	}
	if (sorted(info.l_a))
		return (write_op("OK", 1));
	return (write_op("KO", 1));
}