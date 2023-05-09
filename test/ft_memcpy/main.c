/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetay <yetay@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 08:52:17 by yetay             #+#    #+#             */
/*   Updated: 2023/05/09 15:09:47 by yetay            ###   ########.fr       */
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
	if (memcpy(d, src, n) != ft_memcpy(d, src, n))
	{
		printf("   dst: |%s|\n", dst);
		printf("   src: |%s|\n", src);
		printf("   memcpy(dst, src, %lu): |%s|\n", n, memcpy(d, src, n));
		printf("ft_memcpy(dst, src, %lu): |%s|\n\n", n, ft_memcpy(e, src, n));
		return (1);
	}
	return (0);
}

int	main(void)
{
	char	dst[30];
	char	*src;
	int		i;
	int		errors;

	errors = 0;
	i = 0;
	while (i < 29)
		dst[i++] = '_';
	dst[i] = '\0';
	src = "A string of character.";
	if (memcpy_is_diff(dst, src, 0))
		errors++;
	if (memcpy_is_diff(dst, src, 2))
		errors++;
	if (memcpy_is_diff(dst, src, strlen(src)))
		errors++;
	src = "";
	if (memcpy_is_diff(dst, src, 0))
		errors++;
	if (memcpy_is_diff(dst, src, 1))
		errors++;
	if (errors == 0)
		printf("All tests passed.\n");
	return (0);
}
