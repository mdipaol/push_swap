/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:05:12 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/02/28 19:19:44 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 09/02/22 12:05

#include "pushswap.h"

void	ft_last_order(t_list **stack_a) //FINIRE
{
	int *stacka;
	int	size;
	int	min;
	int	i;

	i = 0;
	stacka = ft_lst_to_arr(stack_a);
	size = ft_lstsize(*stack_a);
	min = ft_min(stacka, size);
	while (i < size)
	{
		if (i <= size / 2)
			ft_ra(stack_a);
		else
			ft_rra(stack_a);
		i++;
	}
}

void	ft_order_manager(t_list **stack_a, t_list **stack_b, t_data *data)
{
	int	i;

	ft_prepare_lis(stack_a, stack_b, data);
	i = ft_lstsize(*stack_b);
	while (i > 0)
	{
		int	*stacka = ft_lst_to_arr(stack_a);
		int	*stackb = ft_lst_to_arr(stack_b);
		data->stacka = stacka;
		data->stackb = stackb;
		ft_mov_b(stack_b, data);
		ft_prepare_mov_a(stack_a, stack_b, data);
		ft_mov_c(data);
		ft_choose_push_a(stack_a, stack_b, data);
		i = ft_lstsize(*stack_b);
	}
	ft_last_order(stack_a);
}

void	ft_ord_s(int argc, t_list **stack_a, t_list **stack_b, t_data *data)
{
	int	*arr;

	arr = ft_lst_to_arr(stack_a);
	ft_order_arr(arr, data);
	if (!data->a_ord)
	{
		if (argc == 4)
			ft_three_numbers(stack_a, data);
		else if (argc == 5)
			ft_four_numbers(stack_a, stack_b, data);
		else if (argc == 6)
			ft_five_numbers(stack_a, stack_b, data);
		else if (argc > 6)
			ft_order_manager(stack_a, stack_b, data);
	}
	free (arr);
}

void	ft_fill_a(t_list **stack_a, char *argv, t_data *data)
{
	t_list	*tmp;

	data->size_stack_a = 0;
	tmp = ft_lstnew(ft_atoi(argv));
	ft_lstadd_back(stack_a, tmp);
	data->size_stack_a = ft_lstsize(*stack_a);
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
		ft_fill_a(&stack_a, argv[i], &data);
		i++;
	}
	ft_ord_s(argc, &stack_a, &stack_b, &data);
}
