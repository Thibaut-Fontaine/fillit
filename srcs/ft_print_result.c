/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_result.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 16:24:24 by tfontain          #+#    #+#             */
/*   Updated: 2016/12/08 18:52:41 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
** display byte per byte size times, considering bytes like chars.
*/

static void		ft_putmem(char *mem, size_t size)
{
	while (size > 0)
	{
		ft_putchar(*mem);
		++mem;
		--size;
	}
}

/*
** create an 2D square array : array[size][size] and return the adress.
*/

static char		**ft_init_result(char **result, size_t size)
{
	size_t		k;

	result = malloc(sizeof(char*) * size);
	k = 0;
	while (k < size)
		result[k++] = malloc(sizeof(char) * size);
	k = 0;
	while (k < size)
		ft_memset(result[k++], '.', size);
	return (result);
}

static void		ft_destroy_result(char **result, size_t size)
{
	size_t		k;

	k = 0;
	while (k < size)
		free(result[k++]);
	free(result);
}

/*
** browse all the blocks and fill the 2D array with, shifting the positions.
*/

static char		**ft_create_result(t_block *blocks, t_coord *pos, size_t size)
{
	char		**result;
	int			i;
	int			current;

	result = NULL;
	result = ft_init_result(result, size);
	current = 0;
	while (!(blocks[current].array[0].x == -1))
	{
		i = 3;
		while (i >= 0)
		{
			result[blocks[current].array[i].y + pos[current].y]
				[blocks[current].array[i].x + pos[current].x] = current + 'A';
			--i;
		}
		++current;
	}
	return (result);
}

/*
** display the 2D array, adding a '\n' between each row
*/

void			ft_print_result(t_block *blocks, t_coord *pos, size_t size)
{
	size_t		k;
	char		**result;

	result = ft_create_result(blocks, pos, size);
	k = 0;
	while (k < size)
	{
		ft_putmem(result[k], size);
		ft_putchar('\n');
		++k;
	}
	ft_destroy_result(result, size);
}
