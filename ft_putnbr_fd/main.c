/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetay <yetay@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:44:00 by yetay             #+#    #+#             */
/*   Updated: 2023/05/25 16:52:33 by yetay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>

int	ft_putnbr_fd_isbad(int n)
{
	int		fd;
	char	a[15];
	char	b[15];
	int		i;

	fd = open(".test.ft_putnbr_fd.fd", O_WRONLY | O_CREAT);
	i = -1;
	while (++i < 15)
	{
		a[i] = 0;
		b[i] = 0;
	}
	ft_strlcat(a, ft_itoa(n), ft_strlen(ft_itoa(n)) + 1);
	a[ft_strlen(ft_itoa(n))] = 0;
	if (fd == -1)
		return (0);
	ft_putnbr_fd(n, fd);
	write(fd, "\n", 2);
	close(fd);
	fd = open(".test.ft_putnbr_fd.fd", O_RDONLY);
	if (fd == -1)
		return (0);
	i = 0;
	while (read(fd, &b[i], 1))
		i++;
	b[i] = 0;
	b[ft_strlen(ft_itoa(n))] = 0;
	close(fd);
	unlink(".test.ft_putnbr_fd.fd");
	if (strcmp(a, b))
	{
		ft_putstr_fd("n: |", 2);
		ft_putstr_fd(a, 2);
		ft_putstr_fd("|\t ft_putnbr_fd: |", 2);
		ft_putstr_fd(b, 2);
		ft_putendl_fd("|", 2);
		return (1);
	}
	return (0);
}

int	main(void)
{
	int	errors;
	int	i;

	errors = 0;
	i = -20;
	if (ft_putnbr_fd_isbad(INT_MIN))
		errors++;
	while (++i < 20)
		if (ft_putnbr_fd_isbad(i))
			errors++;
	if (ft_putnbr_fd_isbad(INT_MAX))
		errors++;
	if (errors == 0)
	{
		ft_putchar_fd('A', 2);
		ft_putnbr_fd(11, 2);
		ft_putendl_fd(" tests passed.", 2);
	}
	return (0);
}
