/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fer <fer@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:29:58 by feaguila          #+#    #+#             */
/*   Updated: 2023/12/21 11:13:47 by fer              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*mfill(int len, int n, int i, int signo)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	i = len--;
	if (signo == -1)
		str[0] = '-';
	while (n != 0)
	{
		str[len--] = n % 10 * signo + '0';
		n = n / 10;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	int		signo;
	int		i;
	int		len;
	char	*str;

	if (n > INT_MAX || n < INT_MIN)
		return (NULL);
	signo = 1;
	i = n;
	len = 0;
	if (n == 0)
		len = 1;
	if (n < 0)
	{
		signo = -1;
		len++;
	}
	while (i != 0)
	{
		i = i / 10;
		len++;
	}
	str = mfill(len, n, i, signo);
	return (str);
}
/* Transforma un INT a CHAR */
/*
// int	main(int argc, char **argv)
// {
// 	char	*mem;
// 	int		i;

// 	if (argc != 2)
// 		return (0);
// 	mem = ft_itoa(atoi(argv[1]));
// 	printf("ITOA => %s\n", mem);
// 	printf("strlen de itoa => %zu\n", strlen(mem));
// 	while (mem[i] != '\0')
// 	{
// 		write (1, &mem[i], 1);
// 		write (1, "\n", 1);
// 		i++;
// 	}
// 	free(mem);
// 	return (0);
// }
*/
