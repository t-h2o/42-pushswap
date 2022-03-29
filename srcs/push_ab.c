/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrivel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:58:00 by tgrivel           #+#    #+#             */
/*   Updated: 2022/03/29 15:00:12 by tgrivel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pushswap.h"

static int
	comp_stack(t_stack *a, int n)
{
	int	i;

	i = 0;
	while (i < a->len)
	{
		if (a->ptr[i] < n)
			return (1);
		i++;
	}
	return (0);
}

static void
	midnum(t_stack *s, int *mid, int *sub)
{
	int	min;
	int	max;
	int	i;

	i = s->len;
	max = MININT;
	min = MAXINT;
	while (i--)
	{
		if (min > s->ptr[i])
			min = s->ptr[i];
		if (max < s->ptr[i])
			max = s->ptr[i];
	}
	*mid = ((max - min) / 2) + min;
	*sub = ((max - min) / 4) + min;
}

void
	push_ab(t_stack *a, t_stack *b)
{
	int	mid;
	int	sub;

	midnum(a, &mid, &sub);
	while (comp_stack(a, mid))
	{
		if (a->ptr[0] < mid)
		{
			ps_push(a, b);
			if (b->ptr[0] > sub)
				ps_rotate(b);
		}
		else
			ps_rotate(a);

	}
	while (b->ptr[-b->len + 1] > sub)
		ps_reverse(b);
}
