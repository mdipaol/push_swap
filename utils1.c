/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:58:53 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/02/28 19:00:41 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_both_numbers(int i, t_data *data)
{
	int	flag;

	if (data->mov_a[i] >= 0 && data->mov_b[i] >= 0)
		flag = 0;
	if (data->mov_a[i] < 0 && data->mov_b[i] < 0)
		flag = 1;
	if (data->mov_a[i] >= 0 && data->mov_b[i] < 0)
		flag = 2;
	if (data->mov_a[i] < 0 && data->mov_b[i] >= 0)
		flag = 3;
	return (flag);
}

int	ft_min_mov_c(t_data *data)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = data->mov_c[i];
	while (i < data->size_stack_b)
	{
		if (data->mov_c[i] < tmp)
			tmp = data->mov_c[i];
		i++;
	}
	return (tmp);
}

int	ft_min(int *min, int len_a)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = min[i];
	while (i < len_a)
	{
		if (min[i] < tmp)
			tmp = min[i];
		i++;
	}
	return (tmp);
}

int	ft_search_min_mov_a(int	*stacka, int b, int len_a)
{
	int	i;
	int	j;
	int	tmp;
	int	*min;

	i = 0;
	j = 0;
	min = (int *)ft_calloc(sizeof(int), len_a);
	while (i < len_a)
	{
		if (stacka[i] > b)
		{
			min[j] = stacka[i];
			j++;
		}
		i++;
	}
	tmp = ft_min(min, j);
	i = 0;
	free(min);
	return (tmp);
}
