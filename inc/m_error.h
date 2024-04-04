/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_error.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feaguila <feaguila@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:51:22 by feaguila          #+#    #+#             */
/*   Updated: 2024/04/04 11:51:37 by feaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_ERROR_H

# define MINI_ERROR_H

enum	e_mini_error
{
	QUOTE = 1,
	NOTDIR = 2,
	NOTPERM = 3,
	NOTCMD = 6,
	DUPERR = 7,
	FORKERR = 8,
	PIPERR = 9,
	MEM = 10
};

#endif
