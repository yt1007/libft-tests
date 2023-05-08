/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetay <yetay@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 09:33:11 by yetay             #+#    #+#             */
/*   Updated: 2023/05/08 09:33:15 by yetay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int	ft_tolower(int c);

int	main(void)
{
	int	c;

	c = 0;
	while (c < 256)
	{
		if (tolower(c) != ft_tolower(c))
		{
			printf("char: %c\t", c);
			printf("tolower(%c): %i\t", c, tolower(c));
			printf("ft_tolower(%c): %i\n", c, ft_tolower(c));
			return (0);
		}
		c++;
	}
	printf("All tests passed.\n");
	return (0);
}
