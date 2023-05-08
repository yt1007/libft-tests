/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetay <yetay@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:32:30 by yetay             #+#    #+#             */
/*   Updated: 2023/04/28 15:08:03 by yetay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int	ft_isprint(int c);

int	main(void)
{
	int	c;

	c = 0;
	while (c < 256)
	{
		if (isprint(c) != ft_isprint(c))
		{
			printf("char: %c\t", c);
			printf("isprint(%c): %i\t", c, isprint(c));
			printf("ft_isprint(%c): %i\n", c, ft_isprint(c));
			return (0);
		}
		c++;
	}
	printf("All tests passed.\n");
	return (0);
}
