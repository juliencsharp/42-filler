/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 16:17:04 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/19 13:14:03 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "filler.h"

/*
**	Writes the specified message on the error output and exit
**	the program.
*/

void	error(char *msg)
{
	ft_putstr_fd("JuJu: ", ERROR_FD);
	ft_putstr_fd(msg, ERROR_FD);
	ft_putstr_fd("\n", ERROR_FD);
	exit(ERROR_CODE);
}
