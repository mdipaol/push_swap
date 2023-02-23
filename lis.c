/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:41:51 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/02/22 17:23:41 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_create_lis(int *arr, int *lenght)
{
	int	i;
	int	j;
	int	tmp;
	int	*lis;
	int y = 0;
	i = 0;
	j = 0;
	tmp = lenght[i];
	while (lenght[i])
	{
		if (tmp < lenght[i])
		{
			tmp = lenght[i];
			j = tmp;
		}
		i++;
	}
	tmp = tmp - 1;
	lis = (int *)ft_calloc(sizeof(int), tmp);
	printf("tmp=%d\n", tmp);
	printf("j=%d\n", j);
	lis[tmp] = arr[j];
	/* printf("arr[j]=%d\n", arr[j]);
	printf("lis[tmp]=%d\n", lis[tmp]);
	printf("lenght[j]=%d\n", lenght[j]); */
	j--;
	while (j >= -1)
	{
		if (lenght[j] == tmp)
		{
			/* printf("tmp=%d\n", tmp);
			printf("lenght[j]=%d\n", lenght[j]); */
			printf("j=%d\n", j);
			lis[tmp] = arr[j+1];
			tmp--;
		}
			j--;
	}
	while (y < 10)
	{
		printf("%d ", lis[y]);
		y++;
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
	i = 0;
	while (lenght[i])
	{
		printf("%d ", lenght[i]);
		i++;
	}
	printf("\n");
	ft_create_lis(arr, lenght);
}

void	ft_prepare_lis(t_list **stack_a, t_data *data)
{
	int	*arr;
	int	*lenght;

	arr = ft_lst_to_arr(stack_a);
	lenght = (int *)ft_calloc(sizeof(int), data->size_stack + 1);
	ft_lis(arr, lenght, data);
}
