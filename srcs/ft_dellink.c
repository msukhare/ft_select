/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dellink.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 19:28:31 by msukhare          #+#    #+#             */
/*   Updated: 2018/03/09 14:56:16 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static void	*ft_find_todel(void)
{
	t_arg	*to_ret;

	to_ret = g_term.begin_list;
	while (to_ret->curse != 1)
		to_ret = to_ret->next;
	return (to_ret);
}

void		ft_dellink(int *x, int *y)
{
	t_arg	*to_del;

	to_del = ft_find_todel();
	to_del->back->next = to_del->next;
	to_del->next->back = to_del->back;
	if (to_del->end == 1)
	{
		(*x) = 0;
		(*y) = 0;
		to_del->back->end = 1;
	}
	if (g_term.begin_list == to_del)
	{
		g_term.begin_list = g_term.begin_list->next;
		if (g_term.begin_list == to_del)
			ft_escape(NULL, 1);
	}
	free(to_del->argu);
	free(to_del);
	to_del->next->curse = 1;
	ft_refresh(x, y, 1);
}
