/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:48:37 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/02/24 18:54:33 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_mov_b(t_list **stack_a, t_list **stack_b, t_data *data)
{
	int	*stackb;
	int	*mov_b;
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->size_stack_b = ft_lstsize(*stack_b);
	mov_b = (int *)ft_calloc(sizeof(int), data->size_stack_b);
	stackb = ft_lst_to_arr(stack_b);
	while (*stack_b)
	{
		printf("%d\n", (*stack_b)->content);
		*stack_b = (*stack_b)->next;
	}
	while (i < data->size_stack_b)
	{
		if (i <= data->size_stack_b / 2)
			mov_b[i] = i;
		else
			mov_b[i] = i - data->size_stack_b;
		i++;
	}
	data->mov_b = mov_b;
}
