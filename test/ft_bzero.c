/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetay <yetay@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 07:13:06 by yetay             #+#    #+#             */
/*   Updated: 2023/05/02 08:10:56 by yetay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>
#include <unistd.h>

void	*ft_bzero(void *s, size_t n);

int	main(void)
{
	unsigned char	str[27];
	size_t			i;

	i = -1;
	while ('A' + ++i <= 'Z')
		str[i] = 'A' + i;
	str[i] = '\0';
	i = -1;
	while (++i <= 26)
	{
		if (bzero(str, i) != ft_bzero(str, i))
		{
			write(1, "   bzero: |", 11);
			write(1, bzero(str, i), 26);
			write(1, "|\n", 2);
			write(1, "ft_bzero: |", 11);
			write(1, ft_bzero(str, i), 26);
			write(1, "|\n", 2);
			return (0);
		}
	}
	write(1, "All tests passed.\n", 18);
	return (0);
}
