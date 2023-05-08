/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetay <yetay@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 09:11:16 by yetay             #+#    #+#             */
/*   Updated: 2023/04/28 14:58:52 by yetay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int	ft_isdigit(int c);

int	main(void)
{
	int	c;

	c = 0;
	while (c < 255)
	{
		if (isdigit(c) != ft_isdigit(c))
		{
			printf("char: %c\t", c);
			printf("isdigit(%c): %i\t", c, isdigit(c));
			printf("ft_isdigit(%c): %i\n", c, ft_isdigit(c));
			return (0);
		}
		c++;
	}
	printf("All tests passed.\n");
	return (0);
}
