/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetay <yetay@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:38:39 by yetay             #+#    #+#             */
/*   Updated: 2023/05/19 16:15:31 by yetay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lstsize_isbad(int n)
{
	t_list	**lst;
	t_list	*new;
	int		i;

	if (n == 0)
	{
		if (ft_lstsize(NULL) != 0)
			return (1);
		else
			return (0);
	}
	i = -1;
	lst = NULL;
	while (++i < n)
	{
		if (lst)
			ft_lstadd_front(lst, ft_lstnew(ft_itoa(i)));
		else
		{
			new = ft_lstnew(ft_itoa(i));
			lst = &new;
		}
	}
	if (ft_lstsize(*lst) != n)
	{
		ft_putstr_fd("         n: ", 2);
		ft_putnbr_fd(i, 2);
		ft_putendl_fd("", 2);
		ft_putstr_fd("ft_lstsize: ", 2);
		ft_putnbr_fd(i, 2);
		ft_putendl_fd("", 2);
		return (1);
	}
	return (0);
}

int	main(void)
{
	int	errors;
	int	n;

	errors = 0;
	n = -1;
	while (++n < 51)
		if (ft_lstsize_isbad(n))
			errors++;
	if (errors == 0)
		ft_putendl_fd("All tests passed.", 2);
	return (0);
}
