/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetay <yetay@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 07:35:41 by yetay             #+#    #+#             */
/*   Updated: 2023/05/24 08:05:47 by yetay            ###   ########.fr       */
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

int	ft_lstdelone_isbad(int n)
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
	if (n == 0 && lf == NULL && lr == NULL)
		return (0);
	lf_last = ft_lstlast(*lf);
	lr_last = ft_lstlast(*lr);
	tmp = NULL;
//	ft_putstr_fd(ft_itoa((int) tmp), 2);
//	ft_putstr_fd("\t", 2);
//	ft_putstr_fd(ft_itoa((int) lf), 2);
//	ft_putstr_fd("\t", 2);
//	ft_putstr_fd(ft_itoa((int) *lf), 2);
//	ft_putstr_fd("\t", 2);
//	ft_putendl_fd(ft_itoa((int) (*lf)->next), 2);
	tmp = *lf;
//	ft_putstr_fd(ft_itoa((int) tmp), 2);
//	ft_putstr_fd("\t", 2);
//	ft_putstr_fd(ft_itoa((int) lf), 2);
//	ft_putstr_fd("\t", 2);
//	ft_putstr_fd(ft_itoa((int) *lf), 2);
//	ft_putstr_fd("\t", 2);
//	ft_putendl_fd(ft_itoa((int) (*lf)->next), 2);
	if (tmp == lf_last)
		lf = NULL;
	else
	{
		while (tmp->next != lf_last)
			tmp = tmp->next;
		tmp->next = NULL;
//		ft_putstr_fd(ft_itoa((int) tmp), 2);
//		ft_putstr_fd("\t", 2);
//		ft_putstr_fd(tmp->content, 2);
//		ft_putstr_fd("\t", 2);
//		ft_putstr_fd(ft_itoa((int) tmp->next), 2);
//		ft_putstr_fd("\t", 2);
//		ft_putstr_fd(ft_itoa((int) lf_last), 2);
//		ft_putstr_fd("\t", 2);
//		ft_putstr_fd(lf_last->content, 2);
//		ft_putstr_fd("\t", 2);
//		ft_putendl_fd(ft_itoa((int) lf_last->next), 2);
	}
	ft_lstdelone(lf_last, free);
	if (lf && *lf)
	   if (strcmp((*lf)->content, ft_itoa(n - 1)) || strcmp(tmp->content, "1"))
		{
			ft_putstr_fd("Del last node from list: ", 2);
			i = n;
			while (--i)
			{
				ft_putnbr_fd(i, 2);
				ft_putstr_fd(" ", 2);
			}
			ft_putendl_fd(ft_itoa(i), 2);
			ft_putstr_fd("          Expected list: ", 2);
			i = n;
			while (--i)
			{
				ft_putnbr_fd(i, 2);
				ft_putstr_fd(" ", 2);
			}
			ft_putendl_fd("", 2);
			ft_putstr_fd("         Resulting list: ", 2);
			if (lf)
				ft_putlst(*lf);
			ft_putendl_fd("", 2);
			return (1);
		}
//	ft_putstr_fd(ft_itoa((int) tmp), 2);
//	ft_putstr_fd("\t", 2);
//	ft_putstr_fd(ft_itoa((int) lf), 2);
//	ft_putstr_fd("\t", 2);
//	if (lf)
//	{
//		ft_putstr_fd(ft_itoa((int) *lf), 2);
//		ft_putstr_fd("\t", 2);
//		ft_putendl_fd(ft_itoa((int) (*lf)->next), 2);
//	}
//	else
//		ft_putendl_fd("", 2);
	tmp = *lr;
	if (tmp == lr_last)
		lr = NULL;
	else
	{
		while (tmp->next != lr_last)
			tmp = tmp->next;
		tmp->next = NULL;
	}
	ft_lstdelone(lr_last, free);
	if (lr && *lr)
	   if (strcmp((*lr)->content, "0") || strcmp(tmp->content, ft_itoa(n - 2)))
		{
			ft_putstr_fd("Del last node from list: ", 2);
			i = n;
			while (--i)
			{
				ft_putnbr_fd(i, 2);
				ft_putstr_fd(" ", 2);
			}
			ft_putendl_fd(ft_itoa(i), 2);
			ft_putstr_fd("          Expected list: ", 2);
			i = n;
			while (--i)
			{
				ft_putnbr_fd(i, 2);
				ft_putstr_fd(" ", 2);
			}
			ft_putendl_fd("", 2);
			ft_putstr_fd("         Resulting list: ", 2);
			if (lr)
				ft_putlst(*lr);
			ft_putendl_fd("", 2);
			return (1);
		}
	if (lf)
		ft_freelst(*lf);
	if (lr)
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
		if (ft_lstdelone_isbad(i))
			errors++;
	if (ft_lstdelone_isbad(1024))
		errors++;
	if (errors == 0)
		ft_putendl_fd("All tests passed.", 2);
	return (0);
}
