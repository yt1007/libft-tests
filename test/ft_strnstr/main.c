/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetay <yetay@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:42:07 by yetay             #+#    #+#             */
/*   Updated: 2023/05/08 13:10:12 by yetay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <string.h>
#include <stdio.h>

char	*ft_strnstr(char *haystack, char *needle, size_t len);

int	strnstr_is_diff(char *haystack, char *needle, size_t len)
{
	char	*a;
	char	*b;

	a = strnstr(haystack, needle, len);
	b = ft_strnstr(haystack, needle, len);
	if (a != b)
	{
		printf("needle: %s\nhaystack: %s\nlen: %zu\n", needle, haystack, len);
		printf("   strnstr: (%p) %s\n", a, a);
		printf("ft_strnstr: (%p) %s\n\n", b, b);
		return (1);
	}
	return (0);
}

int	main(void)
{
	char	*haystack;
	char	*needle;
	char	*not_found;
	size_t	i;
	size_t	errors;

	haystack = "Foo Bar Baz";
	needle = "Bar";
	not_found = "Fool";
	errors = 0;
	i = 0;
	while (i <= strlen(haystack))
		if (strnstr_is_diff(haystack, needle, i++))
			errors += 1;
	if (strnstr_is_diff(haystack, "", strlen(haystack)))
		errors += 1;
	if (strnstr_is_diff(haystack, not_found, strlen(haystack)))
		errors += 1;
	i = 0;
	while (i <= strlen(needle))
		if (strnstr_is_diff("", needle, i++))
			errors += 1;
	if (errors == 0)
		printf("All tests passed.\n");
	return (0);
}
