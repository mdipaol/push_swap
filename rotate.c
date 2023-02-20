/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:14:48 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/02/20 11:26:26 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"


void	ft_rotate(t_list **stack)
{
	t_list	*tmp_1;
	t_list	*tmp_2;

	tmp_1 = *stack;
	while ((*stack)->next)
		*stack = (*stack)->next;
	(*stack)->next = tmp_1;
	tmp_1 = tmp_1->next;
	tmp_1->next = NULL;
}

void	ft_ra(t_list **stack_a)
{
	ft_rotate(stack_a);
	while ((*stack_a))
	{
		printf("%d ", (*stack_a)->content);
		*stack_a = (*stack_a)->next;
	}
	//write(1, "ra\n", 3);
}

void	ft_rb(t_list **stack_b)
{
	ft_rotate(stack_b);
	write(1, "rb\n", 3);
}

void	ft_rr(t_list **stack_a, t_list **stack_b)
{
	ft_ra(stack_a);
	ft_rb(stack_b);
	write(1, "rr\n", 3);
}
