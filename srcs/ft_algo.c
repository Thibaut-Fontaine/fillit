/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimao-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 20:22:10 by psimao-d          #+#    #+#             */
/*   Updated: 2016/12/08 18:27:48 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_initzero(t_coord **pos, int index)
{
	while (index < 27)
	{
		(*pos)[index].x = 0;
		(*pos)[index].y = 0;
		index++;
	}
	(*pos)[index].x = -1;
	(*pos)[index].y = -1;
	return (1);
}

int		ft_withinlimits(t_block *blocks, t_coord *pos, int bsize, int index)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if ((blocks[index].array[i].x + pos[index].x >= bsize) ||
		(blocks[index].array[i].y + pos[index].y >= bsize))
			return (0);
		i++;
	}
	return (1);
}

int		ft_checkpos(t_block *blocks, t_coord **pos, int *bsize, int index)
{
	int		cnt;
	int		cnt2;
	int		idx;
	t_coord	p;

	cnt = 0;
	idx = index;
	while (index-- > 0)
	{
		cnt = -1;
		while (++cnt < 4)
		{
			p.x = blocks[idx].array[cnt].x + (*pos)[idx].x;
			p.y = blocks[idx].array[cnt].y + (*pos)[idx].y;
			cnt2 = -1;
			while (++cnt2 < 4)
			{
				if (p.x == blocks[index].array[cnt2].x + (*pos)[index].x
				&& p.y == blocks[index].array[cnt2].y + (*pos)[index].y)
					return (0);
			}
		}
	}
	return (ft_withinlimits(blocks, *pos, *bsize, idx));
}

int		ft_bruteforce(t_block *blocks, t_coord **pos, int *bsize, int index)
{
	if (blocks[index].array[0].x == -1)
		return (1);
	(*pos)[index].y = 0;
	while ((*pos)[index].y < *bsize)
	{
		(*pos)[index].x = 0;
		while ((*pos)[index].x < *bsize)
		{
			if (ft_checkpos(blocks, pos, bsize, index) == 1)
			{
				if (ft_bruteforce(blocks, pos, bsize, index + 1) == 1)
					return (1);
			}
			(*pos)[index].x++;
		}
		(*pos)[index].y++;
	}
	return (0);
}

void	ft_try_blocksize(t_block *blocks)
{
	int		bsize;
	t_coord	*pos;

	bsize = 2;
	pos = (t_coord *)malloc(sizeof(t_coord) * 27);
	if (!pos)
		return ;
	while (ft_initzero(&pos, 0) && !ft_bruteforce(blocks, &pos, &bsize, 0))
		bsize++;
	ft_print_result(blocks, pos, bsize);
	return ;
}
