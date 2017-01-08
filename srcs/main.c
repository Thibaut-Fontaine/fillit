/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:28:59 by tfontain          #+#    #+#             */
/*   Updated: 2016/12/12 19:54:36 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int				main(int argc, const char *argv[])
{
	t_block		*blocks;

	blocks = ft_input(argc, argv);
	ft_try_blocksize(blocks);
	free(blocks);
	return (0);
}
