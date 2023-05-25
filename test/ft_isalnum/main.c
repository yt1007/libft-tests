/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetay <yetay@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:32:30 by yetay             #+#    #+#             */
/*   Updated: 2023/04/28 15:00:40 by yetay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int	ft_isalnum(int c);

int	main(void)
{
	int	c;

	c = 0;
	while (c < 256)
	{
		if (isalnum(c) != ft_isalnum(c))
		{
			printf("char: %c\t", c);
			printf("isalnum(%c): %i\t", c, isalnum(c));
			printf("ft_isalnum(%c): %i\n", c, ft_isalnum(c));
			return (0);
		}
		c++;
	}
	printf("All tests passed.\n");
	return (0);
}
