/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrivel <tggrivel@student.42lausanne.ch>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:43:15 by tgrivel           #+#    #+#             */
/*   Updated: 2022/03/18 19:21:41 by tgrivel          ###   ########.fr       */
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

//	push the two first number of A in B
//	sort the three number in A
//	pusb B in A
static void
	sort_five(t_stack *a, t_stack *b)
{
	int	i;
	int	j;
	int	min;
	int	pos;

	ps_push(a, b);
	ps_push(a, b);
	sort_three(a);
	i = 2;
	j = 0;
	while (i--)
	{
		get_num(a, &min, &pos, (b->ptr[0] + 1) % 5);
		if (pos == -1)
		{
			ps_swap(b);
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
	get_min(a, &min, &pos);
	while (a->ptr[0] != min)
	{
		if (pos > 2)
			ps_reverse(a);
		else
			ps_rotate(a);
	}
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
