/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:17:09 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/03/01 19:59:38 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_check_all(int argc, char **argv)
{
	char	*arr;
	int	i;
	int	j = 0;
	i = 1;
	arr = (char *)ft_calloc(sizeof(char), argc);
	while (i < argc)
	{
		while (argv[i][j])
		{
			arr[i] = argv[i][j];
			j++;
		}
		i++;
	}
	i = 0;
	while(i < argc)
	{
		printf("%c", arr[i]);
		i++;
	}
}
