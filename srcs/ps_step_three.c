/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_step_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrivel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:58:54 by tgrivel           #+#    #+#             */
/*   Updated: 2022/03/29 14:04:13 by tgrivel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pushswap.h"

static int
	sort_stack(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->len - 1)
	{
		if (a->ptr[i] + 1 != a->ptr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static void
	step_tree(t_stack *a, t_stack *b, int shunk[4])
{
	int	mid;

	mid = shunk[0] / 8;
	while (sort_stack(a) == 0)
	{
		ps_push(a, b);
		if (b->ptr[0] < mid)
			ps_rotate(b);
	}
	while (b->ptr[-b->len + 1] < mid)
		ps_reverse(b);
}

void
	step_three_init(t_stack *a, t_stack *b, int shunk[SHUNKS_NUMBER][4])
{
	int	i;

	i = 0;
	while (shunk[i][0])
		step_tree(a, b, shunk[i++]);
}
