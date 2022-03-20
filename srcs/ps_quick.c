/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_quick.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrivel <tggrivel@student.42lausanne.ch>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:09:45 by tgrivel           #+#    #+#             */
/*   Updated: 2022/03/20 20:58:01 by tgrivel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pushswap.h"
#define SHUNKS_NUMBER 10

static void
	midnum(t_stack *s, int shunk[SHUNKS_NUMBER][3], int n)
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
	shunk[n][0] = max - min;
	shunk[n][1] = ((max - min) / 2) + min;
	shunk[n][2] = ((max - min) / 4) + min;
}

static void
	step_one(t_stack *a, t_stack *b, int shunk[SHUNKS_NUMBER][3])
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

static void
	midup(t_stack *s, int *mid, int *submid, int n)
{
	int	min;
	int	max;
	int	i;

	i = s->len;
	max = MININT;
	min = MAXINT;
	while (i--)
	{
		if (min > s->ptr[-i])
			min = s->ptr[-i];
		if (max < s->ptr[-i])
			max = s->ptr[-i];
	}
	*mid = max - ((max - min) / n);
	*submid = max - ((max - min) / (n * 2));
}

static int
	comp_sta(t_stack *s, int num)
{
	int	i;

	i = s->len;
	while (i--)
	{
		if (s->ptr[i * s->dir] > num)
			return (1);
	}
	return (0);
}

static void
	step_two(t_stack *a, t_stack *b, int n)
{
	int	mid;
	int	submid;

	midup(b, &mid, &submid, n);
	while (comp_sta(b, mid))
	{
		if (b->len == 1)
			return ;
		if (b->ptr[0] > mid)
		{
			ps_push(b, a);
			if (a->ptr[0] < submid)
				ps_rotate(a);
		}
		else
			ps_rotate(b);
	}
	midup(b, &mid, &submid, n / 2);
	while (b->ptr[-b->len] > mid)
		ps_reverse(b);
	if (n == 32)
		step_two(a, b, n / 2);
	if (n == 16)
		step_two(a, b, n / 2);
	if (n == 8)
		step_two(a, b, n / 2);
	if (n == 4)
		step_two(a, b, n / 2);
}

static void
	display_shunk(int shunk[SHUNKS_NUMBER][3])
{
	int	i;

	printf("SIZE:");
	i = 0;
	while (i < SHUNKS_NUMBER)
		printf("\t%d", shunk[i++][0]);
	printf("\n");
	printf("MIDD:");
	i = 0;
	while (i < SHUNKS_NUMBER)
		printf("\t%d", shunk[i++][1]);
	printf("\n");
	printf("SUB:");
	i = 0;
	while (i < SHUNKS_NUMBER)
		printf("\t%d", shunk[i++][2]);
	printf("\n");
}

//	put the half little number in B
//						shunk tab
//	            Size:	100		50	...
//	   middle number:	 50		75	...
//	submiddle number:	 75		83	...
void
	ps_quick(t_stack *a, t_stack *b)
{
	int	i;
	int	j;
	int	shunk[SHUNKS_NUMBER][3];

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < SHUNKS_NUMBER)
			shunk[j++][i] = 0;
		i++;
	}
	display_shunk(shunk);
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
	display_shunk(shunk);
	if (a->len != 3)
		ps_error("test: not A3\n", "");
	sort_three(a);
	step_two(a, b, 32);
}
