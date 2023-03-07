/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:17:09 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/03/07 12:17:20 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

long int	*ft_fill_arr(int argc, char **argv)
{
	int			i;
	int			j;
	long int	*arr;

	i = 1;
	j = 0;
	arr = (long int *)ft_calloc(sizeof(long int), argc);
	while (i < argc)
	{
		arr[j] = ft_atoi(argv[i]);
		j++;
		i++;
	}
	return (arr);
}

int	ft_check_db(int tmp, long int *arr, int size)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < size)
	{
		if (tmp == arr[i])
			count++;
		i++;
	}
	return (count);
}

void	ft_check_double_and_limit(int argc, char **argv)
{
	int			i;
	long int	*arr;
	int			tmp;
	int			size;

	i = 0;
	size = argc - 1;
	arr = ft_fill_arr(argc, argv);
	while (i < size)
	{
		tmp = arr[i];
		if (ft_check_db(tmp, arr, size) > 1)
		{
			write(1, "Error\n", 6);
			free (arr);
			exit (1);
		}
		i++;
	}
	ft_check_limit (arr, size);
	free (arr);
}

void	ft_check_num(char *arr)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen(arr);
	while (arr[i])
	{
		if ((arr[i] >= '0' && arr[i] <= '9') || arr[i] == '-')
			i++;
		else
			break ;
	}
	if (i != size)
	{
		write(1, "Error\n", 6);
		exit (1);
	}
}

void	ft_check_all(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		ft_check_num(argv[i]);
		i++;
	}
	ft_check_double_and_limit (argc, argv);
}
