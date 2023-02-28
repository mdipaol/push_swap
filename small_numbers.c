/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:53:39 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/02/28 18:41:19 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_initialize(t_data *data)
{
	data->c_1 = 0;
	data->c_2 = 0;
	data->c_3 = 0;
	data->c_4 = 0;
	data->c_5 = 0;
}

void	ft_check_three_number(t_list **stack_a, t_data *data)
{
	int	*a;

	a = ft_lst_to_arr(stack_a);
	ft_initialize(data);
	if (a[0] > a[1] && a[1] < a[2] && a[2] > a[0])
		data->c_1 = 1;
	if (a[0] > a[1] && a[1] > a[2] && a[2] < a[0])
		data->c_2 = 1;
	if (a[0] > a[1] && a[1] < a[2] && a[2] < a[0])
		data->c_3 = 1;
	if (a[0] < a[1] && a[1] > a[2] && a[2] > a[0])
		data->c_4 = 1;
	if (a[0] < a[1] && a[1] > a[2] && a[2] < a[0])
		data->c_5 = 1;
	free (a);
}

void	ft_three_numbers(t_list **stack_a, t_data *data)
{
	ft_check_three_number(stack_a, data);
	if (data->c_1)
	{
		ft_sa(stack_a);
	}
	if (data->c_2)
	{
		ft_sa(stack_a);
		ft_rra(stack_a);
	}
	if (data->c_3)
		ft_ra(stack_a);
	if (data->c_4)
	{
		ft_sa(stack_a);
		ft_ra(stack_a);
	}
	if (data->c_5)
		ft_rra(stack_a);
}

void	ft_four_numbers(t_list **stack_a, t_list **stack_b, t_data *data)
{
	int	*a;

	a = ft_lst_to_arr(stack_a);
	if (a[0] < a[1] && a[0] < a[2] && a[0] < a[3])
		ft_pb(stack_a, stack_b);
	if (a[1] < a[0] && a[1] < a[2] && a[1] < a[3])
	{
		ft_ra(stack_a);
		ft_pb(stack_a, stack_b);
	}
	if (a[2] < a[0] && a[2] < a[1] && a[2] < a[3])
	{
		ft_ra(stack_a);
		ft_ra(stack_a);
		ft_pb(stack_a, stack_b);
	}
	if (a[3] < a[0] && a[3] < a[1] && a[3] < a[2])
	{
		ft_rra(stack_a);
		ft_pb(stack_a, stack_b);
	}
	ft_three_numbers(stack_a, data);
	ft_pa(stack_a, stack_b);
	free (a);
}

void	ft_five_numbers(t_list **stack_a, t_list **stack_b, t_data *data)
{
	int	*a;

	a = ft_lst_to_arr(stack_a);
	if (a[0] > a[1] && a[0] > a[2] && a[0] > a[3] && a[0] > a[4])
		ft_pb(stack_a, stack_b);
	if (a[1] > a[0] && a[1] > a[2] && a[1] > a[3] && a[1] > a[4])
	{
		ft_ra(stack_a);
		ft_pb(stack_a, stack_b);
	}
	if (a[2] > a[0] && a[2] > a[1] && a[2] > a[3] && a[2] > a[4])
	{
		ft_ra(stack_a);
		ft_ra(stack_a);
		ft_pb(stack_a, stack_b);
	}
	if (a[3] > a[0] && a[3] > a[1] && a[3] > a[2] && a[3] > a[4])
	{
		ft_rra(stack_a);
		ft_rra(stack_a);
		ft_pb(stack_a, stack_b);
	}
	if (a[4] > a[0] && a[4] > a[1] && a[4] > a[2] && a[4] > a[3])
	{
		ft_rra(stack_a);
		ft_pb(stack_a, stack_b);
	}
	ft_four_numbers(stack_a, stack_b, data);
	ft_pa(stack_a, stack_b);
	ft_ra(stack_a);
	free (a);
}
