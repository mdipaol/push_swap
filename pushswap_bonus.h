/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:38:56 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/03/07 14:26:07 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_BONUS_H
# define PUSHSWAP_BONUS_H

# include "libft/libft.h"
# include "Get_Next_Line/get_next_line.h"
# include <unistd.h>
# include <stdio.h>

typedef struct s_data
{
	int	size_stack_a;
	int	a_ord;
}			t_data;

void	ft_sa(t_list **stack_a);
void	ft_sb(t_list **stack_b);
void	ft_ss(t_list **stack_a, t_list **stack_b);
void	ft_pa(t_list **stack_a, t_list **stack_b);
void	ft_pb(t_list **stack_a, t_list **stack_b);
void	ft_ra(t_list **stack_a);
void	ft_rb(t_list **stack_b);
void	ft_rr(t_list **stack_a, t_list **stack_b);
void	ft_rra(t_list **stack_a);
void	ft_rrb(t_list **stack_b);
void	ft_rrr(t_list **stack_a, t_list **stack_b);
int		*ft_lst_to_arr(t_list **stack);
void	ft_order_arr(int *arr, t_data *data);
void	ft_free_stack_a(t_list **stack_a);
void	ft_check_move_2(t_list **stack_a, t_list **stack_b, char *s);

#endif
