/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_quick.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrivel <tggrivel@student.42lausanne.ch>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:09:45 by tgrivel           #+#    #+#             */
/*   Updated: 2022/03/24 12:48:23 by tgrivel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pushswap.h"
#define SHUNKS_NUMBER 10

static void
	midnum(t_stack *s, int shunk[SHUNKS_NUMBER][4], int n)
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
	shunk[n][3] = min;
}

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


static int
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

static int
	get_max(t_stack *s)
{
	int	max;
	int	i;
	
	max = MININT;
	i = 0;
	while (i < s->len)
	{
		if (s->ptr[i * s->dir] > max)
			max = s->ptr[i * s->dir];
		i++;
	}
	return (max);
}

static void
	step_two(t_stack *a, t_stack *b, int shunk[3])
{
	int	max;
	int	mid;
	
	max = get_max(b);
	mid = ((max - shunk[3]) / 2) + shunk[3];
	if (max < shunk[1] - ((shunk[0] - shunk[0] % 2) / 2))
		return;
	
	printf("max %d/%d\tshunk : %d\t%d\t%d\t%d\n",
			max, mid, shunk[0], shunk[1], shunk[2], shunk[3]);


	while (comp_sta(b, shunk[3]))
	{
		ps_push(b, a);
		if (a->ptr[0] < mid)
			ps_rotate(a);
	}
	while (a->ptr[a->len - 1] > shunk[3] && a->ptr[a->len - 1] < mid)
	{
		ps_reverse(a);
	}

	return;

}

static void
	display_shunk(int shunk[SHUNKS_NUMBER][4])
{
	int	i;

	printf("\nSIZE:");
	i = 0;
	while (i < SHUNKS_NUMBER)
		printf("\t%d", shunk[i++][0]);
	printf("\nMIDD:");
	i = 0;
	while (i < SHUNKS_NUMBER)
		printf("\t%d", shunk[i++][1]);
	printf("\nSUB:");
	i = 0;
	while (i < SHUNKS_NUMBER)
		printf("\t%d", shunk[i++][2]);
	printf("\nMIN:");
	i = 0;
	while (i < SHUNKS_NUMBER)
		printf("\t%d", shunk[i++][3]);
	printf("\n\n");
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
	int	shunk[SHUNKS_NUMBER][4];

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < SHUNKS_NUMBER)
			shunk[j++][i] = 0;
		i++;
	}
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

	while (b->ptr[0] + 1 == a->ptr[0] || b->ptr[-1] + 1 == a->ptr[0])
	{
		if (b->ptr[0] < b->ptr[-1])
			ps_swap(b);
		ps_push(b, a);
	}
	
//	print_stack(*a, *b);

	i = 0;
	while (shunk[i][0])
		i++;
	while (i--)
		step_two(a, b, shunk[i]);
}
