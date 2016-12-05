/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 00:11:09 by tfontain          #+#    #+#             */
/*   Updated: 2016/12/05 03:36:00 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static t_coord		ft_count_decal(t_block block)
{
	int			i;
	int			cur;
	t_coord		decal;
	t_coord		check;

	cur = 0;
	check.x = 0;
	check.y = 0;
	while (cur < 4)
	{
		i = 0;
		while (i < 4)
		{
			if (block.array[i].x == cur && check.x == 0 && (check.x = 1))
				decal.x = cur;
			if (block.array[i].y == cur && check.y == 0 && (check.y = 1))
				decal.y = cur;
			++i;
		}
		++cur;
	}
	return (decal);
}

static t_block		ft_decal_one_tetri(t_block block)
{
	int			i;
	t_coord		decal;

	i = 0;
	decal = ft_count_decal(block);
	while (i < 4)
	{
		block.array[i].x = block.array[i].x - decal.x;
		block.array[i].y = block.array[i].y - decal.y;
		++i;
	}
	return (block);
}

t_block				*ft_decal(t_block *blocks)
{
	int		k;

	k = 0;
	while (blocks[k].array[0].x != -1)
	{
		blocks[k] = ft_decal_one_tetri(blocks[k]);
		++k;
	}
	return (blocks);
}
