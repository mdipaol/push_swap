/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:14:41 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/02/20 09:40:42 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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
	write(1, "sa\n", 3);
}

void	ft_sb(t_list **stack_b)
{
	ft_swap(stack_b);
	write(1, "sb\n", 3);
}

void	ft_ss(t_list **stack_a, t_list **stack_b)
{
	ft_sa(stack_a);
	ft_sb(stack_b);
	write(1, "ss\n", 3);
}
