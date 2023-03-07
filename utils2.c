/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:54:09 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/03/06 17:01:27 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_free_order(t_data *data)
{
	free(data->mov_a);
	free(data->mov_b);
	free(data->mov_c);
}

void	ft_initialize(t_data *data)
{
	data->c_1 = 0;
	data->c_2 = 0;
	data->c_3 = 0;
	data->c_4 = 0;
	data->c_5 = 0;
}