/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mv_curse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 18:04:10 by msukhare          #+#    #+#             */
/*   Updated: 2018/03/09 14:52:44 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static int	ft_getside(char *buff)
{
	int		size;

	size = ft_strlen(buff);
	if (buff[size - 1] == 'C')
		return (RIGHT);
	if (buff[size - 1] == 'D')
		return (LEFT);
	return (0);
}

void		ft_mv_curse(char *buff, int *x, int *y)
{
	t_arg	*tmp;
	int		side;

	side = ft_getside(buff);
	if (side != RIGHT && side != LEFT)
		return ;
	tmp = g_term.begin_list;
	while (tmp->curse != 1)
		tmp = tmp->next;
	ft_mv_left_right(tmp, x, y, side);
	ft_refresh(x, y, 1);
}
