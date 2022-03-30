/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ba.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrivel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:24:23 by tgrivel           #+#    #+#             */
/*   Updated: 2022/03/30 12:57:12 by tgrivel          ###   ########.fr       */
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
		if (a->ptr[-i] > n)
			return (1);
		i++;
	}
	return (0);
}

static int
	stack_sort(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->len - 1)
	{
		if (a->ptr[i] != a->ptr[i + 1] - 1)
			return (0);
		i ++;
	}
	return (1);
}

static void
	midnum(t_stack *s, int *maxptr, int *mid, int *sub)
{
	int	min;
	int	max;
	int	i;

	i = s->len;
	max = MININT;
	min = MAXINT;
	while (i--)
	{
		if (min > s->ptr[i * s->dir])
			min = s->ptr[i * s->dir];
		if (max < s->ptr[i * s->dir])
			max = s->ptr[i * s->dir];
	}
	*mid = ((max - min) / 2) + min;
	*sub = ((max - min) / 4) + *mid;
	*maxptr = max;
}

void
	push_ba(t_stack *a, t_stack *b)
{
	int	mid;
	int	sub;
	int	max;

	while (stack_sort(a))
	{
		if (b->ptr[0] < b->ptr[-1])
			ps_swap(b);
		ps_push(b, a);
	}
	midnum(b, &max, &mid, &sub);
	while (comp_stack(b, mid) && s_sort(b, 0))
	{
		if (b->ptr[0] > mid)
		{
			if (b->ptr[0] < b->ptr[-1])
				ps_swap(b);
			ps_push(b, a);
			if (a->ptr[0] < sub)
				ps_rotate(a);
		}
		else
			ps_rotate(b);
	}
	midnum(a, &max, &mid, &sub);
	while (a->ptr[a->len - 1] != max)
		ps_reverse(a);



}
