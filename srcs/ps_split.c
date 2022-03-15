/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melogr@phy <melogr@phy.to>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:52:19 by melogr@phy        #+#    #+#             */
/*   Updated: 2022/03/15 13:19:06 by melogr@phy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pushswap.h"

//	check blank char
//	tab, new line, space
static int
	blank_char(char c)
{
	if (c == ' '
		|| c == '\t'
		|| c == '\n')
		return (1);
	return (0);
}

//	duplicate a string
static char
	*strcopy(char *str, int *i)
{
	char	*r;
	int		len;

	len = 0;
	while (!blank_char(str[len]) && str[len] != 0)
		len++;
	r = (char *)malloc(len + 1);
	if (r == 0)
		return (0);
	r[len] = 0;
	*i = *i + len;
	while (len--)
		r[len] = str[len];
	return (r);
}

//	number arguments
//	between blank chars
static int
	count_line(char *str)
{
	int	i;
	int	line;

	i = 0;
	line = 0;
	if (!str)
		ps_error("push_swap: Error: no string\n", "");
	while (str[i])
	{
		while (blank_char(str[i]))
			i++;
		if (!blank_char(str[i]) && str[i] != 0)
			line++;
		while (!blank_char(str[i]) && str[i] != 0)
			i++;
	}
	if (line == 0)
		ps_error("push_swap: bad usage: blank chars\n", "");
	return (line);
}

//	split the string by blank characters
//	give the arguments number in argc
char
	**ps_split(char *str, int *argc)
{
	char	**r;
	int		line;
	int		i;
	int		j;

	*argc = count_line(str) + 1;
	r = (char **)malloc(sizeof(char *) * *argc);
	if (r == 0)
		ps_error("push_swap: Error: malloc slit\n", "");
	r[*argc - 1] = 0;
	i = 0;
	j = 0;
	line = *argc - 1;
	while (line--)
	{
		while (blank_char(str[i]) && str[i])
			i++;
		r[j] = strcopy(&str[i], &i);
		if (r[j++] == 0)
			ps_error("push_swap: Error: string copy\n", "t", r);
		i++;
	}
	return (r);
}
