/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:01:06 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/03/01 19:37:21 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h>

typedef struct s_data
{
	int	c_1;
	int	c_2;
	int	c_3;
	int	c_4;
	int	c_5;
	int	a_ord;
	int	size_stack_a;
	int	size_stack_b;
	int	*lis;
	int	max_lis;
	int	*mov_a;
	int	*mov_b;
	int	*mov_c;
	int	x;
	int	y;
	int *stacka;
	int *stackb;
}			t_data;

void	ft_sa(t_list **stack_a);
void	ft_sb(t_list **stack_b);
void	ft_ss(t_list **stack_a, t_list **stack_b);
void	ft_ra(t_list **stack_a);
void	ft_rb(t_list **stack_b);
void	ft_rr(t_list **stack_a, t_list **stack_b);
void	ft_rra(t_list **stack_a);
void	ft_rrb(t_list **stack_b);
void	ft_rrr(t_list **stack_a, t_list **stack_b);
void	ft_pa(t_list **stack_a, t_list **stack_b);
void	ft_pb(t_list **stack_a, t_list **stack_b);
int		*ft_lst_to_arr(t_list **stack);
void	ft_three_numbers(t_list **stack_a, t_data *data);
void	ft_four_numbers(t_list **stack_a, t_list **stack_b, t_data *data);
void	ft_five_numbers(t_list **stack_a, t_list **stack_b, t_data *data);
void	ft_order_arr(int *arr, t_data *data);
void	ft_prepare_lis(t_list **stack_a, t_list **stack_b, t_data *data);
void	ft_mov_b(t_list **stack_b, t_data *data);
void	ft_prepare_mov_a(t_list **stack_a, t_list **stack_b, t_data *data);
int		ft_max_arr_a(int *arr, int len_a);
int		ft_min_arr_a(int *arr, int len_a);
int		ft_count_mov_a(int *stacka, int prepare_mov_a, int len_a);
void	ft_mov_c(t_data *data);
int		ft_both_numbers(int i, t_data *data);
int		ft_case_negative_positive(int i, t_data *data);
int		ft_min_mov_c(t_data *data);
void	ft_case_both_positive_pa(t_list **stack_a, t_list **stack_b, t_data *data);
void	ft_case_both_negative_pa(t_list **stack_a, t_list **stack_b, t_data *data);
void	ft_case_positive_negative_pa(t_list **stack_a, t_list **stack_b, t_data *data);
void	ft_case_negative_positive_pa(t_list **stack_a, t_list **stack_b, t_data *data);
void	ft_choose_push_a(t_list **stack_a, t_list **stack_b, t_data *data);
int		ft_search_min_mov_a(int	*stacka, int b, int len_a);
int		ft_min(int *min, int len_a);
void	ft_free_stack_a(t_list **stack_a);
void	ft_free_order(t_data *data);
void	ft_check_all(int argc, char **argv);

#endif
