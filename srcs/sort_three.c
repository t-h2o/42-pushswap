/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrivel <tggrivel@student.42lausanne.ch>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:43:15 by tgrivel           #+#    #+#             */
/*   Updated: 2022/04/02 02:19:08 by melogr@phy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pushswap.h"

//     possible scenarious
//  1     2     3     4     5
// *     **    **    ***   ***
// ***   *     ***   **    *
// **    ***   *     *     **
void
	sort_three(t_stack *s)
{
	if (s->ptr[0] < s->ptr[1]
		&& s->ptr[0] < s->ptr[2] && s->ptr[1] > s->ptr[2])
	{
		ps_reverse(s);
		ps_swap(s, 0);
	}
	else if (s->ptr[0] > s->ptr[1]
		&& s->ptr[0] < s->ptr[2] && s->ptr[1] < s->ptr[2])
		ps_swap(s, 0);
	else if (s->ptr[0] < s->ptr[1]
		&& s->ptr[0] > s->ptr[2] && s->ptr[1] > s->ptr[2])
		ps_reverse(s);
	else if (s->ptr[0] > s->ptr[1]
		&& s->ptr[0] > s->ptr[2] && s->ptr[1] > s->ptr[2])
	{
		ps_rotate(s);
		ps_swap(s, 0);
	}
	else if (s->ptr[0] > s->ptr[1]
		&& s->ptr[0] > s->ptr[2] && s->ptr[1] < s->ptr[2])
		ps_rotate(s);
}

int
	ps_check(t_stack *a, t_stack *b)
{
	int	n;
	int	i;

	if (b->ptr)
		return (1);
	i = 0;
	n = a->ptr[i];
	while (i + 1 < a->len)
	{
		n = a->ptr[i];
		if (n > a->ptr[i + 1])
			return (1);
		i++;
	}
	printf("SORT!\n");
	return (0);
}

void
	ps_sort(t_stack *a, t_stack *b)
{
	if (a->len == 3)
		sort_three(a);
	else if (a->len == 5)
		sort_five(a, b);
	else if (a->len == 2)
		ps_swap(a, 0);
	else
		ps_quick(a, b);
}
