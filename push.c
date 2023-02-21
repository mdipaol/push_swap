/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:14:24 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/02/21 16:11:57 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_1;

	tmp_1 = *stack_b;
	if ((*stack_b)->next)
		*stack_b = (*stack_b)->next;
	tmp_1->next = NULL;
	*stack_a = tmp_1;
	write (1, "pa\n", 3);
}

void	ft_pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_1;

	tmp_1 = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp_1->next = NULL;
	*stack_b = tmp_1;
	write (1, "pb\n", 3);
}
