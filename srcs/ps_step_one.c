/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_step_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrivel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 17:38:53 by tgrivel           #+#    #+#             */
/*   Updated: 2022/03/28 19:16:19 by tgrivel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pushswap.h"

static void
	step_one(t_stack *a, t_stack *b, int shunk[SHUNKS_NUMBER][4])
{
	int	i;
	int	s;

	s = 0;
	while (shunk[s][0])
		s++;
	midnum(a, shunk, s);
	i = a->len;
	while (i--)
	{
		if (a->len == 1)
			return ;
		if (a->ptr[0] < shunk[s][1])
		{
			ps_push(a, b);
			if (b->ptr[0] > shunk[s][2])
				ps_rotate(b);
		}
		else
			ps_rotate(a);
	}
	while (b->ptr[-b->len + 1] > shunk[s][2])
		ps_reverse(b);
	if (a->len > 3)
		step_one(a, b, shunk);
}

void
	step_one_init(t_stack *a, t_stack *b, int shunk[SHUNKS_NUMBER][4])
{
	int	i;

	i = a->len;
	midnum(a, shunk, 0);
	while (i--)
	{
		if (a->ptr[0] < shunk[0][1])
		{
			ps_push(a, b);
			if (b->ptr[0] < shunk[0][2])
				ps_rotate(b);
		}
		else
			ps_rotate(a);
	}
	step_one(a, b, shunk);
	if (a->len != 3)
		ps_error("test: not A3\n", "");
	sort_three(a);
}
