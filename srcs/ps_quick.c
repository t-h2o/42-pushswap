/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_quick.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrivel <tggrivel@student.42lausanne.ch>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:09:45 by tgrivel           #+#    #+#             */
/*   Updated: 2022/03/30 16:04:45 by tgrivel          ###   ########.fr       */
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

static void
	sorttt(t_stack *a, t_stack *b)
{
	int	count;
	int	max;
	int	min;
	int	mid;

	min = MAXINT;
	max = MININT;

	count = 0;
	while (s_sort(a, count))
	{
		if (a->ptr[count] > max)
			max = a->ptr[count];
		if (a->ptr[count] < min)
			min = a->ptr[count];
		count++;
	}

	mid = ((max - min) / 2) + min;

	while (count--)
	{
		ps_push(a, b);
		if (b->ptr[0] > mid)
			ps_rotate(b);
	}
	while (b->ptr[-b->len + 1] != 0)
		ps_reverse(b);

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
	ps_quick(t_stack *a, t_stack *b)
{
	int	i;
	int	mid;
	int	sub;

	i = a->len;
	midnum(a, &mid, &sub);
	while (i--)
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

	while (a->len != 3)
		push_ab(a, b);
	sort_three(a);

	while (s_sort(b, 0))
		push_ba(a, b);
	ps_push(b, a);

	sorttt(a,b);


	while (a->ptr[0] + 1 == a->ptr[1] || a->ptr[1] + 1 == a->ptr[0])
	{
		if (a->ptr[0] - 1 == a->ptr[1])
			ps_swap(a);
		ps_push(a, b);
	}
}
