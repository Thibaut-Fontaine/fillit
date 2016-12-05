/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:28:59 by tfontain          #+#    #+#             */
/*   Updated: 2016/12/05 03:31:28 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int				main(int argc, const char *argv[])
{
	t_block		*blocks;
	t_coord		*pos;
	size_t		size;

	size = 15;
	pos = malloc(sizeof(t_coord) * 4);
	pos[0].x = 0;
	pos[0].y = 0;
	pos[1].x = 0;
	pos[1].y = 3;
	pos[2].x = 0;
	pos[2].y = 7;
	pos[3].x = 0;
	pos[3].y = 11;
	pos[4].x = -1;
	pos[4].y = -1;
	blocks = ft_input(argc, argv);
	//ft_try_blocksize(blocks);
	ft_print_result(blocks, pos, size);
	return (0);
}
