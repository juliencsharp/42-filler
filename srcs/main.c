/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 14:41:57 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/18 20:00:16 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			main(int argc, char *argv[])
{
	int		playerid;
	char	playername[MAX_PLAYER_NAME_LEN];
	t_board	board;
	t_board	piece;

	(void)argc;
	(void)argv;
	ft_bzero(&piece, sizeof(piece));
	read_head(&playerid, (char*)&playername);
	parse_board(&board);
	while (1)
	{
		parse_piece(&piece);
		board_print(&board);
	}
	return (0);
}
