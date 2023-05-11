/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetay <yetay@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 07:13:06 by yetay             #+#    #+#             */
/*   Updated: 2023/05/11 09:45:37 by yetay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>
#include <unistd.h>

void	ft_bzero(void *s, size_t n);

int	ft_bzero_isdiff(size_t n)
{
	char	x[30];
	char	y[30];
	size_t	i;

	bzero(x, n);
	ft_bzero(y, n);
	i = -1;
	while (++i < n)
		if (x[i] != y[i] || x[i] != 0)
		{
			write(2, "   bzero: |", 11);
			write(2, x, n);
			write(2, "|\n", 2);
			write(2, "ft_bzero: |", 11);
			write(2, y, n);
			write(2, "|\n\n", 3);
			return (1);
		}
	return (0);
	
}

int	main(void)
{
	int		errors;
	size_t	i;

	errors = 0;
	i = -1;
	while (++i < 30)
		if (ft_bzero_isdiff(i))
			errors++;
	if (errors == 0)
		write(2, "All tests passed.\n", 18);
	return (0);
}
