/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:48:37 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/02/27 00:12:17 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_create_mov_a(int *stacka, int *prepare_mov_a, t_data *data)
{
	int	i;
	i = 0;

	while (i < data->size_stack_b)
	{
		printf("%d ", prepare_mov_a[i]);
		i++;
	}
}

void	ft_mov_a(t_list **stack_a, int *stacka, int *stackb, int *prepare_mov_a, t_data *data)
{
	int	i;
	int	j;
	int	flag;
	int	y;
	int	len = ft_lstsize(*stack_a);
	int	max = ft_max_arr_a(stacka, data);
	int	min = ft_min_arr_a(stacka, len, data);
	printf("max=%d\n", max);
	printf("min=%d\n", min);
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
	ft_create_mov_a (stacka, prepare_mov_a, data);
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
}
