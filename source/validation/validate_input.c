/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carfern2 <carfern2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 13:54:07 by carfern2          #+#    #+#             */
/*   Updated: 2025/02/10 13:37:24 by carfern2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	is_integer(const char *str)
{
	int		i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (!isdigit (str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	has_duplicates(int *arr, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	convert_to_integers(int argc, char **argv, int *values)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (!is_integer(argv[i]))
			return (0);
		values[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	return (1);
}

int	validate_input(int argc, char **argv)
{
	int		*values;

	if (argc < 2)
		return (0);
	values = (int *)malloc(sizeof(int) * (argc - 1));
	if (!values)
		return (0);
	if (!convert_to_integers(argc, argv, values))
	{
		free(values);
		return (0);
	}
	if (has_duplicates(values, argc - 1))
	{
		free (values);
		return (0);
	}
	free (values);
	return (1);
}
