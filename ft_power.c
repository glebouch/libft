/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glebouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 09:57:09 by glebouch          #+#    #+#             */
/*   Updated: 2017/11/14 20:38:22 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_power(int a, int b)
{
	int c;

	c = a;
	while (b-- > 1)
		c *= a;
	return (c);
}