/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetay <yetay@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:17:45 by yetay             #+#    #+#             */
/*   Updated: 2023/05/08 10:18:45 by yetay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strrchr(char *s, int c);

int	strrchr_is_diff(char *s, int c)
{
	if (strrchr(s, c) != ft_strrchr(s, c))
	{
		printf("%p: %s\n", strrchr(s, c), strrchr(s, c));
		printf("%p: %s\n", ft_strrchr(s, c), ft_strrchr(s, c));
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
		if (strrchr_is_diff(s, c))
			return (1);
	s = "";
	strrchr_is_diff(s, 0);
	strrchr_is_diff(s, 'A');
	printf("All tests passed.\n");
	return (0);
}
