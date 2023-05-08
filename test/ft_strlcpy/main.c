/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetay <yetay@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:18:42 by yetay             #+#    #+#             */
/*   Updated: 2023/05/05 15:00:29 by yetay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <string.h>
#include <stdio.h>

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);

static void	*reset_mem(char *mem)
{
	size_t	i;

	i = -1;
	while (++i < 127)
		*(mem + i) = '_';
	*(mem + i) = 0;
	return (mem);
}

int	strlcpy_is_diff(char *dst, char *src, size_t dstsize)
{
	size_t	a;
	char	*b;
	size_t	x;
	char	*y;

	reset_mem(dst);
	a = strlcpy(dst, src, dstsize);
	b = strdup(dst);
	reset_mem(dst);
	x = ft_strlcpy(dst, src, dstsize);
	y = strdup(dst);
	printf("Test %3zu:", dstsize);
	if (a != x || strcmp(b, y))
	{
		reset_mem(dst);
		printf(" FAILED.\n");
		printf("dst: %s\n", dst);
		printf("src :%s\n", src);
		printf("dstsize: %zu\n", dstsize);
		printf("   strlcpy(dst, src, dstsize): %zu %s\n", a, b);
		printf("ft_strlcpy(dst, src, dstsize): %zu %s\n", x, y);
		return (1);
	}
	printf(" PASSED!\n");
	return (0);
}

int	main(void)
{
	char	mem[128];
	char	*src;
	char	*dst;
	int		i;

	src = "A string of characters";
	dst = mem;
	i = -1;
	while (++i < 130)
	{
		if (strlcpy_is_diff(dst, src, i))
			return (1);
	}
	printf("All tests passed.\n");
	return (0);
}
