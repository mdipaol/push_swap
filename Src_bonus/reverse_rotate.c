/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:14:45 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/03/06 19:32:01 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap_bonus.h"

void	ft_rrotate(t_list **stack)
{
	t_list	*tmp_1;
	t_list	*tmp_2;

	tmp_1 = *stack;
	while ((tmp_1)->next)
	{
		tmp_2 = tmp_1;
		tmp_1 = tmp_1->next;
	}
	tmp_1->next = *stack;
	tmp_2->next = NULL;
	*stack = tmp_1;
}

void	ft_rra(t_list **stack_a)
{
	ft_rrotate(stack_a);
}

void	ft_rrb(t_list **stack_b)
{
	ft_rrotate(stack_b);
}

void	ft_rrr(t_list **stack_a, t_list **stack_b)
{
	ft_rrotate(stack_a);
	ft_rrotate(stack_b);
}
