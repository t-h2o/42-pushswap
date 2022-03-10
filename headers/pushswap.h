/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melogr@phy <melogr@phy.to>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 23:23:17 by melogr@phy        #+#    #+#             */
/*   Updated: 2022/03/10 22:57:47 by melogr@phy       ###   ########.fr       */
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
 *		dir:
 *	indicate the direction of the pointer
 */
typedef struct s_stack	t_stack;
struct s_stack {
	int	*ptr;
	int	len;
	int	dir;
};

//	ps_print.c
void	print_stack(t_stack a, t_stack b);

//	ps_array.c
void	ps_argv_to_array(int argc, char **argv, t_stack *a);
char	**ps_splitarg(char *str, int *argc);

//	ps_function.c
void	ps_push(t_stack *src, t_stack *dst);
void	ps_swap(t_stack *stack);
void	ps_rotate(t_stack *stack);
void	ps_reverse(t_stack *stack);

//	ps_error.c
void	ps_error(char *msg, char *inst, ...);
void	ps_free_tab(char **tab);

//	ps_scan.c
void	ps_scan(t_stack *a, t_stack *b);
#endif /* PUSHSWAP_H */
