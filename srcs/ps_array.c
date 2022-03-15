/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melogr@phy <melogr@phy.to>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 23:29:55 by melogr@phy        #+#    #+#             */
/*   Updated: 2022/03/15 11:55:55 by melogr@phy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pushswap.h"

//	put string(str) value in number(n)
//	if the string is only digit
//		return 0
//	else
//		return -1
//	put the string valut in n
static int	ps_atoi(char *str, int *n)
{
	int	i;
	int	neg;

	i = 0;
	neg = 1;
	if (*str == '-')
	{
		str++;
		neg = -1;
	}
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (-1);
		i = *str - '0' + i * 10;
		str++;
	}
	*n = i * neg;
	return (0);
}

//	set stack A with arguments
void
	ps_argv_to_array(int argc, char **argv, t_stack *a)
{
	int	*num;
	int	i;

	num = (int *)malloc(sizeof(int) * --argc);
	if (num == 0)
		ps_error("push_swap: error: malloc array\n", "");
	i = 0;
	while (argv[i])
	{
		if (ps_atoi(argv[i], &(num[i])))
			ps_error("push_swap: usage: there is not only digit\n", "f", num);
		i++;
	}
	a->len = argc;
	a->ptr = num;
}
