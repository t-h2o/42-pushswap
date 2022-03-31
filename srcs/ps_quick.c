/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_quick.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrivel <tggrivel@student.42lausanne.ch>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:09:45 by tgrivel           #+#    #+#             */
/*   Updated: 2022/03/31 15:43:38 by tgrivel          ###   ########.fr       */
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

static int
	stack_comp(t_stack *s, int n)
{
	int	i;

	i = 0;
	while (i < s->len)
	{
		if (s->ptr[i * s->dir] > n)
			return (1);
		i++;
	}
	return (0);
}

void
	ps_quick(t_stack *a, t_stack *b)
{
	int	i;
	int	part[NU];
	int	two[NU];

	i = 0;
	while (i < NU)
	{
		two[i] = 0;
		part[i++] = 0;
	}

	step_one(a, b, part);
	while (a->ptr[0] - 1 == b->ptr[0] || a->ptr[0] - 1 == b->ptr[-1])
	{
		if (b->ptr[0] < b->ptr[-1])
			ps_swap(0, b);
		ps_push(b, a);
	}

	i = 0;
	while (part[i] < b->len)
		printf("-->%d\n", part[i++]);

	int mid;

	mid = (part[i] - part[i - 1]) / 2 + part[i - 1];
	while (stack_comp(b, mid))
		ps_push(b, a);


}
