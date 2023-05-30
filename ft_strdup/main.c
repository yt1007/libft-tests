/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetay <yetay@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:40:54 by yetay             #+#    #+#             */
/*   Updated: 2023/05/08 17:47:28 by yetay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char	*ft_strdup(char *s1);

int	strdup_is_diff(char *s1)
{
	char	*a;
	char	*b;

	a = strdup(s1);
	if (a == 0)
		return (0);
	b = ft_strdup(s1);
	if (b == 0)
		return (0);
	if (strcmp(a, b) || strcmp(s1, a) || strcmp(s1, b))
	{
		printf("       s1: %s\n", s1);
		printf("   strdup: %s\n", a);
		printf("ft_strdup: %s\n\n", b);
		return (1);
	}
	free(b);
	free(a);
	return (0);
}

int	main(void)
{
	char	*test[10];
	int		errors;
	int		i;

	test[0] = "hello 42";
	test[1] = "AUGAoXZqCrMHzMW2YAyhnqQm8SToHarcHvt";
	test[2] = "EGgx87usNoO27HK1";
	test[3] = "iOcsXIfOOhmX4swaMk6A9fuuMhNUddk51";
	test[4] = "cXYrru5wsYM3retUTTxYewLXWnVCzK5W";
	test[5] = "uAwZQfwUrDa";
	test[6] = "0o4Kehac5DqW";
	test[7] = "WRq31mMa9\n4lb6zI5pAAYxdPZ";
	test[8] = "kjp\rpu4dtJ";
	test[9] = "";
	errors = 0;
	i = 0;
	while (i < 10)
		if (strdup_is_diff(test[i++]))
			errors++;
	if (errors == 0)
		printf("All tests passed.\n");
	return (0);
}
