/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetay <yetay@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:25:56 by yetay             #+#    #+#             */
/*   Updated: 2023/05/08 11:27:33 by yetay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <string.h>
#include <stdio.h>

int	ft_memcmp(void *s1, void *s2, size_t n);

int	memcmp_is_diff(char *s1, char *s2, size_t n)
{
	if (memcmp(s1, s2, n) != ft_memcmp(s1, s2, n))
	{
		printf("String 1: %s\nString 2: %s\n", s1, s2);
		printf("Results: %i (memcmp, %zu ch)\n", memcmp(s1, s2, n), n);
		printf("Results: %i (ft_memcmp, %zu ch)\n", ft_memcmp(s1, s2, n), n);
		printf("--\n");
		return (1);
	}
	return (0);
}

int	main(void)
{
	int	i;

	i = 0;
	while (i < 8)
		if (memcmp_is_diff("panic", "panicky", i++))
			return (1);
	i = 0;
	while (i < 8)
		if (memcmp_is_diff("panicky", "panic", i++))
			return (1);
	if (memcmp_is_diff("", "", 0))
		return (1);
	if (memcmp_is_diff("", "", 1))
		return (1);
	if (memcmp_is_diff("", "panic", 0))
		return (1);
	if (memcmp_is_diff("", "panic", 1))
		return (1);
	if (memcmp_is_diff("panic", "", 0))
		return (1);
	if (memcmp_is_diff("panic", "", 1))
		return (1);
	printf("All tests passed.\n");
	return (0);
}
