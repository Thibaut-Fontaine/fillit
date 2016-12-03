/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TEST_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 14:29:47 by tfontain          #+#    #+#             */
/*   Updated: 2016/12/02 18:23:58 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit/header.h"

int				main()
{
	t_block		*pt;
	t_coord		*pos;

	pos = malloc(sizeof(t_coord) * 3);
	pos[0].x = 0;
	pos[0].y = 0;
	pos[1].x = 1;
	pos[1].y = 0;
	pos[2].x = -1;
	pos[2].y = -1;
	pt = malloc(sizeof(t_block) * 3);
	pt[0].array[0].x = 0;
	pt[0].array[0].y = 0;
	pt[0].array[1].x = 0;
	pt[0].array[1].y = 1;
	pt[0].array[2].x = 0;
	pt[0].array[2].y = 2;
	pt[0].array[3].x = 0;
	pt[0].array[3].y = 3;

	pt[1].array[0].x = 0;
	pt[1].array[0].y = 1;
	pt[1].array[1].x = 1;
	pt[1].array[1].y = 0;
	pt[1].array[2].x = 1;
	pt[1].array[2].y = 1;
	pt[1].array[3].x = 0;
	pt[1].array[3].y = 0;

	pt[2].array[0].y = -1;
	pt[2].array[0].x = -1;
	ft_print_result(pt, pos, 4);
	return (0);
}
