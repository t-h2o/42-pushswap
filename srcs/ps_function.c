/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_function.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melogr@phy <melogr@phy.to>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 12:37:35 by melogr@phy        #+#    #+#             */
/*   Updated: 2022/03/14 19:21:41 by tgrivel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pushswap.h"

//	move the 1st number of source
//	on the top of destination
void
	ps_push(t_stack *src, t_stack *dst)
{
	if (src->ptr == 0)
		return ;
	if (dst->ptr == 0)
	{
		dst->ptr = src->ptr;
		src->ptr += src->dir;
	}
	else
	{
		dst->ptr += src->dir;
		src->ptr += src->dir;
	}
	dst->len++;
	src->len--;
	if (src->len == 0)
		src->ptr = 0;
	if (dst->dir == 1)
		write(1, "pa\n", 3);
	else if (dst->dir == -1)
		write(1, "pb\n", 3);
}

//	swap the two 1st number
void
	ps_swap(t_stack *stack)
{
	int	tmp;

	if (stack->len < 2)
		return ;
	tmp = *stack->ptr;
	*stack->ptr = (stack->ptr)[stack->dir];
	(stack->ptr[stack->dir]) = tmp;
	if (stack->dir == 1)
		write(1, "sa\n", 3);
	else if (stack->dir == -1)
		write(1, "sb\n", 3);
}

//	move the 1st number at the bottom
void
	ps_rotate(t_stack *stack)
{
	int	i;
	int	top;
	int	len;

	if (stack->len < 2)
		return ;
	len = stack->len;
	i = 0;
	top = stack->ptr[0];
	while (--len)
	{
		stack->ptr[i] = stack->ptr[i + stack->dir];
		i += stack->dir;
	}
	stack->ptr[i] = top;
	if (stack->dir == 1)
		write(1, "ra\n", 3);
	else if (stack->dir == -1)
		write(1, "rb\n", 3);
}

//	move the last number on the top
void
	ps_reverse(t_stack *stack)
{
	int	i;
	int	bot;
	int	len;

	if (stack->len < 2)
		return ;
	len = stack->len;
	i = (len * stack->dir) - stack->dir;
	bot = stack->ptr[i];
	while (--len)
	{
		stack->ptr[i] = stack->ptr[i - stack->dir];
		i -= stack->dir;
	}
	stack->ptr[i] = bot;
	if (stack->dir == 1)
		write(1, "rra\n", 4);
	else if (stack->dir == -1)
		write(1, "rrb\n", 4);
}
