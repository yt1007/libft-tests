/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetay <yetay@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 09:11:16 by yetay             #+#    #+#             */
/*   Updated: 2023/04/28 14:53:58 by yetay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int	ft_isalpha(int c);

int	main(void)
{
	int	c;

	c = 0;
	while (c < 256)
	{
		if (isalpha(c) != ft_isalpha(c))
		{
			printf("char: %c\t", c);
			printf("isalpha(%c): %i\t", c, isalpha(c));
			printf("ft_isalpha(%c): %i\n", c, ft_isalpha(c));
			return (0);
		}
		c++;
	}
	printf("All tests passed.\n");
	return (0);
}
