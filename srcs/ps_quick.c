/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_quick.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrivel <tggrivel@student.42lausanne.ch>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:09:45 by tgrivel           #+#    #+#             */
/*   Updated: 2022/03/15 20:18:03 by tgrivel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pushswap.h"
/*
static int
	midnum(t_stack *s)
{
	int	min;
	int	max;
	int	mid;
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
	mid = ((max - min) / 2) + min;
	printf("mid --> %d\n", mid);
	return (mid);
}
*/
void
	ps_quick(t_stack *a, t_stack *b)
{
	int	i;

	i = a->len;
	
	i = a->len;
	while (i--)
	{
		if (a->ptr[0] % 8 == 0)
			ps_push(a, b);
		else
			ps_rotate(a);
	}
	while (b->ptr)
		ps_push(b, a);

	while (i--)
	{
		if (a->ptr[0] % 2 == 0)
			ps_push(a, b);
		else
			ps_rotate(a);
	}
	print_stack(*a, *b);
	while (b->ptr)
		ps_push(b, a);
	
	i = a->len;
	while (i--)
	{
		if (a->ptr[0] % 4 == 0)
			ps_push(a, b);
		else
			ps_rotate(a);
	}
	while (b->ptr)
		ps_push(b, a);
}

//	001
//	010
//	011
//	100
//	101
//	110
//	111

//		001
//	010
//		011
//	100
//		101
//	110
//		111

//		001
//	010
//			011
//	100
//		101
//	110
//			111
