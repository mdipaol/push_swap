/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:48:37 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/03/07 17:14:48 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_create_mov_a(int *stacka, int len_a, t_data *data)
{
	int	j;
	int	*mov_a;
	int	y;

	j = 0;
	y = 0;
	mov_a = (int *)ft_calloc(sizeof(int), data->size_stack_b);
	while (j <= data->size_stack_b - 1)
	{
		mov_a[j] = ft_count_mov_a(stacka, data->prepare_mov_a[y], len_a);
		j++;
		y++;
	}
	data->mov_a = mov_a;
}

void	ft_mov_a(t_list **stack_a, int *stacka, int *stackb, t_data *data)
{
	int	i;
	int	y;
	int	len_a;
	int	max;
	int	min;

	i = 0;
	y = 0;
	len_a = ft_lstsize(*stack_a);
	min = ft_min_arr_a(stacka, len_a);
	max = ft_max_arr_a(stacka, len_a);
	while (i < data->size_stack_b)
	{
		if (stackb[i] < max)
			data->prepare_mov_a[y] = ft_search_min_mov_a(stacka, \
			stackb[i], len_a);
		else if (stackb[i] > max)
			data->prepare_mov_a[y] = min;
		y++;
		i++;
	}
	ft_create_mov_a (stacka, len_a, data);
}

void	ft_prepare_mov_a(t_list **stack_a, t_list **stack_b, t_data *data)
{
	int	*stacka;
	int	*stackb;

	stacka = ft_lst_to_arr(stack_a);
	stackb = ft_lst_to_arr(stack_b);
	data->prepare_mov_a = (int *)ft_calloc(sizeof(int), data->size_stack_b);
	ft_mov_a(stack_a, stacka, stackb, data);
	free(data->prepare_mov_a);
	free(stacka);
	free(stackb);
}

void	ft_mov_b(t_list **stack_b, t_data *data)
{
	int	*mov_b;
	int	i;

	i = 0;
	data->size_stack_b = ft_lstsize(*stack_b);
	mov_b = (int *)ft_calloc(sizeof(int), data->size_stack_b);
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
