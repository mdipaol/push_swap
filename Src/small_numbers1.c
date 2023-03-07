/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_numbers1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:09:32 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/03/06 17:59:30 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_move_five_numbers(int *a, t_list **stack_a, t_list **stack_b)
{
	if (a[0] > a[1] && a[0] > a[2] && a[0] > a[3] && a[0] > a[4])
		ft_pb(stack_a, stack_b);
	if (a[1] > a[0] && a[1] > a[2] && a[1] > a[3] && a[1] > a[4])
	{
		ft_ra(stack_a);
		ft_pb(stack_a, stack_b);
	}
	if (a[2] > a[0] && a[2] > a[1] && a[2] > a[3] && a[2] > a[4])
	{
		ft_ra(stack_a);
		ft_ra(stack_a);
		ft_pb(stack_a, stack_b);
	}
	if (a[3] > a[0] && a[3] > a[1] && a[3] > a[2] && a[3] > a[4])
	{
		ft_rra(stack_a);
		ft_rra(stack_a);
		ft_pb(stack_a, stack_b);
	}
	if (a[4] > a[0] && a[4] > a[1] && a[4] > a[2] && a[4] > a[3])
	{
		ft_rra(stack_a);
		ft_pb(stack_a, stack_b);
	}
}
