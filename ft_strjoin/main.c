/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetay <yetay@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:22:50 by yetay             #+#    #+#             */
/*   Updated: 2023/05/09 17:34:25 by yetay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

int	ft_strjoin_isbad(char const *s1, char const *s2, char *t)
{
	char	*str;

	str = ft_strjoin(s1, s2);
	if (str == 0)
		return (0);
	if (strcmp(str, t))
	{
		printf("s1: %s\ns2: %s\n", s1, s2);
		printf("Expected string: %s\n", t);
		printf("ft_strjoin(s1, s2): %s\n", str);
		return (1);
	}
	free(str);
	return (0);
}

int	main(void)
{
	int		errors;

	errors = 0;
	if (ft_strjoin_isbad("A ", "cat is not a dog", "A cat is not a dog"))
		errors++;
	if (ft_strjoin_isbad("", "A cat is not a dog", "A cat is not a dog"))
		errors++;
	if (ft_strjoin_isbad("A cat is not a dog", "", "A cat is not a dog"))
		errors++;
	if (ft_strjoin_isbad("", "", ""))
		errors++;
	if (ft_strjoin_isbad("12345678", "12345678", "1234567812345678"))
		errors++;
	if (ft_strjoin_isbad("12345678901234567890123456789012", "12345678901234567890123456789012", "1234567890123456789012345678901212345678901234567890123456789012"))
		errors++;
	if (errors == 0)
		printf("All tests passed.\n");
	return (0);
}
