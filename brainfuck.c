/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfuck2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfredric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 17:19:00 by cfredric          #+#    #+#             */
/*   Updated: 2016/10/23 17:19:01 by cfredric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brainfuck.h"

int			main(int argc, char **argv)
{
	if (argc < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	interpret(argv[1]);
	return (0);
}

static void	ft_set0(unsigned char *str)
{
	int		i;

	i = 0;
	while (str[i])
		str[i++] = 0;
}

static char	*open_bracket(char *str)
{
	int		count;

	count = 0;
	while (1)
	{
		if (*str == '[')
			count++;
		else if (*str == ']')
			count--;
		if (count == 0)
			break ;
		str++;
	}
	return (str);
}

static char *closed_bracket(char *str)
{
	int		count;

	count = 0;
	while (1)
	{
		if (*str == ']')
			count++;
		else if (*str == '[')
			count--;
		if (count == 0)
			break ;
		str--;
	}
	return (str);
}

void	interpret(char *str)
{
	unsigned char	*buf;
	unsigned char	*buf_ptr;

	buf = (unsigned char *)malloc(sizeof(unsigned char) * 4096);
	buf_ptr = buf;
	ft_set0(buf);
	while (*str)
	{
		if (*str == '>')
			buf_ptr++;
		else if (*str == '<')
			buf_ptr--;
		else if (*str == '+')
			*buf_ptr += 1;
		else if (*str == '-')
			*buf_ptr -= 1;
		else if (*str == '.')
			write(1, buf_ptr, 1);
		else if (*str == '[' && *buf_ptr == 0)
			str = open_bracket(str);
		else if (*str == ']' && *buf_ptr != 0)
			str = closed_bracket(str);
		str++;
	}
	free(buf);
}
