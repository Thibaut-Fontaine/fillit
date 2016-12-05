/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimao-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 20:22:10 by psimao-d          #+#    #+#             */
/*   Updated: 2016/12/05 00:29:21 by psimao-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_checkpos(t_block *blocks, t_coord *pos, int bsize, int index)
{
	int	cnt;
	int	cnt2;
	int	idx;
	int test;

	cnt = 0;
	cnt2 = 0;
	test = 0;
	idx = index;
	while (index >= 0)
	{
		cnt = 0;
		while (cnt < 4)
		{
			cnt2 = 0;
			while (cnt2 < 4)
			{
				if (blocks[idx].array[cnt].x + pos[idx].x != blocks[index].array[cnt].x + pos[idx].x && \
				blocks[idx].array[cnt].y + pos[idx].y != blocks[index].array[cnt].y + pos[idx].y && \
				blocks[idx].array[cnt].x + pos[idx].x <= bsize && \
				blocks[idx].array[cnt].y + pos[idx].y <= bsize)
				{
					test++;
					if (test == 4)
						return (1);
				}
				cnt2++;
			}
			cnt++;
		}
		index--;
	}
	return (0);
}

int	ft_bruteforce(t_block *blocks, t_coord *pos, int bsize, int index)
{
	while (pos[index].y < bsize && blocks[index].array[0].y != -1)
	{
		pos[index].x = 0;
		while (pos[index].x < bsize)
		{
			if (ft_checkpos(blocks, pos, bsize, index) == 1)
				if (ft_bruteforce(blocks, pos, bsize, index + 1) == 1)
				{
					ft_print_result(blocks, pos, bsize);
					return (1);
				}
			pos[index].x++;
		}
		pos[index].y++;
	}
 	return(0); 
}

void	ft_try_blocksize(t_block *blocks)
{
	int		bsize;
	t_coord	*pos;

	bsize = 3;
	pos = (t_coord *)malloc(sizeof(t_coord) * 27);
	if (!pos)
		return ;
	while (ft_bruteforce(blocks, pos, bsize, 0) == 0)
		bsize++;
	return ;
}
