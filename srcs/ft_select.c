/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 18:29:08 by msukhare          #+#    #+#             */
/*   Updated: 2018/03/09 14:51:03 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void		ft_select(int *x, int *y)
{
	t_arg	*tmp;

	tmp = g_term.begin_list;
	while (tmp->curse != 1)
		tmp = tmp->next;
	if (tmp->select == 1)
		tmp->select = 0;
	else if (tmp->select == 0)
		tmp->select = 1;
	if (tmp->end != 1)
	{
		(*x) += (ft_strlen(tmp->argu) + 1);
		tmp->curse = 0;
		tmp = tmp->next;
		tmp->curse = 1;
	}
	else
	{
		(*x) = 0;
		(*y) = 0;
		tmp->curse = 0;
		tmp = tmp->next;
		tmp->curse = 1;
	}
	ft_refresh(x, y, 1);
}
