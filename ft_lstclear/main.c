/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetay <yetay@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 08:41:16 by yetay             #+#    #+#             */
/*   Updated: 2023/05/24 09:54:43 by yetay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

//static void	ft_putlst(t_list *lst)
//{
//	t_list	*pl;
//
//	if (!lst)
//		return ;
//	pl = lst;
//	while (pl->next)
//	{
//		ft_putstr_fd(pl->content, 2);
//		ft_putstr_fd(" ", 2);
//		pl = pl->next;
//	}
//	ft_putendl_fd(pl->content, 2);
//}
//
//static void	ft_freelst(t_list *lst)
//{
//	t_list	*tmp;
//
//	while (lst->next)
//	{
//		tmp = lst;
//		lst = lst->next;
//		if (tmp->content)
//			free(tmp->content);
//		if (tmp)
//			free(tmp);
//	}
//	if (lst->content)
//		free(lst->content);
//	if (lst)
//		free(lst);
//}
//
int	ft_lstclear_isbad(int n)
{
	t_list	**lf;
	t_list	**lr;
	t_list	*lf_head;
	t_list	*lr_head;
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
	ft_lstclear(lf, free);
	if (lf && *lf)
	{
		ft_putstr_fd("lf: ", 2);
		ft_putnbr_fd((unsigned int) lf, 2);
		ft_putstr_fd("\t*lf: ", 2);
		ft_putnbr_fd((unsigned int) *lf, 2);
		ft_putendl_fd("", 2);
		return (1);
	}
	ft_lstclear(lr, free);
	if (lr && *lr)
	{
		ft_putstr_fd("lr: ", 2);
		ft_putnbr_fd((unsigned int) lr, 2);
		ft_putstr_fd("\t*lr: ", 2);
		ft_putnbr_fd((unsigned int) *lr, 2);
		ft_putendl_fd("", 2);
		return (1);
	}
	return (0);
}

int	main(void)
{
	int	errors;
	int	i;

	errors = 0;
	i = -1;
	while (++i < 6)
		if (ft_lstclear_isbad(i))
			errors++;
	i--;
	while (++i < 64)
		if (ft_lstclear_isbad(i))
			errors++;
	if (ft_lstclear_isbad(1024))
		errors++;
	if (errors == 0)
		ft_putendl_fd("All tests passed.", 2);
	return (0);
}
