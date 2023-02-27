/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:44:21 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/02/27 19:15:08 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_count_mov_a(int *stacka, int prepare_mov_a, int len_a, t_data *data)
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

int	ft_min_arr_a(int *arr, int len_a, t_data *data)
{
	int	i;
	int	a;

	i = 1;
	a = arr[0];
	//printf("len=%d ", len);
	while (i < len_a)
	{
		//printf("i=%d ", i);
		if (arr[i] < a)
			a = arr[i];
		//printf("a=%d ", a);
		i++;
	}
	int j = 0;
	/* while (arr[j])
	{
		printf("arr=%d ", arr[j]);
		j++;
	} */
	return (a);
}


int	ft_max_arr_a(int *arr, int len_a, t_data *data)
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
	while (arr[i] && arr[i] >= arr[i-1])
		i++;
	if (arr[i] == '\0')
		data->a_ord = 1;
	else
		data->a_ord = 0;
}
