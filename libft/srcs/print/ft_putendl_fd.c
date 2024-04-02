/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feaguila <feaguila@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:38:48 by feaguila          #+#    #+#             */
/*   Updated: 2024/01/17 16:07:28 by feaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
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
	write (fd, "\n", 1);
}
/*Escribe un STR + \n en un file descriptor que queramos*/
/*FD{0, 1, 2} {3,.. OPEN/READ FILE}*/
/*
// int	main(int argc, char **argv)
// {
// 	if (argc == 0)
// 		return (0);
// 	ft_putendl_fd(argv[1], 1);
// 	return (0);
// }
*/
