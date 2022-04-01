/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_quick.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrivel <tggrivel@student.42lausanne.ch>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:09:45 by tgrivel           #+#    #+#             */
/*   Updated: 2022/04/01 18:23:07 by tgrivel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pushswap.h"

static void
	push_next(t_stack *s, int n)
{
	int	i;

	i = 0;
	if (s->ptr == 0)
		return ;
	while (i < s->len)
	{
		if (s->ptr[i * s->dir] == n)
			break ;
		i++;
	}
	if (i < s->len / 2)
		while (s->ptr[0] != n)
			ps_rotate(s);
	if (i >= s->len / 2)
		while (s->ptr[0] != n)
			ps_reverse(s);
}

void
	ps_quick(t_stack *a, t_stack *b)
{
	step_one(a, b);
	sort_three(a);
	while (b->len > 1)
	{
		push_next(b, a->ptr[0] - 1);
		ps_push(b, a);
	}
	ps_push(b, a);
}
