/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 20:14:26 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/02/27 21:02:06 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_case_both_positive_pa(t_list **stack_a, t_list **stack_b, int i, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->x || i < data->y)
	{
		ft_rr(stack_a, stack_b);
		i++;
		data->x--;
		data->y--;
	}
	while (data->x > 0)
	{
		ft_ra(stack_a);
		data->x--;
	}
	while (data->y > 0)
	{
		ft_rb(stack_b);
		data->y--;
	}
	ft_pa(stack_a, stack_b);
}

void	ft_case_both_negative_pa(t_list **stack_a, t_list **stack_b, int i, t_data *data)  //DA FINIRE, CONTROLLA, MANUEL DEL FUTURO
{
	int	i;

	i = 0;
	while (i < data->x || i < data->y)
	{
		ft_rrr(stack_a, stack_b);
		i++;
		data->x--;
		data->y--;
	}
	while (data->x > 0)
	{
		ft_rra(stack_a);
		data->x--;
	}
	while (data->y > 0)
	{
		ft_rrb(stack_b);
		data->y--;
	}
	ft_pa(stack_a, stack_b);
}

/* void	ft_case_positive_negative_pa(int i, t_data *data)
{

}

void	ft_case_negative_positive_pa(int i, t_data *data)
{

} */

