/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetay <yetay@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 09:47:14 by yetay             #+#    #+#             */
/*   Updated: 2023/05/08 10:08:08 by yetay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strchr(char *s, int c);

int	strchr_is_diff(char *s, int c)
{
	if (strchr(s, c) != ft_strchr(s, c))
	{
		printf("%p: %s\n", strchr(s, c), strchr(s, c));
		printf("%p: %s\n", ft_strchr(s, c), ft_strchr(s, c));
		return (1);
	}
	return(0);
}

int	main(void)
{
	char	*s;
	int		c;

	s = "The quick brown fox jumps over the lazy dog.";
	c = -1;
	while (++c < 256)
		if (strchr_is_diff(s, c))
			return (1);
	s = "";
	strchr_is_diff(s, 0);
	strchr_is_diff(s, 'A');
	printf("All tests passed.\n");
	return (0);
}
