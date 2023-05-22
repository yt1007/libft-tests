/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetay <yetay@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:43:33 by yetay             #+#    #+#             */
/*   Updated: 2023/05/23 07:19:29 by yetay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

static void	ft_putlst(t_list *lst)
{
	t_list	*pl;

	pl = lst;
	while (pl->next)
	{
		ft_putstr_fd(pl->content, 2);
		ft_putstr_fd(" ", 2);
		pl = pl->next;
	}
	ft_putendl_fd(pl->content, 2);
}

static void	ft_freelst(t_list *lst)
{
	t_list	*tmp;

	while (lst->next)
	{
		tmp = lst;
		lst = lst->next;
		if (tmp)
			free(tmp);
	}
	if (lst)
		free(lst);
}

int	ft_lstlast_isbad(int n)
{
	t_list	**lf;
	t_list	**lr;
	t_list	*lf_head;
	t_list	*lr_head;
	t_list	*lf_last;
	t_list	*lr_last;
	int		i;

	lf = NULL;
	lr = NULL;
	i = -1;
	while (++i < n)
	{
		if (lf)
			ft_lstadd_front(lf, ft_lstnew(ft_itoa(i)));
		else
		{
			lf_head = ft_lstnew(ft_itoa(i));
			lf = &lf_head;
		}
		if (lr)
			ft_lstadd_back(lr, ft_lstnew(ft_itoa(i)));
		else
		{
			lr_head = ft_lstnew(ft_itoa(i));
			lr = &lr_head;
		}
	}
	lf_last = ft_lstlast(*lf);
	lr_last = ft_lstlast(*lr);
	if (strcmp(lf_last->content, "0") || strcmp(lr_last->content, ft_itoa(n - 1)))
	{
		ft_putstr_fd("Lists with ", 2);
		ft_putnbr_fd(n, 2);
		ft_putendl_fd(" elements:", 2);
		ft_putlst(*lf);
		ft_putlst(*lr);
		if (*lf)
			ft_freelst(*lf);
		if (*lr)
			ft_freelst(*lr);
		return (1);
	}
	if (*lf)
		ft_freelst(*lf);
	if (*lr)
		ft_freelst(*lr);
	return (0);
}

int	main(void)
{
	int	errors;
	int	i;

	errors = 0;
	i = 0;
	while (++i < 64)
		if (ft_lstlast_isbad(i))
			errors++;
	if (ft_lstlast_isbad(1024))
		errors++;
	if (errors == 0)
		ft_putendl_fd("All tests passed.", 2);
	return (0);
}
