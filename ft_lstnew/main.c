/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetay <yetay@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 09:25:32 by yetay             #+#    #+#             */
/*   Updated: 2023/05/18 10:22:27 by yetay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
t_list	*ft_lstnew(void *content);

int	ft_lstnew_isbad(void *content)
{
	t_list *lst;

	lst = ft_lstnew(content);
	if (lst->content == content && lst->next == NULL)
		return (0);
	if (lst->next != NULL)
		ft_putendl_fd("lst->next is not NULL.",2);
	if (lst->content != content)
	{
		ft_putstr_fd("  content: ", 2);
		ft_putendl_fd(content, 2);
		ft_putstr_fd("ft_lstnew: ", 2);
		ft_putendl_fd(lst->content, 2);
	}
	if (lst)
		free(lst);
	return (1);
}

int	main(void)
{
	int	errors;

	errors = 0;
	if (ft_lstnew_isbad("A cat is not a dog."))
		errors++;
	if (ft_lstnew_isbad("\0abc\0"))
		errors++;
	if (ft_lstnew_isbad("\0"))
		errors++;
	if (ft_lstnew_isbad(""))
		errors++;
	if (ft_lstnew_isbad(NULL))
		errors++;
	if (errors == 0)
		ft_putendl_fd("All tests passed.", 2);
	return (0);
}
