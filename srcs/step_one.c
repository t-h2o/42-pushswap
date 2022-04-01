/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrivel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:21:29 by tgrivel           #+#    #+#             */
/*   Updated: 2022/04/01 15:45:20 by tgrivel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pushswap.h"

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
	while (b->ptr[-b->len + 1] > sub)
		ps_reverse(b);
}

static int
	sta_com(t_stack *s, int n)
{
	int	i;

	i = 0;
	if (s->ptr == 0)
		return (0);
	while (i < s->len)
	{
		if (s->ptr[i * s->dir] > n)
			return (1);
		i++;
	}
	return (0);
}

static int
	get_max(t_stack *s)
{
	int	i;
	int	max;

	i = 0;
	max = MININT;
	if (s->ptr == 0)
		return (0);;
	while (i < s->len)
	{
		if (s->ptr[i * s->dir] > max)
			max = s->ptr[i * s->dir];
		i++;
	}
	return (max);
}

static void
	b_a(t_stack *a, t_stack *b, int mid, int sub)
{

	int max = get_max(a);

	printf("INFO\t%d\t%d\n", mid, sub);
	
	while (b->ptr &&
		(a->ptr[0] - 1 == b->ptr[0] || a->ptr[0] - 1 == b->ptr[-1]))
	{
		if (b->ptr[0] < b->ptr[-1])
			ps_swap(0, b);
		ps_push(b, a);
	
	if (b->ptr == 0)
		return ;
	}
	while (sta_com(b, mid))
	{
		ps_push(b, a);
		while (a->ptr[0] + 1 != a->ptr[1])
		{
			ps_rotate(a);
			ps_push(b, a);
		}
		while (a->ptr[a->len - 1] < max)
		{
			ps_reverse(a);
			if (a->ptr[0] - 1 != a->ptr[1])
				ps_push(a, b);
		}
	}
}

void
	step_one(t_stack *a, t_stack *b)
{
	int mid;
	int sub;

	if (a->len == 3)
	{
		sort_three(a);
		return ;
	}
	midnum(a, &mid, &sub);
	a_b(a, b, mid, sub);
	step_one(a, b);
	b_a(a, b, mid, sub);
	b_a(a, b, 0, sub);
}
