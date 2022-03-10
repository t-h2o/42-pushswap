/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melogr@phy <melogr@phy.to>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 23:23:17 by melogr@phy        #+#    #+#             */
/*   Updated: 2022/03/10 14:31:07 by melogr@phy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSHSWAP_H
# define PUSHSWAP_H

//	include
# include	<stdio.h>
# include	<stdlib.h>

/*		ptr:
 *	pointer on a place of the int array
 *		len:
 *	length of the stack
 */
typedef struct s_stack	t_stack;
struct s_stack {
	int	*ptr;
	int	len;
};

//	ps_print.c
void	print_stack(t_stack a, t_stack b);

//	ps_array.c
void	argv_to_array(int argc, char **argv, t_stack *a);

//	ps_function.c
void	push(t_stack *src, t_stack *dst);
void	swap(t_stack *stack);
void	rotate(t_stack *stack);
void	reverse(t_stack *stack);

#endif /* PUSHSWAP_H */
