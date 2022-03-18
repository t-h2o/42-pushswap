/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_quick.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrivel <tggrivel@student.42lausanne.ch>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:09:45 by tgrivel           #+#    #+#             */
/*   Updated: 2022/03/19 00:30:12 by tgrivel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pushswap.h"

static void
	midnum(t_stack *s, int *mid, int *submid)
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
	*submid = ((max - min) / 4) + min;
}

static void
	step_one(t_stack *a, t_stack *b)
{
	int	i;
	int	mid;
	int	submid;

	i = a->len;
	midnum(a, &mid, &submid);
	while (i--)
	{
		if (a->len == 1)
			return ;
		if (a->ptr[0] < mid)
		{
			ps_push(a, b);
			if (b->ptr[0] > submid)
				ps_rotate(b);
		}
		else
			ps_rotate(a);
	}
	while (b->ptr[-b->len + 1] > submid)
		ps_reverse(b);
	if (a->len > 3)
		step_one(a, b);
}


static void
	midup(t_stack *s, int *mid, int *submid, int n)
{
	int	min;
	int	max;
	int	i;

	i = s->len;
	max = MININT;
	min = MAXINT;
	while (i--)
	{
		if (min > s->ptr[-i])
			min = s->ptr[-i];
		if (max < s->ptr[-i])
			max = s->ptr[-i];
	}
	*mid = max - ((max - min) / n);
	*submid = max - ((max - min) / (n * 2));
}

static void
	step_two(t_stack *a, t_stack *b, int n)
{
	int	i;
	int	mid;
	int	submid;

	i = b->len;
	midup(b, &mid, &submid, n);
	while (i--)
	{
		if (b->len == 1)
			return ;
		if (b->ptr[0] > mid)
		{
			ps_push(b, a);
			if (a->ptr[0] < submid)
				ps_rotate(a);
		}
		else
			ps_reverse(b);
	}
	if (n == 32)
		step_two(a, b, n / 2);
	if (n == 16)
		step_two(a, b, n / 2);
	if (n == 8)
		step_two(a, b, n / 2);
	if (n == 4)
		step_two(a, b, n / 2);
}

//	put the half little number in B
void
	ps_quick(t_stack *a, t_stack *b)
{
	int	i;
	int	mid;
	int	submid;

	i = a->len;
	midnum(a, &mid, &submid);
	while (i--)
	{
		if (a->ptr[0] < mid)
		{
			ps_push(a, b);
			if (b->ptr[0] < submid)
				ps_rotate(b);
		}
		else
			ps_rotate(a);
	}
	step_one(a, b);
	if (a->len != 3)
		ps_error("test: not A3\n", "");
	sort_three(a);
	step_two(a, b, 32);
}
