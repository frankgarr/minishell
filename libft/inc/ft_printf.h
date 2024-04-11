/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feaguila <feaguila@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 09:29:04 by feaguila          #+#    #+#             */
/*   Updated: 2024/04/09 13:29:14 by feaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*-- LIBS --*/
# include <stdarg.h>
# include "libft.h"

/*-- INIT --*/
int		ft_printf(char const *str, ...);
int		ft_fd_printf(int fd, const char *f, ...);

/*-- CHECK --*/
int		ft_checkprint(va_list args, char c);

/*-- PRINT CHARS --*/
int		ft_putchar(char c);
int		ft_putstr(char *str);

/*-- PRINT NUMBERS --*/
int		ft_putnbr(int nb);
int		ft_putnbr_unsigned(unsigned int nb);
int		ft_putnbr_hex(unsigned int nb, char *base);

/*-- PRINT POINTER --*/
int		ft_putptr(unsigned long long ptr);

/*-- TRANSFORM NUMBERS --*/
char	*ft_utoa(unsigned int nb);

#endif
