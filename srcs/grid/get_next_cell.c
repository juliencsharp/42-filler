/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_cell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 11:55:02 by juazouz           #+#    #+#             */
/*   Updated: 2019/01/03 14:37:01 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
**	Moves the point to the next cell.
**	Returns 0 when the end of the grid is reached.
*/

int	get_next_cell(t_grid *grid, t_point *point)
{
	if (!point->iteration_started)
	{
		point->iteration_started = true;
		return (1);
	}
	point->x++;
	if (point->x >= grid->width)
	{
		point->x = 0;
		point->y++;
		if (point->y >= grid->height)
		{
			return (0);
		}
	}
	return (1);
}
