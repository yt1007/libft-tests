/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetay <yetay@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 10:33:18 by yetay             #+#    #+#             */
/*   Updated: 2023/05/19 13:34:05 by yetay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <string.h>

int	main(void)
{
	int		errors;
	t_list	**lst;
	t_list	*new;
	t_list	*tmp;
	int		i;
	char	*a;

	errors = 0;
	i = 0;
	new = ft_lstnew("0");
	lst = &new;
	while (++i < 8)
		ft_lstadd_front(lst, ft_lstnew(ft_itoa(i)));
	while ((*lst)->next)
	{
		a = ft_itoa(--i);
		if (strcmp((*lst)->content, a))
		{
			ft_putstr_fd(" current: ", 2);
			ft_putendl_fd((*lst)->content,2);
			ft_putstr_fd("expected: ", 2);
			ft_putendl_fd(a, 2);
			errors++;
		}
		if (a)
			free(a);
		tmp = *lst;
		*lst = (*lst)->next;
		if (tmp)
			free(tmp);
	}
	if (errors == 0)
		ft_putendl_fd("All tests passed.", 2);
	return (0);
}
