/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:58:53 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/02/27 19:21:36 by mdi-paol         ###   ########.fr       */
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
