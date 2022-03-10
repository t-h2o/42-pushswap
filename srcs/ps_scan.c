/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_scan.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrivel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 12:13:26 by tgrivel           #+#    #+#             */
/*   Updated: 2022/03/10 17:45:54 by melogr@phy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pushswap.h"

static int
	ps_strcmp(char *s1, char *s2)
{
	while (*s1)
		if (*(s1++) != *(s2++))
			return (0);
	return (1);
}

void
	ps_scan(t_stack *a, t_stack *b)
{
	char	*input;
	int		len;
	int		try;

	len = 5;
	input = (char *)malloc(len);
	try = 0;
	while (len + 1)
		input[len--] = 0;


	while (1)
	{
		int	print = 1;
		try++;
		printf("\n\n%d\t| Give the command : ", try);
		scanf("%s", input);
		printf("\t| ");	
		if (ps_strcmp(input, "q"))
		{
			printf("DONE\n\n");
			break ;
		}
		else if (ps_strcmp(input, "help"))
		{
			printf("help\n");
			/*	Create a help message
			 */
		}
		else
		{
			if (ps_strcmp(input, "ra"))
			{
				printf("rotate A\n");
				ps_rotate(a);
			}
			else if (ps_strcmp(input, "rb"))
			{
				printf("rotate B\n");
				ps_rotate(b);
			}
			else if (ps_strcmp(input, "rr"))
			{
				printf("rotate A & B\n");
				ps_rotate(a);
				ps_rotate(b);
			}
			else if (ps_strcmp(input, "rra"))
			{
				printf("reverse rotate A\n");
				ps_reverse(a);
			}
			else if (ps_strcmp(input, "rrb"))
			{
				printf("reverse rotate B\n");
				ps_reverse(b);
			}
			else if (ps_strcmp(input, "rrr"))
			{
				printf("reverse rotate A & B\n");
				ps_reverse(a);
				ps_reverse(b);
			}
			else if (ps_strcmp(input, "sa"))
			{
				printf("swap A\n");
				ps_swap(a);
			}
			else if (ps_strcmp(input, "sb"))
			{
				printf("swap B\n");
				ps_swap(b);
			}
			else if (ps_strcmp(input, "ss"))
			{
				printf("swap A & B\n");
				ps_swap(a);
				ps_swap(b);
			}
			else if (ps_strcmp(input, "pb"))
			{
				printf("push A on B\n");
				ps_push(a, b);
			}
			else if (ps_strcmp(input, "pa"))
			{
				printf("push B on A\n");
				ps_push(b, a);
			}
			else
			{
				printf("didn't get it :(\n");
				try--;
				print = 0;
			}
			if (print)
			{
				printf("\n");
				print_stack(*a, *b);
			}

		}
	}
	free(input);
}

