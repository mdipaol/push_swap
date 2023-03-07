/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 19:24:31 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/03/06 19:38:46 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap_bonus.h"

void	ft_free_stack_a(t_list **stack_a)
{
	t_list	*tmp;

	while (*stack_a)
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		free(tmp);
	}
}

int	*ft_lst_to_arr(t_list **stack)
{
	t_list	*tmp;
	int		*arr;
	int		size_lst;
	int		i;

	i = 0;
	tmp = *stack;
	size_lst = ft_lstsize(*stack);
	arr = (int *)ft_calloc(sizeof(int), size_lst + 1);
	while (tmp)
	{
		arr[i] = (tmp)->content;
		tmp = (tmp)->next;
		i++;
	}
	return (arr);
}

void	ft_order_arr(int *arr, t_data *data)
{
	int	i;

	i = 1;
	data->a_ord = 0;
	while (i < data->size_stack_a && arr[i] >= arr[i - 1])
		i++;
	if (i == (data->size_stack_a))
		data->a_ord = 1;
	else
		data->a_ord = 0;
}
