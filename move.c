/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:48:37 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/02/27 19:13:33 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_create_mov_a(int *stacka, int *prepare_mov_a, int len_a, t_data *data)
{
	int	i = 0;
	int	j;
	int	count;
	int	*mov_a;
	int y = 0;

	j = data->size_stack_b - 1;
	while (j > 0)
	{
		mov_a[j] = ft_count_mov_a(stacka, prepare_mov_a[y], len_a, data);
		j--;
		y++;
	}
	data->mov_a = mov_a;
	//free (mov_a);
/* 	printf("mov_a ");
	while (i < data->size_stack_b)
	{
		printf("|%d|", mov_a[i]);
		i++;
	}
	printf("\n"); */
}

void	ft_mov_a(t_list **stack_a, int *stacka, int *stackb, int *prepare_mov_a, t_data *data)
{
	int	i;
	int	j;
	int	flag;
	int	y;
	int	len_a = ft_lstsize(*stack_a);
	int	max = ft_max_arr_a(stacka, len_a, data);
	int	min = ft_min_arr_a(stacka, len_a, data);

	i = 0;
	j = 0;
	y = data->size_stack_b - 1;
	while (i < data->size_stack_b)
	{
		j = 0;
		flag = 1;
		while (j < data->size_stack_a)
		{
			if (stackb[i] < max && stacka[j] > stackb[i] && flag)
			{
				prepare_mov_a[y] = stacka[j];
				flag = 0;
				y--;
			}
			else if (stackb[i] > max && flag)
			{
				prepare_mov_a[y] = min;
				flag = 0;
				y--;
			}// se in stack b il numero e' il piu grande dello stacka considera il numero piu piccolo, per il punto di inserzione
					  // manuel del futuro, fai una variabile da salvare nella struct max e min
			j++;
		}
		i++;
	}
	ft_create_mov_a (stacka, prepare_mov_a, len_a, data);
}


void	ft_prepare_mov_a(t_list **stack_a, t_list **stack_b, t_data *data)
{
	int	*prepare_mov_a;
	int	*stacka;
	int	*stackb;

	stacka = ft_lst_to_arr(stack_a);
	stackb = ft_lst_to_arr(stack_b);
	prepare_mov_a = (int *)ft_calloc(sizeof(int), data->size_stack_b);
	ft_mov_a(stack_a, stacka, stackb, prepare_mov_a, data);
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
	//free (mov_b);
/* 	i = 0;
	printf("mov_b ");
	while (i < data->size_stack_b)
	{
		printf("|%d|", mov_b[i]);
		i++;
	}
	printf("\n"); */
}
