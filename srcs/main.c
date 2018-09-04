/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 10:05:53 by msukhare          #+#    #+#             */
/*   Updated: 2018/03/09 14:49:50 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static void	ft_openshell(void)
{
	char	*term;

	if (!(term = getenv("TERM")))
	{
		ft_putstr_fd("TERM not set\n", 2);
		exit(1);
	}
	if (ft_strlen(term) == 0)
	{
		ft_putstr_fd("TERM is empty\n", 2);
		exit(1);
	}
	if ((tgetent(NULL, term)) < 0)
	{
		ft_putstr_fd("tgetent fail\n", 2);
		exit(1);
	}
}

int			main(int argc, char **argv)
{
	t_termo	new_termo;

	ft_getallsignal();
	if (argc <= 1)
	{
		ft_putstr_fd("usage : \n ./ft_select [arg...]\n", 2);
		return (0);
	}
	ft_openshell();
	if ((tcgetattr(0, &g_term.termi)) < 0 || (tcgetattr(0, &new_termo)) < 0 ||
			ft_push(&new_termo) < 0)
	{
		ft_putstr_fd("tcgetattr or tcsetattr fail\n", 2);
		return (-1);
	}
	if (!(g_term.begin_list = ft_creatlist(argv)))
		ft_escape("malloc fail\n", 1);
	ft_inv_curs();
	ft_readcmd();
	return (0);
}
