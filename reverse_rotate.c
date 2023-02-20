/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:14:45 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/02/20 10:04:25 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_rrotate(t_list **stack)
{
	t_list	*tmp_1;
	t_list	*tmp_2;

	tmp_1 = *stack;
	while ((*stack)->next)
	{
		tmp_2 = *stack;
		*stack = (*stack)->next;
	}
	tmp_2->next =
}

void	ft_rra(t_list **stack_a)
{
	ft_rrotate(stack_a);
	while ((*stack_a))
	{
		printf("%d ", (*stack_a)->content);
		*stack_a = (*stack_a)->next;
	}
	//write(1, "rra\n", 4);
}

void	ft_rrb(t_list **stack_b)
{
	ft_rrotate(stack_b);
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_list **stack_a, t_list **stack_b)
{
	ft_rra(stack_a);
	ft_rrb(stack_b);
	write(1, "rrr\n", 4);
}
