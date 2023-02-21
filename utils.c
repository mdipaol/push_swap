/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:44:21 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/02/21 11:37:11 by mdi-paol         ###   ########.fr       */
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
