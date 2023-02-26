/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:41:51 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/02/25 19:44:31 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_max_lis(int *lenght)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	tmp = lenght[i];
	while (lenght[i])
	{
		if (tmp < lenght[i])
		{
			tmp = lenght[i];
		}
		i++;
	}
	return (tmp);
}

void	ft_create_lis(int *arr, int *lenght, t_data *data)
{
	int	j;
	int	flag;
	int	max;
	int	size;

	size = data->size_stack_a;
	max = ft_max_lis(lenght);
	data->max_lis = max;
	data->lis = (int *)ft_calloc(sizeof(int), max);
	while (max > 0)
	{
		j = size - 1;
		flag = 1;
		while (j >= 0)
		{
			if (lenght[j] == max && flag)
			{
				data->lis[max - 1] = arr[j];
				size = j;
				flag = 0;
			}
			j--;
		}
		max--;
	}
}

void	ft_lis(int *arr, int *lenght, t_data *data)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	lenght[0] = 1;
	while (i < data->size_stack_a)
	{
		lenght[i] = 1;
		j = 0;
		while (j < i)
		{
			if (arr[i] > arr[j] && lenght[i] < lenght[j] + 1)
			{
				lenght[i] = lenght[j] + 1;
			}
			j++;
		}
		i++;
	}
	ft_create_lis(arr, lenght, data);
}

void	ft_push_lis(t_list **stack_a, t_list **stack_b, t_data *data)
{
	int	i;
	int	j;
	int	*arr;

	i = 0;
	j = 0;
	arr = ft_lst_to_arr(stack_a);
	while (i < data->size_stack_a)
	{
		if (arr[i] == data->lis[j] && j < data->max_lis)
		{
			ft_ra(stack_a);
			i++;
			j++;
		}
		else
		{
			ft_pb(stack_a, stack_b);
			i++;
		}
	}
	free (arr);
}

void	ft_prepare_lis(t_list **stack_a, t_list **stack_b, t_data *data)
{
	int	*arr;
	int	*lenght;

	arr = ft_lst_to_arr(stack_a);
	lenght = (int *)ft_calloc(sizeof(int), data->size_stack_a + 1);
	ft_lis(arr, lenght, data);
	free (arr);
	ft_push_lis(stack_a, stack_b, data);
}
