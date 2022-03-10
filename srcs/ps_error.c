/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melogr@phy <melogr@phy.to>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:18:39 by melogr@phy        #+#    #+#             */
/*   Updated: 2022/03/10 22:51:51 by melogr@phy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pushswap.h"
#include	<stdarg.h>
#include	<unistd.h>

//	free a tab
void
	ps_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

//	print on the standard error
static void
	print_errmsg(char *str)
{
	while (*str)
	{
		write(2, str, 1);
		str++;
	}
}

//	print on the standard error msg
//	follow the free instruction (inst)
//	... are pointers to free
void
	ps_error(char *msg, char *inst, ...)
{
	va_list	ls;

	va_start(ls, inst);
	while (*inst)
	{
		if (*inst == 'f')
			free(va_arg(ls, char *));
		if (*inst == 't')
			ps_free_tab((char **)va_arg(ls, char *));
		inst++;
	}
	va_end(ls);
	print_errmsg(msg);
	exit (0);
}
