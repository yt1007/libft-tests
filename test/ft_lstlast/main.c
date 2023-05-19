/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetay <yetay@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:43:33 by yetay             #+#    #+#             */
/*   Updated: 2023/05/19 16:58:39 by yetay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

static int	ft_lstlast_isbad(int n)
{
	t_list	**lst;
	t_list	*new;
	t_list	*pl;
	int		i;

	if (n == 0)
	{
		if (ft_lstlast(NULL) != 0)
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
	pl = ft_lstlast(*lst);
	if (pl->next || strcmp(pl->content, "0"))
	{
		ft_putstr_fd("         n: ", 2);
		ft_putnbr_fd(n, 2);
		ft_putendl_fd("", 2);
		ft_putstr_fd("ft_lstlast: ", 2);
		ft_putstr_fd(pl->content, 2);
		ft_putendl_fd("", 2);
		ft_putstr_fd("Expected: ", 2);
		ft_putstr_fd("0", 2);
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
	while (++n < 3)
		if (ft_lstlast_isbad(n))
			errors++;
	if (errors == 0)
		ft_putendl_fd("All tests passed.", 2);
	return (0);
}
