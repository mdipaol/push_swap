/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:53:39 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/02/21 11:01:02 by mdi-paol         ###   ########.fr       */
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
	int	*arr;
	int	i;

	i = 0;
	arr = ft_lst_to_arr(*stack_a);
	if (arr[0] > arr[1] && arr[1] < arr[2] && arr[2] > arr[0])
		data->c_1 = 1;
	if (arr[0] > arr[1] && arr[1] > arr[2] && arr[2] < arr[0])
		data->c_2 = 1;
	if (arr[0] > arr[1] && arr[1] < arr[2] && arr[2] < arr[0])
		data->c_3 = 1;
	if (arr[0] < arr[1] && arr[1] > arr[2] && arr[2] > arr[0])
		data->c_4 = 1;
	if (arr[0] < arr[1] && arr[1] > arr[2] && arr[2] < arr[0])
		data->c_5 = 1;
	free (arr);
}

void	ft_three_numbers(t_list **stack_a, t_data *data)
{
	ft_initialize(&data);
	ft_check_three_number(*stack_a, &data);
	if (data->c_1)
		ft_sa(*stack_a);
	if (data->c_2)
	{
		ft_sa(*stack_a);
		ft_rra(*stack_a);
	}
	if (data->c_3)
		ft_ra(*stack_a);
	if (data->c_4)
	{
		ft_sa(*stack_a);
		ft_ra(*stack_a);
	}
	if (data->c_5)
		ft_rra(*stack_a);
}
