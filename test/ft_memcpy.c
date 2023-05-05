/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetay <yetay@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 08:52:17 by yetay             #+#    #+#             */
/*   Updated: 2023/05/05 14:05:29 by yetay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <string.h>
#include <stdio.h>

void	*ft_memcpy(void *dst, void *src, size_t n);

static int	memcpy_is_diff(char *dst, char *src, size_t n)
{
	char	d[30];
	char	e[30];
	size_t	i;

	i = -1;
	while (++i < 29)
	{
		d[i] = dst[i];
		e[i] = dst[i];
	}
	d[i] = 0;
	e[i] = 0;
	printf("Test: ft_memcpy(\"%s\", \"%s\", %lu)\n", dst, src, n);
	if (memcpy(d, src, n) != ft_memcpy(d, src, n))
	{
		printf("----  FAILED.\n");
		printf("dst: |%s|\n", dst);
		printf("src: |%s|\n", src);
		printf("memcpy(dst, src, %lu): |%s|\n", n, memcpy(d, src, n));
		printf("ft_memcpy(dst, src, %lu): |%s|\n\n", n, ft_memcpy(e, src, n));
		return (1);
	}
	printf("----  PASSED!\n");
	return (0);
}

int	main(void)
{
	char	dst[30];
	char	*src;
	int		i;

	i = 0;
	while (i < 29)
		dst[i++] = '_';
	dst[i] = '\0';
	src = "A string of character.";
	if (memcpy_is_diff(dst, src, 0))
		return (1);
	if (memcpy_is_diff(dst, src, 2))
		return (1);
	if (memcpy_is_diff(dst, src, strlen(src)))
		return (1);
	src = "";
	if (memcpy_is_diff(dst, src, 0))
		return (1);
	if (memcpy_is_diff(dst, src, 1))
		return (1);
	printf("All tests passed.\n");
	return (0);
}
