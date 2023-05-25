/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetay <yetay@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:28:54 by yetay             #+#    #+#             */
/*   Updated: 2023/05/16 14:24:00 by yetay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

int	ft_substr_is_bad(char const *s, unsigned int start, size_t len, char *t)
{
	char	*substr;

	substr = ft_substr(s, start, len);
	if (substr == 0)
		return (0);
	if (strcmp(substr, t))
	{
		printf("s: %s\nstart: %u    len: %zu\n", s, start, len);
		printf("Expected substring: %s\n", t);
		printf("ft_substr: %s\n", substr);
		return (1);
	}
	if (substr)
		free(substr);
	return (0);
}

int	main(void)
{
	int		errors;
	char	*s;
	size_t	i;

	errors = 0;
	s = "A cat is not a dog.";
	i = -1;
	/* Intended use */
	while (++i < ft_strlen(s))
		if (ft_substr_is_bad(s, i, ft_strlen(s), s + i))
			errors++;
	if (ft_substr_is_bad(s, 2, 3, "cat"))
		errors++;
	if (ft_substr_is_bad(s, 0, 5, "A cat"))
		errors++;
	if (ft_substr_is_bad(s, 0, ft_strlen(s), s))
		errors++;
	/* len exceptions */
	if (ft_substr_is_bad(s, 0, ft_strlen(s) + 5, s))
		errors++;
	if (ft_substr_is_bad(s, 2, 0, ""))
		errors++;
	/* Empties */
	if (ft_substr_is_bad("", 0, 1, ""))
		errors++;
	/* start index is end of string */
	i = 0;
	while (i < (ft_strlen(s) + 5))
		if (ft_substr_is_bad(s, ft_strlen(s), i++, ""))
			errors++;
	i = -1;
	while (++i <= 5)
		if (ft_substr_is_bad(s, ft_strlen(s) + 1, i, ""))
			errors++;
	/* start index is beyond the string */
	i = -1;
	while (++i <= 5)
		if (ft_substr_is_bad(s, ft_strlen(s) + 2, 0, ""))
			errors++;
	if (errors == 0)
		printf("All tests passed.\n");
	return (0);
}
