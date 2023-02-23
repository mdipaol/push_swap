/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:41:51 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/02/23 15:44:44 by mdi-paol         ###   ########.fr       */
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
	int	*lis;
	int	flag;
	int	max;
	int	size;

	size = data->size_stack;
	max = ft_max_lis(lenght);
	lis = (int *)ft_calloc(sizeof(int), max);
	while (max > 0)
	{
		j = size - 1;
		flag = 1;
		while (j >= 0)
		{
			if (lenght[j] == max && flag)
			{
				lis[max - 1] = arr[j];
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
	while (i < data->size_stack)
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

void	ft_prepare_lis(t_list **stack_a, t_data *data)
{
	int	*arr;
	int	*lenght;

	arr = ft_lst_to_arr(stack_a);
	lenght = (int *)ft_calloc(sizeof(int), data->size_stack + 1);
	ft_lis(arr, lenght, data);
}
