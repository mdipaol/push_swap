/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:44:21 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/03/01 17:32:12 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_count_mov_a(int *stacka, int prepare_mov_a, int len_a)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < len_a)
	{
		if (prepare_mov_a == stacka[i] && i <= (len_a / 2))
			j = i;
		else if (prepare_mov_a == stacka[i] && i <= len_a)
			j = i - len_a;
		i++;
	}
	return (j);
}

int	ft_min_arr_a(int *arr, int len_a)
{
	int	i;
	int	a;

	i = 1;
	a = arr[0];
	while (i < len_a)
	{
		if (arr[i] < a)
			a = arr[i];
		i++;
	}
	return (a);
}


int	ft_max_arr_a(int *arr, int len_a)
{
	int	i;
	int	a;

	i = 0;
	a = arr[i];
	while (i < len_a)
	{
		if (arr[i] > a)
			a = arr[i];
		i++;
	}
	return (a);
}

int	*ft_lst_to_arr(t_list **stack)
{
	t_list	*tmp;
	int		*arr;
	int		size_lst;
	int		i;

	i = 0;
	tmp = *stack;
	size_lst = ft_lstsize(*stack);
	arr = (int *)ft_calloc(sizeof(int), size_lst + 1);
	while (tmp)
	{
		arr[i] = (tmp)->content;
		tmp = (tmp)->next;
		i++;
	}
	return (arr);
}

void	ft_order_arr(int *arr, t_data *data)
{
	int	i;

	i = 1;
	data->a_ord = 0;
	while (i < data->size_stack_a && arr[i] >= arr[i - 1])
		i++;
	if (i == (data->size_stack_a))
		data->a_ord = 1;
	else
		data->a_ord = 0;
}
