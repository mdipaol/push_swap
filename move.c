/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:48:37 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/02/24 18:13:18 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_mov_b(t_list **stack_a, t_list **stack_b, t_data *data)
{
	int	*stack_b;
	int	i;

	i = 0;
	data->size_stack_b = ft_lstsize(*stack_b);
	stack_b = ft_lst_to_arr(stack_b);
	while (stack_a[i])
	{
		if ()
	}
}
