/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melogr@phy <melogr@phy.to>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 23:23:17 by melogr@phy        #+#    #+#             */
/*   Updated: 2022/04/01 18:45:15 by tgrivel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSHSWAP_H
# define PUSHSWAP_H

//	include
# include	<stdio.h>
# include	<stdlib.h>
# include	<unistd.h>

//	define
# define MAXINT 0x7fffffff
# define MININT 0x80000000
# define NU 10

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
char	**ps_split(char *str, int *argc);

//	ps_function.c
void	ps_push(t_stack *src, t_stack *dst);
void	ps_swap(t_stack *a, t_stack *b);
void	ps_rotate(t_stack *stack);
void	ps_reverse(t_stack *stack);

//	ps_error.c
void	ps_error(char *msg, char *inst, ...);
void	ps_free_tab(char **tab);

//	ps_scan.c
void	ps_scan(t_stack *a, t_stack *b);

//	sort_tree.c
void	ps_sort(t_stack *a, t_stack *b);
int		ps_check(t_stack *a, t_stack *b);
void	sort_three(t_stack *s);

//	sort_five.c
void	sort_five(t_stack *a, t_stack *b);

//	ps_quick.c
void	ps_quick(t_stack *a, t_stack *b);
int		s_sort(t_stack *s, int n);

//	step_one.c
void	step_one(t_stack *a, t_stack *b);

#endif /* PUSHSWAP_H */
