/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melogr@phy <melogr@phy.to>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 22:43:27 by melogr@phy        #+#    #+#             */
/*   Updated: 2022/04/01 20:03:15 by tgrivel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pushswap.h"

//	change	11	30	22
//	to		1	3	2
static void
	change_number(int *num, int len)
{
	int	new;
	int	j;
	int	i;
	int	pos;

	new = MININT;
	j = 0;
	while (j < len)
	{
		i = 0;
		pos = 0;
		while (num[pos] < new)
			pos++;
		while (i < len)
		{
			if (num[i] < num[pos] && num[i] + 1 > new)
				pos = i;
			i++;
		}
		num[pos] = new++;
		j++;
	}
	j = 0;
	while (j < len)
		num[j++] += 2147483648;
}

//	return 0 if there is not same number
static int
	check_same(int *num, int len)
{
	int	i;

	while (len--)
	{
		i = len;
		while (i--)
			if (num[i] == num[len])
				return (1);
	}
	return (0);
}

//	init stack A & B
//	put the argument in an integer array
//	A -> pointer on the top of the array
static void
	init_stack(t_stack *a, t_stack *b, int *argc, char **argv)
{
	char	**tab;

	a->dir = 1;
	b->dir = -1;
	b->len = 0;
	b->ptr = 0;
	if (*argc == 2)
	{
		tab = ps_split(argv[1], argc);
		ps_argv_to_array(*argc, tab, a);
		ps_free_tab(tab);
	}
	else
		ps_argv_to_array(*argc, &(argv[1]), a);
}

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

//	push_swap
int
	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		*num;

	if (argc == 1)
	{
		printf("push_swap: usage: put number\n");
		return (0);
	}
	init_stack(&a, &b, &argc, argv);
	num = a.ptr;
	if (check_same(num, a.len))
		ps_error("push_swap: usage: same number\n", "f", num);
	change_number(num, a.len);
	if (sort_stack(&a))
		ps_error("push_swap: usage: good order\n", "f", num);
	ps_sort(&a, &b);
	free(num);
}
