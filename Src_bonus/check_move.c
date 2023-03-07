/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:22:44 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/03/07 16:39:42 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap_bonus.h"

void	ft_check_move_2(t_list **stack_a, t_list **stack_b, char *s)
{
	if (!ft_strncmp(s, "rra\n", 4))
		ft_rra(stack_a);
	else if (!ft_strncmp(s, "rrb\n", 4))
	{
		if (stack_b)
			ft_rrb(stack_b);
	}
	else if (!ft_strncmp(s, "rrr\n", 4))
	{
		if (stack_b)
			ft_rrr(stack_a, stack_b);
	}
	else if (!ft_strncmp(s, "pa\n", 3))
	{
		if (stack_b)
			ft_pa(stack_a, stack_b);
	}
	else if (!ft_strncmp(s, "pb\n", 3))
	{
		if (stack_b)
			ft_pb(stack_a, stack_b);
	}
}
