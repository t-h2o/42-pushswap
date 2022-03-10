/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melogr@phy <melogr@phy.to>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 22:43:27 by melogr@phy        #+#    #+#             */
/*   Updated: 2022/03/10 22:53:57 by melogr@phy       ###   ########.fr       */
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

	new = -2147483648;
	j = 0;
	while (j < len)
	{
		i = 0;
		pos = j;
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
	{
		num[j++] += 2147483648;
	}
}

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
		tab = ps_splitarg(argv[1], argc);
		if (tab == 0 || *argc == 2)
			ps_error("push swap: usage: need more than one number\n", "t", tab);
		ps_argv_to_array(*argc, tab, a);
		ps_free_tab(tab);
	}
	else
		ps_argv_to_array(*argc, &(argv[1]), a);
}

//	push swap
int
	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		*num;

	if (argc == 1)
	{
		printf("push swap: usage: put number\n");
		return (0);
	}
	init_stack(&a, &b, &argc, argv);
	num = a.ptr;
	print_stack(a, b);
	change_number(num, a.len);
	print_stack(a, b);
//	ps_scan(&a, &b);
	free(num);
}
