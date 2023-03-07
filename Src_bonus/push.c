/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:14:24 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/03/06 19:38:12 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap_bonus.h"

void	ft_pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_1;

	tmp_1 = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp_1->next = *stack_a;
	*stack_a = tmp_1;
}

void	ft_pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_1;

	tmp_1 = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp_1->next = *stack_b;
	*stack_b = tmp_1;
}
