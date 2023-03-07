/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:14:48 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/03/06 19:32:01 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap_bonus.h"

void	ft_rotate(t_list **stack)
{
	t_list	*tmp_1;

	tmp_1 = *stack;
	*stack = (*stack)->next;
	ft_lstadd_back(stack, tmp_1);
}

void	ft_ra(t_list **stack_a)
{
	ft_rotate(stack_a);
}

void	ft_rb(t_list **stack_b)
{
	ft_rotate(stack_b);
}

void	ft_rr(t_list **stack_a, t_list **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
}
