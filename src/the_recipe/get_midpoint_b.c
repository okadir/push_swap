/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_midpoint_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitkadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:37:35 by haitkadi          #+#    #+#             */
/*   Updated: 2022/04/04 19:37:38 by haitkadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static	int	*ft_intdup(t_stack *stack)
{
	int	i;
	int	*arr;

	arr = 0;
	arr = (int *)ft_calloc(stack->b_len, sizeof(int));
	if (!arr)
		exit(-1);
	i = 0;
	while (i < stack->b_len)
	{
		arr[i] = stack->b[i];
		i++;
	}
	return (arr);
}

static	int	partition(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = arr[high];
	i = (low - 1);
	j = low;
	while (j < high)
	{
		if (arr[j] >= pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
		j++;
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

static	void	quick_sort(int *arr, int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = partition(arr, low, high);
		quick_sort(arr, low, pi - 1);
		quick_sort(arr, pi + 1, high);
	}
}

int	get_midpoint_b(t_stack *stack, int chanck_len, int fixed_len)
{
	int	i;
	int	*newarr;
	int	res;

	i = 0;
	newarr = ft_intdup(stack);
	if (!newarr)
		exit(-1);
	quick_sort(newarr, 0, stack->b_len - 1);
	i = (chanck_len / 2);
	res = newarr[i];
	if (chanck_len == fixed_len)
	{
		stack->b_chunck_max = newarr[0];
		stack->b_chunck_min = newarr[chanck_len - 1];
	}
	free(newarr);
	return (res);
}
