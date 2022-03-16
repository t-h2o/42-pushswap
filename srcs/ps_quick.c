/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_quick.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrivel <tggrivel@student.42lausanne.ch>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:09:45 by tgrivel           #+#    #+#             */
/*   Updated: 2022/03/16 18:21:17 by tgrivel          ###   ########.fr       */
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
	midup(t_stack *s, int *mid, int *submid)
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
	*mid = max - ((max - min) / 2);
	*submid = max - ((max - min) / 4);
}

static void
	step_one(t_stack *a, t_stack *b)
{
	int	i;
	int	mid;
	int	submid;

	i = a->len;
	midnum(a, &mid, &submid, 2, 4);
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
	if (a->len > 2)
		step_one(a, b);
}

//	put the half little number in B
void
	ps_quick(t_stack *a, t_stack *b)
{
	int	i;
	int	mid;
	int	submid;

	i = a->len;
	midnum(a, &mid, &submid, 2, 4);
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
	step_two(a, b);

}
