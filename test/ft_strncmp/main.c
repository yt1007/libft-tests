/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetay <yetay@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:25:39 by yetay             #+#    #+#             */
/*   Updated: 2023/05/08 10:34:08 by yetay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <string.h>
#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, size_t n);

int	strncmp_is_diff(char *s1, char *s2, size_t n)
{
	if (strncmp(s1, s2, n) != ft_strncmp(s1, s2, n))
	{
		printf("String 1: %s\nString 2: %s\n", s1, s2);
		printf("Results: %i (strncmp, %zu ch)\n", strncmp(s1, s2, n), n);
		printf("Results: %i (ft_strncmp, %zu ch)\n", ft_strncmp(s1, s2, n), n);
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
		if (strncmp_is_diff("panic", "panicky", i++))
			return (1);
	i = 0;
	while (i < 8)
		if (strncmp_is_diff("panicky", "panic", i++))
			return (1);
	if (strncmp_is_diff("", "", 0))
		return (1);
	if (strncmp_is_diff("", "", 1))
		return (1);
	if (strncmp_is_diff("", "panic", 0))
		return (1);
	if (strncmp_is_diff("", "panic", 1))
		return (1);
	if (strncmp_is_diff("panic", "", 0))
		return (1);
	if (strncmp_is_diff("panic", "", 1))
		return (1);
	printf("All tests passed.\n");
	return (0);
}
