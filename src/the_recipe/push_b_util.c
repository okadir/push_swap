/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitkadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:46:14 by haitkadi          #+#    #+#             */
/*   Updated: 2022/04/04 19:47:39 by haitkadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	n_to_pb(t_stack *stack, int len)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (i < len)
	{
		if (stack->a[i] < stack->pivot_a)
			res++;
		i++;
	}
	return (res);
}

int	best_move_a(t_stack *stack)
{
	int	i;
	int	moves;
	int	final_moves;

	i = 0;
	final_moves = 0;
	if (stack->a[0] < stack->pivot_a)
		return (0);
	while (i < stack->a_len)
	{
		if (stack->a[i] < stack->pivot_a)
		{
			moves = i;
			if (i > stack->a_len / 2)
				moves = (stack->a_len - i) * -1;
			if (final_moves == 0)
				final_moves = moves;
			if (abs(moves) < abs(final_moves))
				final_moves = moves;
		}
		i++;
	}
	return (final_moves);
}
