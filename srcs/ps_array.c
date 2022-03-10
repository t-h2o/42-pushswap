/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melogr@phy <melogr@phy.to>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 23:29:55 by melogr@phy        #+#    #+#             */
/*   Updated: 2022/03/10 00:59:08 by melogr@phy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pushswap.h"

/*	if the string is only digit
 *		return 0
 *	else
 *		return -1
 *	put the string valut in n
 */
static int	ps_atoi(char *str, int *n)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (-1);
		i = *str - '0' + i * 10;
		str++;
	}
	*n = i;
	return (0);
}

/*	duplicate a string
 */
static char
	*strcopy(char *str, int start, int end)
{
	char	*r;
	int		len;

	len = end - start + 1;
	r = (char *)malloc(len + 1);
	if (r == 0)
	{
		printf("push swap: error: malloc string\n");
		exit(0);
	}
	r[len] = 0;
	while (len--)
		r[len] = str[start + len];
	return (r);
}

/*	split the string by spaces
 *	give the arguments number in argc
 */
static char
	**splitarg(char *str, int *argc)
{
	char	**r;
	int		line;
	int		start;
	int		i;
	int		j;

	i = -1;
	line = 1;
	while (str[++i])
		if (str[i] == ' ')
			line++;
	*argc = line + 1;
	r = (char **)malloc(sizeof(char *) * line + 1);
	if (r == 0)
		return (0);
	r[line] = 0;
	i = 0;
	j = 0;
	while (line--)
	{
		start = i;
		while (str[i] != ' ' && str[i])
			i++;
		r[j] = strcopy(str, start, i - 1);
		if (r[j++] == 0)
		{
			free(r);
			return (0);
		}
		i++;
	}
	return (r);
}

/*	set stack A with arguments
 *	split argument if one arguments
 */
void
	argv_to_array(int argc, char **argv, t_stack *a)
{
	int	*num;
	int	i;

	if (argc == 2)
		argv = splitarg(argv[1], &argc);
	else
		argv++;
	num = (int *)malloc(sizeof(int) * --argc);
	if (num == 0)
	{
		printf("push swap: error: malloc array\n");
		exit(0);
	}
	i = 0;
	while (argv[i])
	{
		if (ps_atoi(argv[i], &(num[i])))
		{
			free(num);
			printf("push swap: usage: there is not only digit\n");
			exit(0);
		}
		i++;
	}
	a->len = argc;
	a->ptr = num;
}
