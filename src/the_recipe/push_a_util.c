/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitkadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:46:05 by haitkadi          #+#    #+#             */
/*   Updated: 2022/04/04 19:46:07 by haitkadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	n_to_pa(t_stack *stack, int len)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (i < len)
	{
		if (stack->b[i] >= stack->pivot_b)
			res++;
		i++;
	}
	return (res);
}

int	best_move_b(t_stack *stack)
{
	int	i;
	int	moves;
	int	final_moves;

	i = 0;
	final_moves = 0;
	if (stack->b[0] >= stack->pivot_b)
		return (0);
	while (i < stack->b_len)
	{
		if (stack->b[i] >= stack->pivot_b)
		{
			moves = i;
			if (i > stack->b_len / 2)
				moves = (stack->b_len - i) * -1;
			if (final_moves == 0)
				final_moves = moves;
			if (abs(moves) < abs(final_moves))
				final_moves = moves;
		}
		i++;
	}
	return (final_moves);
}
