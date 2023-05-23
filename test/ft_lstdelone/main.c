/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetay <yetay@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 07:35:41 by yetay             #+#    #+#             */
/*   Updated: 2023/05/23 14:27:16 by yetay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

static void	ft_putlst(t_list *lst)
{
	t_list	*pl;

	if (!lst)
		return ;
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
		if (tmp->content)
			free(tmp->content);
		if (tmp)
			free(tmp);
	}
	if (lst->content)
		free(lst->content);
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
	t_list	*tmp;
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
	tmp = NULL;
	ft_putstr_fd(ft_itoa((int) tmp), 2);
	ft_putstr_fd("\t", 2);
	ft_putstr_fd(ft_itoa((int) lf), 2);
	ft_putstr_fd("\t", 2);
	ft_putstr_fd(ft_itoa((int) *lf), 2);
	ft_putstr_fd("\t", 2);
	ft_putendl_fd(ft_itoa((int) (*lf)->next), 2);
	tmp = *lf;
	ft_putstr_fd(ft_itoa((int) tmp), 2);
	ft_putstr_fd("\t", 2);
	ft_putstr_fd(ft_itoa((int) lf), 2);
	ft_putstr_fd("\t", 2);
	ft_putstr_fd(ft_itoa((int) *lf), 2);
	ft_putstr_fd("\t", 2);
	ft_putendl_fd(ft_itoa((int) (*lf)->next), 2);
	if (tmp->next)
		*lf = tmp->next;
	else
		lf = NULL;
	ft_putstr_fd(ft_itoa((int) tmp), 2);
	ft_putstr_fd("\t", 2);
	ft_putstr_fd(ft_itoa((int) lf), 2);
	ft_putstr_fd("\t", 2);
	if (lf)
	{
		ft_putstr_fd(ft_itoa((int) *lf), 2);
		ft_putstr_fd("\t", 2);
		ft_putendl_fd(ft_itoa((int) (*lf)->next), 2);
	}
	else
		ft_putendl_fd("", 2);
	ft_lstdelone(tmp, free);
	tmp = *lr;
	if (tmp->next)
		*lr = tmp->next;
	else
		lr = NULL;
	ft_lstdelone(tmp, free);
	if (lf)
		ft_putlst(*lf);
	if (lr)
		ft_putlst(*lr);
	if (lf)
		ft_freelst(*lf);
	if (lr)
		ft_freelst(*lr);
	ft_putendl_fd("", 2);
	return (0);
}

int	main(void)
{
	int	errors;
	int	i;

	errors = 0;
	i = 0;
	while (++i < 6)
		if (ft_lstlast_isbad(i))
			errors++;
//	if (ft_lstlast_isbad(1024))
//		errors++;
	if (errors == 0)
		ft_putendl_fd("All tests passed.", 2);
	return (0);
}
