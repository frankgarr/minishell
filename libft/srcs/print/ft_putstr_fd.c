/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feaguila <feaguila@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:26:54 by feaguila          #+#    #+#             */
/*   Updated: 2024/01/17 16:07:07 by feaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s || fd < 0 || fd > INT_MAX)
		return ;
	while (s[i] != '\0')
	{
		write (fd, &s[i], 1);
		i++;
	}
}
/*Envia un STR a imprimir por FD*/
/*
// int	main(int argc, char **argv)
// {
// 	if (argc == 0)
// 		return (0);
// 	ft_putstr_fd(argv[1], 1);
// 	return (0);
// }
*/
