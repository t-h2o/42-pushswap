/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melogr@phy <melogr@phy.to>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 22:43:27 by melogr@phy        #+#    #+#             */
/*   Updated: 2022/03/10 00:12:12 by melogr@phy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pushswap.h"

//	push swap
int
	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc == 1)
	{
		printf("push swap: usage: put number\n");
		return (0);
	}

	b.len = 0;
	b.ptr = 0;
	argv_to_array(argc, argv, &a);
	print_stack(a, b);
}
