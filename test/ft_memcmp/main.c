/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetay <yetay@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:25:56 by yetay             #+#    #+#             */
/*   Updated: 2023/05/11 08:33:46 by yetay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <string.h>
#include <stdio.h>

int	ft_memcmp(void *s1, void *s2, size_t n);

int	memcmp_is_diff(void *s1, void *s2, size_t n)
{
	int	x;
	int	y;

	x = memcmp(s1, s2, n);
	y = ft_memcmp(s1, s2, n);
	if (x != y)
	{
		printf("String 1: %s\nString 2: %s\n", s1, s2);
		printf("   memcmp(s1, s2, %zu): %i\n", n, x);
		printf("ft_memcmp(s1, s2, %zu): %i\n", n, y);
		printf("--\n");
		return (1);
	}
	return (0);
}

int	main(void)
{
	int	i;
	int	errors;

	errors = 0;
	i = 0;
	while (i < 8 && i <= (int)strlen("panic"))
		if (memcmp_is_diff("panic", "panicky", i++))
			errors++;
	i = 0;
	while (i < 8 && i <= (int)strlen("panic"))
		if (memcmp_is_diff("panicky", "panic", i++))
			errors++;
	if (memcmp_is_diff("", "", 0))
		errors++;
	if (memcmp_is_diff("", "", 1))
		errors++;
	if (memcmp_is_diff("", "panic", 0))
		errors++;
	if (memcmp_is_diff("", "panic", 1))
		errors++;
	if (memcmp_is_diff("panic", "", 0))
		errors++;
	if (memcmp_is_diff("panic", "", 1))
		errors++;
	if (errors == 0)
		printf("All tests passed.\n");
	return (0);
}
