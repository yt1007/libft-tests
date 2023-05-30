/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetay <yetay@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:19:58 by yetay             #+#    #+#             */
/*   Updated: 2023/05/11 14:38:36 by yetay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char    *ft_strmapi(char const *s, char (*f)(unsigned int, char));

static char	cap(unsigned int i, char c)
{
	if (i >= 0 && c >= 'a' && c <= 'z')
		return (c - 'a' + 'A');
	return (c);
}

static char	uncap(unsigned int i, char c)
{
	if (i >= 0 && c >= 'A' && c <= 'Z')
		return (c - 'A' + 'a');
	return (c);
}

static int	ft_strmapi_isbad(char const *s, char (*f)(unsigned int, char), char *t)
{
	char	*str;

	str = ft_strmapi(s, f);
	if (str == NULL)
		return (0);
	if (strcmp(str, t))
	{
		printf("               s: \"%s\"\n", s);
		printf("ft_strmapi(s, f): \"%s\"\n", str);
		printf(" Expected output: \"%s\"\n", t);
		return (1);
	}
	if (str)
		free(str);
	return (0);
}

int	main(void)
{
	int	errors;

	errors = 0;
	if (ft_strmapi_isbad("abc", cap, "ABC"))
		errors++;
	if (ft_strmapi_isbad("abc", uncap, "abc"))
		errors++;
	if (ft_strmapi_isbad("abcDeF", cap, "ABCDEF"))
		errors++;
	if (ft_strmapi_isbad("abcDeF", uncap, "abcdef"))
		errors++;
	if (ft_strmapi_isbad("abc  FghI", cap, "ABC  FGHI"))
		errors++;
	if (ft_strmapi_isbad("abc  FghI", uncap, "abc  fghi"))
		errors++;
	if (ft_strmapi_isbad("", cap, ""))
		errors++;
	if (ft_strmapi_isbad("", uncap, ""))
		errors++;
	if (errors == 0)
		printf("All tests passed.\n");
	return (0);
}
