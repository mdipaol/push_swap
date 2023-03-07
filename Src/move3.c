/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 20:14:26 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/03/07 16:52:30 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_case_both_positive_pa(t_list **stack_a, \
t_list **stack_b, t_data *data)
{
	while (data->x > 0 && data->y > 0)
	{
		ft_rr(stack_a, stack_b);
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
	if (data->x == 0 && data->y == 0)
		ft_pa(stack_a, stack_b);
}

void	ft_case_both_negative_pa(t_list **stack_a, \
t_list **stack_b, t_data *data)
{
	while (data->x < 0 && data->y < 0)
	{
		ft_rrr(stack_a, stack_b);
		data->x++;
		data->y++;
	}
	while (data->x < 0)
	{
		ft_rra(stack_a);
		data->x++;
	}
	while (data->y < 0)
	{
		ft_rrb(stack_b);
		data->y++;
	}
	if (data->x == 0 && data->y == 0)
		ft_pa(stack_a, stack_b);
}

void	ft_case_positive_negative_pa(t_list **stack_a, \
t_list **stack_b, t_data *data)
{
	while (data->x > 0)
	{
		ft_ra(stack_a);
		data->x--;
	}
	while (data->y < 0)
	{
		ft_rrb(stack_b);
		data->y++;
	}
	if (data->x == 0 && data->y == 0)
		ft_pa(stack_a, stack_b);
}

void	ft_case_negative_positive_pa(t_list **stack_a, \
t_list **stack_b, t_data *data)
{
	while (data->x < 0)
	{
		ft_rra(stack_a);
		data->x++;
	}
	while (data->y > 0)
	{
		ft_rb(stack_b);
		data->y--;
	}
	if (data->x == 0 && data->y == 0)
		ft_pa(stack_a, stack_b);
}
