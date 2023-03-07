/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:14:41 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/03/06 19:37:45 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap_bonus.h"

void	ft_swap(t_list **stack)
{
	t_list	*tmp_1;
	t_list	*tmp_2;

	tmp_1 = *stack;
	*stack = (*stack)->next;
	tmp_2 = (*stack)->next;
	(*stack)->next = tmp_1;
	tmp_1->next = tmp_2;
}

void	ft_sa(t_list **stack_a)
{
	ft_swap(stack_a);
}

void	ft_sb(t_list **stack_b)
{
	ft_swap(stack_b);
}

void	ft_ss(t_list **stack_a, t_list **stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
}
