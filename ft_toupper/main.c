/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetay <yetay@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 09:24:47 by yetay             #+#    #+#             */
/*   Updated: 2023/05/08 09:27:48 by yetay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int	ft_toupper(int c);

int	main(void)
{
	int	c;

	c = 0;
	while (c < 256)
	{
		if (toupper(c) != ft_toupper(c))
		{
			printf("char: %c\t", c);
			printf("toupper(%c): %i\t", c, toupper(c));
			printf("ft_toupper(%c): %i\n", c, ft_toupper(c));
			return (0);
		}
		c++;
	}
	printf("All tests passed.\n");
	return (0);
}
