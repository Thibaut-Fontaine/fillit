/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compare.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 04:06:50 by tfontain          #+#    #+#             */
/*   Updated: 2016/12/05 03:34:19 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int				ft_istetriminos(t_block block)
{
	int			k;
	int			i;
	int			count;

	k = 0;
	while (k < 19)
	{
		i = 0;
		count = 0;
		while (i < 4)
		{
			if (g_pattern[k].array[i].x == block.array[i].x
					&& g_pattern[k].array[i].y == block.array[i].y)
				++count;
			++i;
		}
		if (i == count)
			return (1);
		++k;
	}
	return (0);
}

void			ft_compare(t_block *blocks)
{
	int			k;

	k = 0;
	while (blocks[k].array[0].x != -1)
	{
		if (ft_istetriminos(blocks[k]) == 0)
			ft_error();
		++k;
	}
}
