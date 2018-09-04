/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freetab_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 17:21:33 by msukhare          #+#    #+#             */
/*   Updated: 2018/03/09 14:54:58 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void		ft_dellist(void)
{
	t_arg	*tmp;
	t_arg	*begin_list;

	begin_list = g_term.begin_list;
	while (begin_list->end == 0)
	{
		tmp = begin_list;
		begin_list = begin_list->next;
		(tmp->argu) ? free(tmp->argu) : 0;
		(tmp) ? free(tmp) : 0;
		tmp->argu = NULL;
		tmp = NULL;
	}
	free(begin_list->argu);
	free(begin_list);
	begin_list->argu = NULL;
	begin_list = NULL;
}
