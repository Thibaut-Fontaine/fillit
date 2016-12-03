/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tetriminos.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 00:13:59 by tfontain          #+#    #+#             */
/*   Updated: 2016/12/02 17:11:42 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_putmem(char *mem, size_t size)
{
	while (size > 0)
	{
		ft_putchar(*mem);
		++mem;
		--size;
	}
}

void		ft_print_onetetri(t_block block)
{
	int		k;
	int		i;
	int		n;
	int		count_hash;
	char	toprint[4][4];

	k = 0;
	count_hash = 0;
	while (k < 4)
		ft_memset(toprint[k++], '.', 4);
	k = 0;
	while (k < 4 && (i = 0) == 0)
	{
		while (i < 4 && (n = 0) == 0)
		{
			while (n < 4)
			{
				if (count_hash <= 4
						&& block.array[n].x == k && block.array[n].y == i)
				{
					toprint[k][i] = '#';
					++count_hash;
				}
				++n;
			}
			++i;
		}
		++k;
	}
	k = 0;
	while (k < 4)
	{
		ft_putmem(toprint[k++], 4);
		ft_putchar('\n');
	}
}

void		ft_print_tetriminos(t_block *pt)
{
	int		k;
	int		first_newline;

	first_newline = 0;
	k = 0;
	while (!(pt[k].array[0].x == -1 && pt[k].array[0].y == -1))
	{
		if (first_newline == 1)
			ft_putchar('\n');
		else if (first_newline == 0)
			first_newline = 1;
		ft_print_onetetri(pt[k]);
		++k;
	}
}
