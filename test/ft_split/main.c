/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetay <yetay@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 09:49:02 by yetay             #+#    #+#             */
/*   Updated: 2023/05/16 17:32:00 by yetay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "libft.h"

int	ft_count_words(char const *s, char c);
char	**ft_split(char const *s, char c);

/*  Function prints a given string of characters to screen                    */
static void	ft_putstr(char const *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
}

/*  Function loops through a given array of strings, print each string        */
/*           separated by a new line.                                         */
static void	ft_print_array(char **s, int elements, int tofree)
{
	int	i;

	i = 0;
	while (i < elements)
	{
		if (i > 0)
			ft_putstr("\n");
		ft_putstr("        ");
		ft_putstr(s[i]);
		if (tofree)
			free(s[i]);
		i++;
	}
	if (tofree)
		free(s);
	ft_putstr("\n");
}

/*  Function prints information about a test set.                             */
static void	ft_print_test_set(char const *s, char c)
{
	ft_putstr("s: \"");
	ft_putstr(s);
	ft_putstr("\" c: '");
	write(1, &c, 1);
	ft_putstr("'\n");
}

static int	ft_split_isbad(char const *s, char c, char **t)
{
	int		i;
	char	**str;
	int		n;

	str = ft_split(s, c);
	if (str == NULL)
		return (0);
	i = -1;
	while (str[++i] != NULL)
		if (strcmp(str[i], t[i]))
		{
			ft_print_test_set(s, c);
			ft_putstr("Expected array:\n");
			n = 0;
			while (t[n] != NULL)
				n++;
			ft_print_array(t, n, 0);
			ft_putstr("ft_split(s, c):\n");
			n = 0;
			while (str[n] != NULL)
				n++;
			ft_print_array(str, n, 1);
			ft_putstr("==================================================\n");
			return (1);
		}
	return (0);
}

int	main(void)
{
	char	*s;
	char	c;
	int		errors;

	errors = 0;
	s = "";
	c = '\0';
	char	*t1[2] = {s, 0};
	if (ft_split_isbad(s, c, t1))
		errors++;
	s = "abcdefghijklmnopqrstuvwxyz";
	t1[0] = s;
	if (ft_split_isbad(s, c, t1))
		errors++;
	if (ft_split_isbad(s, ',', t1))
		errors++;
	t1[0] = "bcdefghijklmnopqrstuvwxyz";
	if (ft_split_isbad(s, 'a', t1))
		errors++;
	t1[0] = "abcdefghijklmnopqrstuvwxy";
	if (ft_split_isbad(s, 'z', t1))
		errors++;
	char	*t2[3] = {"abcdefgh", "jklmnopqrstuvwxyz", 0};
	if (ft_split_isbad(s, 'i', t2))
		errors++;
	t2[0] = "abcdefghijklmnopqrs";
	t2[1] = "uvwxyz";
	if (ft_split_isbad(s, 't', t2))
		errors++;
	s = "abcdefghijklmnopqrsssttttuvwxyz";
	c = 't';
	t2[0] = "abcdefghijklmnopqrsss";
	t2[1] = "uvwxyz";
	if (ft_split_isbad(s, c, t2))
		errors++;
	s = "This is a f*cking long a$$ string of characters.";
	c = 0;
	t1[0] = s;
	if (ft_split_isbad(s, c, t1))
		errors++;
	c = '$';
	t2[0] = "This is a f*cking long a";
	t2[1] = " string of characters.";
	if (ft_split_isbad(s, c, t2))
		errors++;
	c = ' ';
	char	*t3[10] = {"This", "is", "a", "f*cking", "long", "a$$", "string",
		"of", "characters.", 0};
	if (ft_split_isbad(s, c, t3))
		errors++;
	if (ft_split_isbad(0, 0, 0))
		errors++;
	if (errors == 0)
		ft_putstr("All tests passed.\n");
	return (0);
}
