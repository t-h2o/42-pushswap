/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrivel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 18:41:36 by tgrivel           #+#    #+#             */
/*   Updated: 2022/04/01 19:35:48 by tgrivel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pushswap.h"

static void
	get_num(t_stack *s, int *min, int *pos, int n)
{
	int	i;

	i = s->len;
	*min = MAXINT;
	while (i--)
	{
		if (s->ptr[i] == n)
		{
			*min = s->ptr[i];
			*pos = i;
			return ;
		}
	}
	*pos = -1;
}

static void
	get_min(t_stack *s, int *min, int *pos)
{
	int	i;

	i = s->len;
	*min = MAXINT;
	while (i--)
	{
		if (s->ptr[i] < *min)
		{
			*min = s->ptr[i];
			*pos = i;
		}
	}
}

static void
	finish_five(t_stack *a)
{
	int	min;
	int	pos;

	get_min(a, &min, &pos);
	while (a->ptr[0] != min)
	{
		if (pos > 2)
			ps_reverse(a);
		else
			ps_rotate(a);
	}
}

static void
	b_a_5(t_stack *a, t_stack *b)
{
	int	min;
	int	pos;

	get_num(a, &min, &pos, (b->ptr[0] + 1) % 5);
	if (pos == -1)
	{
		ps_swap(b, 0);
		get_num(a, &min, &pos, (b->ptr[0] + 1) % 5);
	}
	while ((b->ptr[0] + 1) % 5 != a->ptr[0])
	{
		if (pos > 2)
			ps_reverse(a);
		else
			ps_rotate(a);
	}
	ps_push(b, a);
}

//	push the two first number of A in B
//	sort the three number in A
//	pusb B in A
void
	sort_five(t_stack *a, t_stack *b)
{
	int	i;

	ps_push(a, b);
	ps_push(a, b);
	sort_three(a);
	i = 2;
	while (i--)
		b_a_5(a, b);
	finish_five(a);
}
