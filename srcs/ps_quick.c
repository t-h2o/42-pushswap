/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_quick.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrivel <tggrivel@student.42lausanne.ch>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:09:45 by tgrivel           #+#    #+#             */
/*   Updated: 2022/03/28 19:17:02 by tgrivel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pushswap.h"

void
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

int
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

void
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
	step_one_init(a, b, shunk);
	step_two_init(a, b, shunk);
	step_three_init(a, b, shunk);
}
