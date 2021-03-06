/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 11:48:45 by juazouz           #+#    #+#             */
/*   Updated: 2019/01/03 18:58:56 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
**	Returns the sum of the distance to the nearest enemy
**	for every point of the piece.
*/

static int		nearest_enemy_dist(t_state *state, t_list *elem)
{
	t_point	piece_point_origin;
	t_point	piece_point;
	t_point	enemy_point;
	int		dist_sum;

	piece_point_origin = *((t_point*)elem->content);
	dist_sum = 0;
	point_init(&piece_point);
	piece_point = piece_center(&state->piece);
	get_nearest_enemy(state,
						point_add(piece_point_origin, piece_point),
						&enemy_point);
	dist_sum += point_dist(point_add(piece_point_origin, piece_point),
							enemy_point);
	return (dist_sum);
}

/*
**	Creates a list of all possible moves.
*/

static void		create_moves_list(t_state *state, t_list **list)
{
	t_list	*new;
	t_point	point;

	point_init(&point);
	while (get_next_cell(&state->board, &point))
	{
		if (can_place(&state->board, &state->piece, &point, state->playerid))
		{
			new = ft_lstnew(&point, sizeof(point));
			ft_lstadd(list, new);
			if (state->mode == MODE_EZPZ)
				return ;
		}
	}
}

/*
**	Returns the move with the best score.
*/

static t_list	*lst_moves_get_min(t_list *lst, t_state *state)
{
	t_list	*curr;
	t_list	*res;
	int		res_int;
	int		tmp;

	curr = lst;
	res_int = -1;
	res = NULL;
	while (curr != NULL)
	{
		tmp = nearest_enemy_dist(state, curr);
		if (res_int == -1 || tmp < res_int)
		{
			res = curr;
			res_int = tmp;
		}
		curr = curr->next;
	}
	return (res);
}

static void		update_stage(t_state *state, t_point *point)
{
	t_list	move;
	int		enemy_dist;

	move.content = point;
	enemy_dist = nearest_enemy_dist(state, &move);
	if (state->mode == MODE_INITIAL || state->mode == MODE_EZPZ)
	{
		if (enemy_dist <= 1)
		{
			state->mode = MODE_CONTACT;
		}
	}
	else if (state->mode == MODE_CONTACT)
	{
		if (enemy_dist > 7)
		{
			state->mode = MODE_EZPZ;
		}
	}
}

int				compute_move(t_state *state, t_point *point)
{
	t_list	*moves;

	moves = NULL;
	create_moves_list(state, &moves);
	if (moves == NULL)
		return (0);
	if (state->mode == MODE_EZPZ)
	{
		*point = *(t_point*)moves->content;
	}
	else
	{
		*point = *(t_point*)lst_moves_get_min(moves, state)->content;
	}
	update_stage(state, point);
	ft_lstdel(&moves, NULL);
	return (1);
}
