/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetay <yetay@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 18:38:41 by yetay             #+#    #+#             */
/*   Updated: 2023/04/28 19:01:23 by yetay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <string.h>
#include <stdio.h>

void	*ft_memset(void *b, int c, size_t len);

int	main(void)
{
	char	a[8];
	int		i;

	i = 0;
	while (i < 8)
		a[i++] = ' ';
	a[7] = '\0';
	i = 0;
	while (i < 8)
	{
		if (memset(a, i + '0', i) != ft_memset(a, i + '0', i))
		{
			printf("%d: |%s|\n", i, ft_memset(a, i + '0', i));
			printf("%d: |%s|\n", i, ft_memset(a, i + '0', i));
			return (0);
		}
		i++;
	}
	printf("All test passed.\n");
	return (0);
}
