/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetay <yetay@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 10:10:19 by yetay             #+#    #+#             */
/*   Updated: 2023/05/05 13:46:09 by yetay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

size_t	ft_strlen(char *str);

int	strlen_test_failed(char *str)
{
	if (strlen(str) != ft_strlen(str))
	{
		printf("String: %s\n", str);
		printf("strlen(\"%s\"): %lu\n", str, strlen(str));
		printf("ft_strlen(\"%s\"): %lu\n", str, ft_strlen(str));
		return (1);
	}
	return (0);
}

int	main(void)
{
	if (strlen_test_failed(""))
		return (1);
	if (strlen_test_failed("A string of characters"))
		return (1);
	if (strlen_test_failed("The strlen() function computes the length of the string s. The strnlen() function attempts to compute the length of s, but never scans beyond the first maxlen bytes of s."))
		return (1);
	printf("All tests passed.\n");
	return (0);
}
