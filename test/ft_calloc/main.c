/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetay <yetay@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:01:13 by yetay             #+#    #+#             */
/*   Updated: 2023/05/16 17:50:26 by yetay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

void	*ft_calloc(size_t count, size_t size);

int	calloc_is_diff(size_t count, size_t size)
{
	char	*a;
	char	*b;
	size_t	i;

	a = calloc(count, size);
	if (a == NULL)
		return (0);
	b = ft_calloc(count, size);
	if (b == NULL)
		return (0);
	i = 0;
	while (i < (count * size))
	{
		if (*(a + i) != 0 || *(b + i) != 0)
		{
			printf("count: %zu\tsize: %zu\n", count, size);
			printf("i = %zu: ", i);
			printf("calloc = '%c', ", *(a + i));
			printf("ft_calloc = '%c'\n", *(b + i));
			return (1);
		}
		i++;
	};
	free(a);
	free(b);
	return (0);
}

int	main(void)
{
	int		errors;
	int		i;
	int		j;

	errors = 0;
	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			if (calloc_is_diff(i, j))
				errors++;
			j++;
		}
		i++;
	}
	if (calloc_is_diff(0, 0))
		errors++;
	if (errors == 0)
		printf("All tests passed.\n");
	return (0);
}
