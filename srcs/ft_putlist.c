/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 17:32:12 by msukhare          #+#    #+#             */
/*   Updated: 2018/03/09 14:51:31 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static void	ft_underscor(int start)
{
	char	*to_do;

	if (start == 1)
	{
		if (!(to_do = tgetstr("us", NULL)))
			ft_escape("tgetstr fail\n", 1);
	}
	else if (start == 0)
	{
		if (!(to_do = tgetstr("ue", NULL)))
			ft_escape("tgetstr fail\n", 1);
	}
	write(0, to_do, ft_strlen(to_do));
}

static void	ft_putcolor(t_arg *to_put)
{
	ft_putstr_fd("\033[47m", 0);
	ft_putstr_fd("\033[30m", 0);
	ft_putstr_fd(to_put->argu, 0);
	ft_putstr_fd("\033[0m", 0);
	ft_putstr_fd("\033[0m", 0);
}

void		ft_putlist(void)
{
	t_arg	*tmp;

	tmp = g_term.begin_list;
	while (tmp->end != 1)
	{
		(tmp->curse == 1) ? ft_underscor(1) : 0;
		if (tmp->select == 0)
			ft_putstr_fd(tmp->argu, 0);
		else
			ft_putcolor(tmp);
		(tmp->curse == 1) ? ft_underscor(0) : 0;
		ft_putchar_fd(' ', 0);
		tmp = tmp->next;
	}
	(tmp->curse == 1) ? ft_underscor(1) : 0;
	if (tmp->select == 0)
		ft_putstr_fd(tmp->argu, 0);
	else
		ft_putcolor(tmp);
	(tmp->curse == 1) ? ft_underscor(0) : 0;
}
