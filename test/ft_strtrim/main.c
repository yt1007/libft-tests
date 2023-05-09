/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetay <yetay@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:24:12 by yetay             #+#    #+#             */
/*   Updated: 2023/05/09 18:35:05 by yetay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

int	ft_strtrim_isbad(char const *s1, char const *set, char *t)
{
	char	*str;

	str = ft_strtrim(s1, set);
	if (str == 0)
		return (0);
	if (strcmp(str, t))
	{
		printf("s1: %s\nset: %s\n", s1, set);
		printf("Expected string: %s\n", t);
		printf("ft_strtrim(s1, set): %s\n", str);
		return (1);
	}
	free(str);
	return (0);
}

int	main(void)
{
	int		errors;

	errors = 0;
	if (ft_strtrim_isbad("abcdefghij", "aj", "bcdefghi"))
		errors++;
	if (ft_strtrim_isbad("abcdefghij", "jiba", "cdefgh"))
		errors++;
	if (ft_strtrim_isbad("abcdefghij", "", "abcdefghij"))
		errors++;
	if (ft_strtrim_isbad("    abcde     ", " ", "abcde"))
		errors++;
	if (ft_strtrim_isbad("", "", ""))
		errors++;
	if (errors == 0)
		printf("All tests passed.\n");
	return (0);
}
