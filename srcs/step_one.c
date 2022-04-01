/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrivel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:21:29 by tgrivel           #+#    #+#             */
/*   Updated: 2022/04/01 19:40:56 by tgrivel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pushswap.h"

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

static void
	a_b_1(t_stack *a, t_stack *b, int mid, int sub)
{
	int	i;

	i = a->len;
	while (i-- && a->len > 3)
	{
		if (a->ptr[0] < mid)
		{
			ps_push(a, b);
			if (b->ptr[0] < sub)
				ps_rotate(b);
		}
		else
			ps_rotate(a);
	}
}

static void
	a_b(t_stack *a, t_stack *b, int mid, int sub)
{
	int	i;

	i = a->len;
	while (i-- && a->len > 3)
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
}

void
	step_one(t_stack *a, t_stack *b)
{
	int	mid;
	int	sub;

	midnum(a, &mid, &sub);
	a_b_1(a, b, mid, sub);
	while (a->len > 3)
	{
		midnum(a, &mid, &sub);
		a_b(a, b, mid, sub);
	}
}
