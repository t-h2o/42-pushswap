/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrivel <tggrivel@student.42lausanne.ch>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:43:15 by tgrivel           #+#    #+#             */
/*   Updated: 2022/03/15 18:39:18 by tgrivel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pushswap.h"

//     possible scenarious
//  1     2     3     4     5
// *     **    **    ***   ***
// ***   *     ***   **    *
// **    ***   *     *     **
static void
	sort_three(t_stack *s)
{
	if (s->ptr[0] < s->ptr[1]
		&& s->ptr[0] < s->ptr[2] && s->ptr[1] > s->ptr[2])
	{
		ps_reverse(s);
		ps_swap(s);
	}
	else if (s->ptr[0] > s->ptr[1]
		&& s->ptr[0] < s->ptr[2] && s->ptr[1] < s->ptr[2])
		ps_swap(s);
	else if (s->ptr[0] < s->ptr[1]
		&& s->ptr[0] > s->ptr[2] && s->ptr[1] > s->ptr[2])
		ps_reverse(s);
	else if (s->ptr[0] > s->ptr[1]
		&& s->ptr[0] > s->ptr[2] && s->ptr[1] > s->ptr[2])
	{
		ps_rotate(s);
		ps_swap(s);
	}
	else if (s->ptr[0] > s->ptr[1]
		&& s->ptr[0] > s->ptr[2] && s->ptr[1] < s->ptr[2])
		ps_rotate(s);
}

//	push the two first number of A in B
//	sort the three number in A
//	pusb B in A
static void
	sort_five(t_stack *a, t_stack *b)
{
	int	i;
	int	j;

	ps_push(a, b);
	ps_push(a, b);
	sort_three(a);
	i = 2;
	j = 0;
	while (i--)
	{
		while ((b->ptr[0] + 1) % 5 != a->ptr[0])
		{
			ps_rotate(a);
			j++;
		}
		print_stack(*a, *b);
		ps_push(b, a);
		if (a->ptr[0] > a->ptr[1])
			ps_swap(a);
	}
	while (j--)
		ps_reverse(a);
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
	if (a->len == 5)
		sort_five(a, b);
	if (a->len > 5)
		ps_quick(a, b);
}
