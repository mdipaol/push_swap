/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:05:12 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/02/20 13:08:40 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 09/02/22 12:05

#include "pushswap.h"

void	ft_fill_a(t_list **stack_a, char *argv)
{
	t_list	*tmp;

	tmp = ft_lstnew(ft_atoi(argv));
	ft_lstadd_back(stack_a, tmp);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_data	data;
	int		i;

	i = 1;
	stack_a = NULL;
	stack_b = NULL;
	while (i < argc)
	{
		ft_fill_a(&stack_a, argv[i]);
		i++;
	}
	if (argc == 3)
		ft_three_numbers(&stack_a, &data);
/* 	if (argc == 4)
		ft_four_numbers(&stack_a, &stack_b);
	if (argc == 5)
		ft_five_numbers(&stack_a, &stack_b); */
}
