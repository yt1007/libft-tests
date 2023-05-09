/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetay <yetay@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:35:02 by yetay             #+#    #+#             */
/*   Updated: 2023/05/09 15:13:02 by yetay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <string.h>
#include <stdio.h>

size_t	ft_strlcat(char *dst, char *src, size_t dstsize);

static void	*reset_mem(char *mem, size_t memsize)
{
	size_t	i;

	i = 0;
	while (i < (memsize - 1))
		*(mem + i++) = 0;
	return (mem);
}

int	strlcat_is_diff(int n, char *mem, char *dst, char *src, size_t dstsize)
{
	size_t	a;
	char	*b;
	size_t	x;
	char	*y;

	reset_mem(mem, 32);
	strlcpy(mem, dst, 32);
	a = strlcat(mem, src, dstsize);
	b = strdup(mem);
	reset_mem(mem, 32);
	strlcpy(mem, dst, 32);
	x = ft_strlcat(mem, src, dstsize);
	y = strdup(mem);
	if (a != x || strcmp(b, y))
	{
		printf("Test %3d FAILED.\n", n);
		printf("dst: %s\n", dst);
		printf("src :%s\n", src);
		printf("dstsize: %zu\n", dstsize);
		printf("   strlcat(dst, src, dstsize): %zu %s\n", a, b);
		printf("ft_strlcat(dst, src, dstsize): %zu %s\n", x, y);
		return (1);
	}
	return (0);
}

int	main(void)
{
	char	mem[32];
	char	*s;
	int		i;
	size_t	j;
	int		errors;

	s = "A cat is not a dog. A cat is a cat.";
	errors = 0;
	i = 1;
	/* Intended usage */
	if (strlcat_is_diff(i++, mem, "A", " cat is not a dog.", 32))
		errors++;
	if (strlcat_is_diff(i++, mem, "", "A cat is not a dog.", 32))
		errors++;
	if (strlcat_is_diff(i++, mem, "A cat", " is not a dog.", 32))
		errors++;
	/* dstsize not reflective of true dst size */
	j = 0;
	while (j < 32)
		if (strlcat_is_diff(i++, mem, "A cat", " is not a dog.", j++))
			errors++;
	j = 0;
	while (j < 32)
		if (strlcat_is_diff(i++, mem, "", s, j++))
			errors++;
	/* dst is longer than dstsize */
	if (strlcat_is_diff(i, mem, s, ".", 32))
		errors++;
	if (errors == 0)
		printf("All tests passed.\n");
	return (0);
}
