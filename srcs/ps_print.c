/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melogr@phy <melogr@phy.to>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 23:34:27 by melogr@phy        #+#    #+#             */
/*   Updated: 2022/03/09 23:38:42 by melogr@phy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pushswap.h"

//	display the two stack
void
	print_stack(t_stack a, t_stack b)
{
	int	i;

	i = 0;
	printf("\tA\tB\n");
	while (a.len || b.len)
	{
		i++;
		if (a.len)
		{
			a.len--;
			printf("%.2d |\t%d", i, *a.ptr);
			a.ptr++;
		}
		else
			printf("%.2d |\t", i);
		if (b.len)
		{
			b.len--;
			printf("\t%d\n", *b.ptr);
			b.ptr++;
		}
		else
			printf("\n");
	}
}
