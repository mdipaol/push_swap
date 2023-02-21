/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:41:51 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/02/21 19:29:34 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	*ft_lenght_lis(int *arr, int *lenght)
{
	int	i;
	int	len;

	i = 0;
	while (arr[i])
		len++;
	lenght = (int *)ft_calloc(sizeof(int), len + 1);
	i = 0;
	while (lenght[i])
	{
		lenght[i] = 1;
		i++;
	}
	return (lenght);
}

void	ft_lis(t_list **stack_a, t_data *data)
{
	int	i;
	int	j;
	int	*arr;
	int	*lenght;
	int	*sub_sequence;

	arr = ft_lst_to_arr(stack_a);
	lenght = ft_lenght_lis(arr, lenght);

}
