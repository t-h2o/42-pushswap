/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_quick.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrivel <tggrivel@student.42lausanne.ch>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:09:45 by tgrivel           #+#    #+#             */
/*   Updated: 2022/03/30 17:45:30 by tgrivel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pushswap.h"

int
	s_sort(t_stack *s, int n)
{
	int	i;

	if (n < 0 || s->len < n)
		return (0);
	if (s->len < 2)
		return (0);
	i = n;
	while (i < s->len - 1)
	{
		if (s->ptr[i * s->dir] != s->ptr[(i + 1) * s->dir] - s->dir)
			return (1);
		i++;
	}
	return (0);
}

void
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
	ps_quick(t_stack *a, t_stack *b)
{
	step_one(a, b);
	while (a->ptr[0] - 1 == b->ptr[0] || a->ptr[0] - 1 == b->ptr[-1])
	{
		if (b->ptr[0] < b->ptr[-1])
			ps_swap(0, b);
		ps_push(b, a);
	}
	while (b->ptr)
	{
		ps_push(b, a);
	}
}
