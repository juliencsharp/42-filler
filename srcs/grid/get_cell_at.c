/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cell_at.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 15:20:25 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/28 16:06:44 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	get_cell_at(t_grid *grid, t_point point)
{
	return (grid->cells[point.x + point.y * grid->width]);
}
