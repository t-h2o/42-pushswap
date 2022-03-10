/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_function.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melogr@phy <melogr@phy.to>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 12:37:35 by melogr@phy        #+#    #+#             */
/*   Updated: 2022/03/10 14:30:32 by melogr@phy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pushswap.h"

//	move the 1st number of source
//	on the top of destination
void
	push(t_stack *src, t_stack *dst)
{
	if (src->ptr == 0)
		return ;
	if (dst->ptr == 0)
		dst->ptr = src->ptr;
	dst->len++;
	src->ptr++;
	src->len--;
	if (src->len == 0)
		src->ptr = 0;
}

//	swap the two 1st number
void
	swap(t_stack *stack)
{
	int	tmp;

	if (stack->len < 2)
		return ;
	tmp = *stack->ptr;
	*stack->ptr = (stack->ptr)[1];
	(stack->ptr[1]) = tmp;
}

//	move the 1st number at the bottom
void
	rotate(t_stack *stack)
{
	int	i;
	int	top;

	if (stack->len < 2)
		return ;
	i = -1;
	top = stack->ptr[0];
	while (++i < stack->len)
	{
		stack->ptr[i] = stack->ptr[i + 1];
	}
	stack->ptr[--i] = top;
}

//	move the last number on the top
void
	reverse(t_stack *stack)
{
	int	i;
	int	bot;

	if (stack->len < 2)
		return ;
	i = stack->len;
	bot = stack->ptr[i - 1];
	while (--i)
	{
		stack->ptr[i] = stack->ptr[i - 1];
	}
	stack->ptr[0] = bot;
}
