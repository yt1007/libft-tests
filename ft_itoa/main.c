/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetay <yetay@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:50:08 by yetay             #+#    #+#             */
/*   Updated: 2023/05/11 11:46:55 by yetay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char	*ft_itoa(int n);

static int	ft_itoa_isbad(int n, char *t)
{
	char	*str;

	str = ft_itoa(n);
	if (strcmp(str, t))
	{
		printf("      n: %d\n", n);
		printf("ft_itoa: %s\n", str);
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
	/*  Integer limits */
	if (ft_itoa_isbad(-2147483648,"-2147483648"))
		errors++;
	if (ft_itoa_isbad(0,"0"))
		errors++;
	if (ft_itoa_isbad(2147483647,"2147483647"))
		errors++;
	/* Random valid integers */
	if (ft_itoa_isbad(42,"42"))
		errors++;
	if (ft_itoa_isbad(-42,"-42"))
		errors++;
	if (ft_itoa_isbad(1234567890,"1234567890"))
		errors++;
	if (ft_itoa_isbad(-1234567890,"-1234567890"))
		errors++;
	if (errors == 0)
		printf("All tests passed.\n");
	return (0);
}
