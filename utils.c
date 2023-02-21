/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:44:21 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/02/21 15:55:18 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	*ft_lst_to_arr(t_list **stack)
{
	t_list	*tmp;
	int	*arr;
	int	size_lst;
	int	i;

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
	while (arr[i] && arr[i] >= arr[i-1])
		i++;
	if (arr[i] == '\0')
		data->a_ord = 1;
	else
		data->a_ord = 0;
}
