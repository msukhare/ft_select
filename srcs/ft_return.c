/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 17:58:05 by msukhare          #+#    #+#             */
/*   Updated: 2018/03/09 14:51:12 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void		ft_return(void)
{
	t_arg	*tmp;

	tmp = g_term.begin_list;
	ft_refresh(0, 0, 0);
	while (tmp->end != 1)
	{
		if (tmp->select == 1)
		{
			ft_putstr(tmp->argu);
			ft_putchar(' ');
		}
		tmp = tmp->next;
	}
	if (tmp->select == 1)
		ft_putstr(tmp->argu);
	ft_escape(NULL, 0);
}
