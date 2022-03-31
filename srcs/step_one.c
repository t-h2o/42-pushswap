/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrivel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:21:29 by tgrivel           #+#    #+#             */
/*   Updated: 2022/03/31 16:00:28 by tgrivel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pushswap.h"

static void
	push_ab_1(t_stack *a, t_stack *b, int *mid)
{
	int	i;
	int	sub;

	midnum(a, mid, &sub);
	i = a->len;
	while (i-- && a->len > 3)
	{
		if (a->ptr[0] < *mid)
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

void
	step_one(t_stack *a, t_stack *b, int part[NU])
{
	int	i;
	int	sub;

	midnum(a, &(part[0]), &sub);
	i = a->len;
	while (i--)
	{
		if (a->ptr[0] < part[0])
		{
			ps_push(a, b);
			if (b->ptr[0] < sub)
				ps_rotate(b);
			else if (a->ptr[0] > a->ptr[1] && b->ptr[0] < b->ptr[-1])
				ps_swap(a, b);

		}
		else
			ps_rotate(a);
	}
	i = 1;
	while (a->len != 3)
		push_ab_1(a, b, &(part[i++]));
	sort_three(a);
}
