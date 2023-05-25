/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetay <yetay@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:08:04 by yetay             #+#    #+#             */
/*   Updated: 2023/05/22 08:01:34 by yetay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <string.h>

int	ft_nodecompare(t_list **lst, void *a)
{
	t_list	*tmp;

	if (strcmp((*lst)->content, a))
	{
		ft_putstr_fd("addr: ", 2);
		ft_putnbr_fd((unsigned int) *lst, 2);
		ft_putstr_fd(" content: ", 2);
		ft_putstr_fd((*lst)->content,2);
		ft_putstr_fd(" =/= ", 2);
		ft_putstr_fd(a, 2);
		ft_putstr_fd(" (expected content); next addr: ", 2);
		ft_putnbr_fd((unsigned int) (*lst)->next, 2);
		ft_putendl_fd("\n", 2);
		return (1);
	}
	if (a)
		free(a);
	tmp = *lst;
	*lst = (*lst)->next;
	if (tmp)
		free(tmp);
	return (0);
}

int	main(void)
{
	int		errors;
	t_list	**lst;
	t_list	*new;
	int		i;

	errors = 0;
	i = 0;
	new = ft_lstnew("0");
	lst = &new;
	while (++i < 8)
		ft_lstadd_back(lst, ft_lstnew(ft_itoa(i)));
	i = -1;
	while ((*lst)->next)
		if (ft_nodecompare(lst, ft_itoa(++i)))
			errors++;
	if (ft_nodecompare(lst, ft_itoa(++i)))
		errors++;
	if (errors == 0)
		ft_putendl_fd("All tests passed.", 2);
	return (0);
}
