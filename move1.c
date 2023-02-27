/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:43:19 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/02/27 19:14:47 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_case_positive_negative(int i, t_data *data)
{
	int	a;

	a = 0;
	a = data->mov_a[i] + (data->mov_b[i] * (-1));
	return (a);
}

int	ft_case_both_negative(int i, t_data *data)
{
	int	a;

	a = 0;
	if (data->mov_a[i] < data->mov_b[i])
	{
		a = data->mov_a[i] * (-1);
		i++;
	}
	else
	{
		a = data->mov_b[i] * (-1);
		i++;
	}
	return (a);
}

int	ft_case_both_positive(int i, t_data *data)
{
	int	a;

	a = 0;
	if (data->mov_a[i] > data->mov_b[i])
	{
		a = data->mov_a[i];
		i++;
	}
	else
	{
		a = data->mov_b[i];
		i++;
	}
	return (a);
}

int	*ft_create_mov_c(int *mov_c, t_data *data)
{
	int	i;
	int	flag;

	i = 0;
	while (i < data->size_stack_b)
	{
		flag = ft_both_numbers(i, data);
		if (flag == 0)
			mov_c[i] = ft_case_both_positive(i, data);
		if (flag == 1)
			mov_c[i] = ft_case_both_negative(i, data);
		if (flag == 2)
			mov_c[i] = ft_case_positive_negative(i, data);
		if (flag == 3)
			mov_c[i] = ft_case_negative_positive(i, data);
		i++;
	}
	return (mov_c);
}
void	ft_print(int *mov_c, t_data *data)
{
	int	i = 0;
	printf ("mov_a= ");
	while (i < data->size_stack_b)
	{
		printf("|%d|", data->mov_a[i]);
		i++;
	}
	printf("\n");
	i = 0;
	printf("mov_b= ");
	while (i < data->size_stack_b)
	{
		printf("|%d|", data->mov_b[i]);
		i++;
	}
	printf("\n");
	i = 0;
	printf("mov_c= ");
	while (i < data->size_stack_b)
	{
		printf("|%d|", mov_c[i]);
		i++;
	}
	printf("\n");
}

void	ft_mov_c(t_list **stack_a, t_list **stack_b, t_data *data)
{
	int	i;
	int	j;
	int	*mov_c;

	i = 0;
	j = 0;
	mov_c = (int *)ft_calloc(sizeof(int), data->size_stack_b);
	mov_c = ft_create_mov_c(mov_c, data);
	data->mov_c = mov_c;
	ft_print(mov_c, data);
}

