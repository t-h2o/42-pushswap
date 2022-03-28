/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_step_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrivel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:57:53 by tgrivel           #+#    #+#             */
/*   Updated: 2022/03/28 19:13:23 by tgrivel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pushswap.h"

int
	comp_sta(t_stack *s, int num)
{
	int	i;

	i = 0;
	while (i < s->len)
	{
		if (s->ptr[i * s->dir] >= num)
			return (1);
		i++;
	}
	return (0);
}

static void
	step_two(t_stack *a, t_stack *b, int shunk[3])
{
	int	max;
	int	mid;

	max = get_max(b);
	mid = ((max - shunk[3]) / 2) + shunk[3];
	if (max < shunk[1] - ((shunk[0] - shunk[0] % 2) / 2))
		return ;
	while (comp_sta(b, shunk[3]))
	{
		ps_push(b, a);
		if (a->ptr[0] < mid)
			ps_rotate(a);
	}
	max = get_max(a);
	while (a->ptr[a->len - 1] < max)
	{
		ps_reverse(a);
	}
}

void
	step_two_init(t_stack *a, t_stack *b, int shunk[SHUNKS_NUMBER][4])
{
	int	i;

	while (b->ptr[0] + 1 == a->ptr[0] || b->ptr[-1] + 1 == a->ptr[0])
	{
		if (b->ptr[0] < b->ptr[-1])
			ps_swap(b);
		ps_push(b, a);
	}
	i = 0;
	while (shunk[i][0])
		i++;
	while (i--)
		step_two(a, b, shunk[i]);
}
