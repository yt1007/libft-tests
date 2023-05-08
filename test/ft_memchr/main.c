/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetay <yetay@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:50:25 by yetay             #+#    #+#             */
/*   Updated: 2023/05/08 11:12:18 by yetay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <string.h>
#include <stdio.h>

void	*ft_memchr(void *s, int c, size_t n);

int	memchr_is_diff(char *s, int c, size_t n)
{
	if (memchr(s, c, n) != ft_memchr(s, c, n))
	{
		printf("s: %s\nc: %d (%c)\nn: %zu\n", s, c, (char) c, n);
		printf("   memchr: (%p) %s\n", memchr(s, c, n), memchr(s, c, n));
		printf("ft_memchr: (%p) %s\n", ft_memchr(s, c, n), ft_memchr(s, c, n));
		return (1);
	}
	return(0);
}

int	main(void)
{
	char	*s;
	int		c;
	size_t	n;

	s = "The quick brown fox jumps over the lazy dog.";
	c = -1;
	while (++c < 256)
	{
		n = -1;
		while (++n <= strlen(s))
			if (memchr_is_diff(s, c, n))
				return (1);
	}
	s = "";
	if (memchr_is_diff(s, 0, 0))
		return (1);
	if (memchr_is_diff(s, 0, strlen(s)))
		return (1);
	if (memchr_is_diff(s, 'A', 0))
		return (1);
	if (memchr_is_diff(s, 'A', strlen(s)))
		return (1);
	printf("All tests passed.\n");
	return (0);
}
