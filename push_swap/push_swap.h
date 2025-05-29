/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:39:26 by alegarci          #+#    #+#             */
/*   Updated: 2025/05/29 16:41:22 by alegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

void	ft_pa(t_stack **a, t_stack **b);
void	ft_pb(t_stack **a, t_stack **b);
void	ft_rra(t_stack **a);
void	ft_rrb(t_stack **b);
void	ft_rrr(t_stack **a, t_stack **b);
void	ft_ra(t_stack **a);
void	ft_rb(t_stack **b);
void	ft_rr(t_stack **a, t_stack **b);
void	ft_sa(t_stack **a);
void	ft_sb(t_stack **b);
void	ft_ss(t_stack **a, t_stack **b);
void	free_split(char **res);
void	lst_addback(t_stack **lst, t_stack *new_node);
void	clear_stack(t_stack **lst);
void	assign_indices(t_stack *a);
void	sort_two(t_stack **a);
void	sort_three(t_stack **a);
void	sort_four(t_stack **a, t_stack **b);
void	sort_five(t_stack **a, t_stack **b);
void	ft_sort_big_list(t_stack **a, t_stack **b, int size);
char	*join_args(int argc, char **argv);
char	**split_args(int argc, char **argv);
char	**validate_args(int argc, char **argv);
int		check_duplicates(char **values);
int		is_int_atoi(char *str);
int		ft_atoi_safe(char *str);
int		is_sorted(t_stack *a);
int		ft_list_size(t_stack *begin_list);
int		find_min(t_stack *a);
int		ft_get_dir(t_stack *a);
t_stack	*lst_new(int value);
t_stack	*create_stack(int argc, char **argv);

#endif