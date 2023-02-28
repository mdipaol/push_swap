/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:53:29 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/02/28 19:02:41 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_case_negative_positive(int i, t_data *data)
{
	int	a;

	a = 0;
	a = ((data->mov_a[i] * (-1)) + data->mov_b[i]);
	return (a);
}

int	ft_index_push_mov_c(int min_mov_c, t_data *data)
{
	int	i;
	int	index;

	i = 0;
	while (i < data->size_stack_b)
	{
		if (min_mov_c == data->mov_c[i])
			index = i;
		i++;
	}
	return (index);
}

void	ft_correct_push_a(t_list **stack_a, t_list **stack_b, int index, t_data *data)
{
	int	flag;

	flag = ft_both_numbers(index, data);
	if (flag == 0)
		ft_case_both_positive_pa(stack_a, stack_b, data);
	if (flag == 1)
		ft_case_both_negative_pa(stack_a, stack_b, data);
	if (flag == 2)
		ft_case_positive_negative_pa(stack_a, stack_b, data);
	if (flag == 3)
		ft_case_negative_positive_pa(stack_a, stack_b, data);
}

void	ft_choose_push_a(t_list **stack_a, t_list **stack_b, t_data *data)
{
	int	min_mov_c;
	int	index;

	min_mov_c = ft_min_mov_c(data);
	index = ft_index_push_mov_c(min_mov_c, data);
	data->x = data->mov_a[index];
	data->y = data->mov_b[index];
	ft_correct_push_a (stack_a, stack_b, index, data);
}
