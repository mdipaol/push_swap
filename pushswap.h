/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:01:06 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/02/27 19:19:12 by mdi-paol         ###   ########.fr       */
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
int		ft_max_arr_a(int *arr, int len_a, t_data *data);
int		ft_min_arr_a(int *arr, int len_a, t_data *data);
int		ft_count_mov_a(int *stacka, int prepare_mov_a, int len_a, t_data *data);
void	ft_mov_c(t_list **stack_a, t_list **stack_b, t_data *data);
int		ft_both_numbers(int i, t_data *data);
int		ft_case_negative_positive(int i, t_data *data);
int		ft_min_mov_c(t_data *data);

#endif
