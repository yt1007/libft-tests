/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetay <yetay@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:19:58 by yetay             #+#    #+#             */
/*   Updated: 2023/05/11 15:12:44 by yetay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char*));

static void	cap(unsigned int i, char *s)
{
	if (i >= 0 && s[i] >= 'a' && s[i] <= 'z')
		s[i] = s[i] - 'a' + 'A';
}

static void	uncap(unsigned int i, char *s)
{
	if (i >= 0 && s[i] >= 'A' && s[i] <= 'Z')
		s[i] = s[i] - 'A' + 'a';
}

static int	ft_striteri_isbad(char *s, void (*f)(unsigned int, char*), char *t)
{
	char	str[64];

	strlcpy(str, s, 64);
	ft_striteri(str, f);
	if (strcmp(str, t))
	{
		printf("               s: \"%s\"\n", s);
		printf("ft_striteri(s, f): \"%s\"\n", str);
		printf(" Expected output: \"%s\"\n", t);
		return (1);
	}
	return (0);
}

int	main(void)
{
	int	errors;

	errors = 0;
	if (ft_striteri_isbad("abc", cap, "ABC"))
		errors++;
	if (ft_striteri_isbad("abc", uncap, "abc"))
		errors++;
	if (ft_striteri_isbad("abcDeF", cap, "ABCDEF"))
		errors++;
	if (ft_striteri_isbad("abcDeF", uncap, "abcdef"))
		errors++;
	if (ft_striteri_isbad("abc  FghI", cap, "ABC  FGHI"))
		errors++;
	if (ft_striteri_isbad("abc  FghI", uncap, "abc  fghi"))
		errors++;
	if (ft_striteri_isbad("", cap, ""))
		errors++;
	if (ft_striteri_isbad("", uncap, ""))
		errors++;
	if (errors == 0)
		printf("All tests passed.\n");
	return (0);
}
