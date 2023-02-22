/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:41:51 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/02/22 14:26:11 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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
	i = 0;
	while (lenght[i])
	{
		printf("%d ", lenght[i]);
		i++;
	}
}

void	ft_prepare_lis(t_list **stack_a, t_data *data)
{
	int	*arr;
	int	*lenght;

	arr = ft_lst_to_arr(stack_a);
	lenght = (int *)ft_calloc(sizeof(int), data->size_stack + 1);
	ft_lis(arr, lenght, data);
}
