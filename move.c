/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:48:37 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/02/25 19:38:03 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"



void	ft_move_a(int *stacka, int *stackb, int *prepare_move_a, t_data *data)
{
	int	i;
	int	j;
	int	flag;
	int	y;

	i = 0;
	j = 0;
	y = data->size_stack_b - 1;
	while (i < data->size_stack_b)
	{
		j = 0;
		flag = 1;
		while (j < data->size_stack_a)
		{
			if (stacka[j] > stackb[i] && flag)
			{
				prepare_move_a[y] = stacka[j];
				flag = 0;
				y--;
			}
			else if ()// se in stack b il numero e' il piu grande dello stacka considera il numero piu piccolo, per il punto di inserzione
					  // manuel del futuro, fai una variabile da salvare nella struct max e min
			j++;
		}
		i++;
	}
	i = 0;
	while (i < data->size_stack_b)
	{
		printf("%d ", prepare_move_a[i]);
		i++;
	}
}


void	ft_prepare_mov_a(t_list **stack_a, t_list **stack_b, t_data *data)
{
	int	*prepare_mov_a;
	int	*stacka;
	int	*stackb;

	stacka = ft_lst_to_arr(stack_a);
	stackb = ft_lst_to_arr(stack_b);
	prepare_mov_a = (int *)ft_calloc(sizeof(int), data->size_stack_b);
	ft_move_a(stacka, stackb, prepare_mov_a, data);
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
