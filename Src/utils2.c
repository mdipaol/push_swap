/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:54:09 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/03/06 18:19:47 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_free_order(t_data *data)
{
	free(data->mov_a);
	free(data->mov_b);
	free(data->mov_c);
}

void	ft_initialize(t_data *data)
{
	data->c_1 = 0;
	data->c_2 = 0;
	data->c_3 = 0;
	data->c_4 = 0;
	data->c_5 = 0;
}

void	ft_last_order_3(t_list **stack_a, int j, int size)
{
	if (j < size / 2)
	{
		while (j > 0)
		{
			ft_ra(stack_a);
			j--;
		}
	}
	else if (j < size)
	{
		while (j < size)
		{
			ft_rra(stack_a);
			j++;
		}
	}
}

void	ft_last_order_2(t_list **stack_a, int *stacka, int size, int min)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		if (stacka[i] == min)
			j = i;
		i++;
	}
	ft_last_order_3(stack_a, j, size);
}
