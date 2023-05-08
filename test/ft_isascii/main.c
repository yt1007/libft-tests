/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetay <yetay@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 09:11:16 by yetay             #+#    #+#             */
/*   Updated: 2023/04/28 15:06:35 by yetay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int	ft_isascii(int c);

int	main(void)
{
	int	c;

	c = 0;
	while (c < 256)
	{
		if (isascii(c) != ft_isascii(c))
		{
			printf("char: %c\t", c);
			printf("isascii(%c): %i\t", c, isascii(c));
			printf("ft_isascii(%c): %i\n", c, ft_isascii(c));
			return (0);
		}
		c++;
	}
	printf("All tests passed.\n");
	return (0);
}
