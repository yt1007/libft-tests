/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetay <yetay@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 10:15:18 by yetay             #+#    #+#             */
/*   Updated: 2023/05/25 13:34:28 by yetay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

static void	*ft_addone(void *x)
{
	char	*c;

	c = NULL;
	c = ft_itoa(ft_atoi(x) + 1);
	return (c);
}

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

static int	ft_lstmap_isbad(int n)
{
	t_list	**lf;
	t_list	**lr;
	t_list	*lf_head;
	t_list	*lr_head;
	t_list	*lfm;
	t_list	*lrm;
	t_list	*node;
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
	if (!lf || !*lf || !lr || !*lr)
	{
		ft_putstr_fd("Had trouble building lists with ", 2);
		ft_putnbr_fd(n, 2);
		ft_putendl_fd(" elements.", 2);
		return (2);
	}
	lfm = NULL;
	lrm = NULL;
	lfm = ft_lstmap(*lf, ft_addone, free);
	lrm = ft_lstmap(*lr, ft_addone, free);
	i = 0;
	node = lrm;
	while (++i <= n)
	{
		if (strcmp(node->content, ft_itoa(i)))
		{
			ft_putstr_fd("Add 1 to list of ", 2);
			ft_putnbr_fd(n, 2);
			ft_putstr_fd(" numbers beginning with 0: ", 2);
			ft_putlst(*lr);
			return (1);
		}
		node = node->next;
	}
	node = lfm;
	while (i-- > 1)
	{
		if (strcmp(node->content, ft_itoa(i)))
		{
			ft_putstr_fd("Add 1 to list of ", 2);
			ft_putnbr_fd(n, 2);
			ft_putstr_fd(" numbers ending with 0: ", 2);
			ft_putlst(*lf);
			return (1);
		}
		node = node->next;
	}
	return (0);
}

int	main(void)
{
	int	errors;
	int	i;

	errors = 0;
	i = -1;
	while (++i < 10)
		if (ft_lstmap_isbad(i))
			errors++;
	i--;
	while (++i < 64)
		if (ft_lstmap_isbad(i))
			errors++;
	if (ft_lstmap_isbad(1024))
		errors++;
	if (errors == 0)
		ft_putendl_fd("All tests passed.", 2);
	return (0);
}
