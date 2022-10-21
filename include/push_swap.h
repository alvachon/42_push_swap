/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvachon <alvachon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:29:08 by alvachon          #+#    #+#             */
/*   Updated: 2022/10/21 13:06:07 by alvachon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "doubly_circ_ll.h"

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_all
{
	int		count;
	t_node	*l_a;
	t_node	*l_b;
}	t_all;

typedef enum e_get
{
	L_A = 'A',
	L_B = 'B',
	BOTH = 'A' + 'B'
}	t_get;

/*arg_split.c*/
void	ft_free_table(void ***table);
char	*ft_strndup(const char *str, size_t len);
char	**ft_freeall(char **str);
size_t	ft_wordcount(char const *s, char c);
char	**ft_split(char const *s, char c);
/*error_handling.c*/
t_bool	size(long integer);
int		ft_isdigit(int c);
t_bool	valid_content(char **av, int i);
t_bool	unique(long integer, t_node **head);
t_bool	sorted(t_node *l_a);
/*error_helper.c*/
int		ft_isspace(int c);
long	ft_atol(const char *str);
int		ft_atoi(const char *str);
int		ft_list_destroyer(t_node **head);
/*error_return.c*/
int		error(char *message);
void	*null_error(char *message);
void	*av_error(t_node **list, char *message);
/*get_stack.c*/
t_node	*ft_select(t_get stack, t_all *info);
void	move_swap(t_get stack, t_all *info);
void	move_reverse_rotate(t_get stack, t_all *info);
void	move_rotate(t_get stack, t_all *info);
void	move_push(t_get stack, t_all *info);
/*index_solver.c*/
void	set_solved_index(int *index, t_all *info);
void	sort_list(int *solver, int len);
void	put_data(int *solver, t_node *l_a);
int		total_items(t_node *node);
t_bool	solved_by_index(t_all *info);
/*moves.c*/
void	swap(t_node	*head, t_node *next);
void	rotate(t_node **node);
void	reverse_rotate(t_node **node);
void	push_checker(t_node **from, t_node **to);
/*push_checker.c*/
void	push_to_empty(t_node ***head, t_node ***empty);
void	push_to_one(t_node ***head, t_node ***to_one);
void	push_at_head(t_node ***head, t_node ***to_head);
void	pop_head(t_node **node);
/*push_swap.c*/
t_node	*ft_check_params(int ac, char **av);
t_node	*take_one_arg_count(char **av);
t_node	*take_multi_args_count(int ac, char **av);
/*stack_action.c*/
void	repeat_op(void (*op)(t_get, t_all *), int i, t_get stack, t_all *info);
void	do_less_moves_to_tail(int pos, int len, t_get stack, t_all *info);
void	put_at_tail(t_node *target, t_get stack, t_all *info);
void	do_less_moves_to_head(int pos, int len, t_get stack, t_all *info);
void	put_at_head(t_node *target, t_get stack, t_all *info);
/*stack_finder.c*/
t_node	*find_biggest(t_node *node);
t_node	*find_smallest(t_node *node);
/*type_algo.c*/
void	in_place_two(t_get stack, t_all *info);
void	in_place_three(t_get stack, t_all *info);
void	insertion_sort(t_all *info);
/*type_sandwich.c*/
int		find_index_smaller_than(int chunk, t_node *head);
int		find_index_bigger_than(int chunk, t_node *head);
void	do_less_steps(int option_1, int option_2, t_all *info);
void	return_to_la(t_all *info);
void	sandwich_sort(t_all *info, int chunk_size);
/*utilities.c*/
size_t	ft_strlen(const char *s);
void	write_op(char *message);
void	ft_display(t_node *head);
int		loop_index(int *index, int i, t_node **node, t_all *info);
t_node	*loop_add(t_node *head, int integer);
/*checker.c*/

#endif