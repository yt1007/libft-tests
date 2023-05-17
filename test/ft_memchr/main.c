/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetay <yetay@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:50:25 by yetay             #+#    #+#             */
/*   Updated: 2023/05/17 20:46:06 by yetay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <string.h>
#include <stdio.h>

void	*ft_memchr(void *s, int c, size_t n);

int	memchr_is_diff(char *s, int c, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	size_t			i;

	a = memchr(s, c, n);
	b = ft_memchr(s, c, n);
	if (a != b)
	{
		printf("s: (%p) ", s);
		i = -1;
		while (++i < n)
			if (c >= ' ' && c <= '~')
				printf("%c", *(s + i));
			else
				printf("\\%d", *(s + i));
		printf("\n");
		if (c >= ' ' && c <= '~')
			printf("c: %d (%c)\n", c, (unsigned char) c);
		else
			printf("c: %d (\\%d)\n", c, (unsigned char) c);
		printf("n: %zu\n", n);
		printf("   memchr: %p\n", a);
		printf("ft_memchr: %p\n", b);
		return (1);
	}
	return(0);
}

int	main(void)
{
	char	*s;
	int		c;
	size_t	n;
	int		errors;

	errors = 0;
	s = "The quick brown fox jumps over the lazy dog.";
	c = -1;
	while (++c < 256)
	{
		n = -1;
		while (++n <= strlen(s))
			if (memchr_is_diff(s, c, n))
				errors++;
	}
	if (memchr_is_diff(s, 'e', 3))
		errors++;
	if (memchr_is_diff(s, 'e' + 256, 3))
		errors++;
	s = "";
	if (memchr_is_diff(s, 0, 0))
		errors++;
	if (memchr_is_diff(s, 0, 1))
		errors++;
	if (memchr_is_diff(s, 0, strlen(s)))
		errors++;
	if (memchr_is_diff(s, 0, strlen(s) + 1))
		errors++;
	if (memchr_is_diff(s, 0, strlen(s) + 2))
		errors++;
	if (memchr_is_diff(s, 'A', 0))
		errors++;
	if (memchr_is_diff(s, 'A', strlen(s)))
		errors++;
	char x[] = {0, 1, 2, 3, 4, 5};
	if (memchr_is_diff(x, 2, 3))
		errors++;
	if (memchr_is_diff(x, 2, 4))
		errors++;
	if (memchr_is_diff(x, 2 + 256, 3))
		errors++;
	if (memchr_is_diff(x, 2 + 256, 4))
		errors++;
	if (errors == 0)
		printf("All tests passed.\n");
	return (0);
}
