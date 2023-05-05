/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetay <yetay@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 08:53:37 by yetay             #+#    #+#             */
/*   Updated: 2023/05/02 19:14:46 by yetay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

void	*ft_memmove(void *dst, void *src, size_t len);

void	*reset_str(char *str)
{
	size_t	i;

	i = -1;
	while (++i < 29)
	{
		if ('A' + i <= 'Z')
			*(str + i) = 'A' + i;
		else
			*(str + i) = '_';
	}
	*(str + i) = 0;
	return (str);
}

int	test_compare(void *mem, void *dst, void *src, size_t len)
{
	char	*d;
	char	*s;
	char	*a;
	char	*b;
	char	*x;
	char	*y;

	d = strdup(dst);
	s = strdup(src);
	a = strdup(memmove(dst, src, len));
	b = strdup(mem);
	reset_str(mem);
	x = strdup(ft_memmove(dst, src, len));
	y = strdup(mem);
	if (strcmp(a, x))
	{
		write(2, "src: ", 5);
		write(2, src, len);
		write(2, "\n", 1);
		write(2, "dst: ", 6);
		write(2, dst, strlen(dst));
		write(2, "\n", 1);
		write(2, "   memmove (ret): ", 18);
		write(2, a, strlen(a));
		write(2, "\n", 1);
		write(2, "ft_memmove (ret): ", 18);
		write(2, x, strlen(x));
		write(2, "\n", 1);
		write(2, "src: ", 5);
		write(2, src, len);
		write(2, "\n", 1);
		reset_str(mem);
		write(2, "mem: ", 5);
		write(2, mem, 30);
		write(2, "\n", 1);
		write(2, "   memmove (mem): ", 18);
		write(2, b, strlen(b));
		write(2, "\n", 1);
		write(2, "ft_memmove (mem): ", 18);
		write(2, y, strlen(y));
		write(2, "\n\n", 2);
		return (1);
	}
	return (0);
}

int	main(void)
{
	char	dst[30];
	char	*src;

	reset_str(dst);
	src = "a string of chars.";
	if (test_compare(dst, dst, src, strlen(src)))
		return (1);
	reset_str(dst);
	if (test_compare(dst, dst, src, 0))
		return (1);
	reset_str(dst);
	src = &dst[20];
	if (test_compare(dst, dst, src, strlen(src)))
		return (1);
	reset_str(dst);
	src = &dst[10];
	if (test_compare(dst, dst, src, strlen(src)))
		return (1);
	reset_str(dst);
	if (test_compare(dst, dst, src, 0))
		return (1);
	reset_str(dst);
	if (test_compare(dst, &dst[1], dst, 0))
		return (1);
	reset_str(dst);
	if (test_compare(dst, &dst[1], dst, 1))
		return (1);
	reset_str(dst);
	if (test_compare(dst, &dst[1], dst, 3))
		return (1);
	write(2, "All tests passed.\n", 18);
	return (0);
}
