/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feaguila <feaguila@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:20:44 by feaguila          #+#    #+#             */
/*   Updated: 2023/12/01 08:32:20 by feaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	pos;
	size_t	len_s1;

	i = 0;
	pos = 0;
	if (!s1 || !set)
		return (NULL);
	len_s1 = ft_strlen(s1);
	if (s1[i] == '\0')
		return (ft_calloc(1, 1));
	while (ft_strchr(set, s1[i]) && s1[i] != '\0')
		i++;
	while (ft_strrchr(set, s1[len_s1 - 1]) && len_s1 > i)
		len_s1--;
	str = (char *)malloc(sizeof(char) * ((len_s1 - i) + 1));
	if (!str)
		return (NULL);
	while (i < len_s1)
		str[pos++] = s1[i++];
	str[pos] = '\0';
	return (str);
}
/*Corta por delante y por detras segun SET y crea un nuevo STR*/
/*
// int	main(int argc, char **argv)
// {
// 	char	*str;

// 	if (argc != 3)
// 		return (0);
// 	str = ft_strtrim(argv[1], argv[2]);
// 	printf("STRTRIM: %s\n", str);
// 	free(str);
// 	return (0);
// }
*/
