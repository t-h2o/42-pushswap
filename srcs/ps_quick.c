/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_quick.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrivel <tggrivel@student.42lausanne.ch>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:09:45 by tgrivel           #+#    #+#             */
/*   Updated: 2022/03/29 16:45:37 by tgrivel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pushswap.h"



void
	ps_quick(t_stack *a, t_stack *b)
{
	while (a->len != 3)
		push_ab(a, b);
	sort_three(a);

	while (b->len > 1)
		push_ba(a, b);
	ps_push(b, a);
}
