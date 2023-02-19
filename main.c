/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:05:12 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/02/19 15:37:50 by mdi-paol         ###   ########.fr       */
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
	int		i;

	i = 1;
	stack_a = NULL;
	stack_b = NULL;
	while (i < argc)
	{
		ft_fill_a(&stack_a, argv[i]);
		i++;
	}
	ft_sa(&stack_a);
}
