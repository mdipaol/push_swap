/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:38:13 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/03/07 17:44:49 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap_bonus.h"

void	ft_check_ord(t_list **stack_a, t_data *data)
{
	int	*a;

	a = ft_lst_to_arr (stack_a);
	ft_order_arr(a, data);
	if (data->a_ord)
		write (1, "OK\n", 3);
	if (!data->a_ord)
		write (1, "KO\n", 3);
	free (a);
	ft_free_stack_a (stack_a);
}

void	ft_check_move(t_list **stack_a, t_list **stack_b, char *s)
{
	if (!ft_strncmp(s, "sa\n", 3))
		ft_sa(stack_a);
	else if (!ft_strncmp(s, "sb\n", 3))
	{
		if (stack_b)
			ft_sb(stack_b);
	}
	else if (!ft_strncmp(s, "ss\n", 3))
	{
		if (stack_b)
			ft_ss(stack_a, stack_b);
	}
	else if (!ft_strncmp(s, "ra\n", 3))
		ft_ra(stack_a);
	else if (!ft_strncmp(s, "rb\n", 3))
	{
		if (stack_b)
			ft_rb(stack_b);
	}
	else if (!ft_strncmp(s, "rr\n", 3))
	{
		if (stack_b)
			ft_rr(stack_a, stack_b);
	}
	ft_check_move_2(stack_a, stack_b, s);
}

void	ft_check(t_list **stack_a, t_list **stack_b, t_data *data)
{
	char	*s;

	s = get_next_line(0);
	if (!ft_strncmp(s, "Error\n", 6))
	{
		write(1, "Error\n", 6);
		exit (1);
	}
	while (s)
	{
		ft_check_move(stack_a, stack_b, s);
		free(s);
		s = get_next_line(0);
	}
	free (s);
	ft_check_ord(stack_a, data);
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
	ft_check(&stack_a, &stack_b, &data);
}
