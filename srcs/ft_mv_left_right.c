/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mv_left_right.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 14:29:44 by msukhare          #+#    #+#             */
/*   Updated: 2018/03/09 14:52:31 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static int	ft_lenstart(void)
{
	int		size;
	t_arg	*tmp;

	size = 0;
	tmp = g_term.begin_list;
	while (tmp->end != 1)
	{
		size += (ft_strlen(tmp->argu) + 1);
		tmp = tmp->next;
	}
	return (size);
}

static void	ft_endline(int *x, int *y)
{
	int		size;
	t_arg	*tmp;

	size = 0;
	tmp = g_term.begin_list;
	while (tmp->curse != 1)
	{
		size += (ft_strlen(tmp->argu) + 1);
		tmp = tmp->next;
	}
	(*x) = size;
	(*y)--;
}

void		ft_mv_left_right(t_arg *tmp, int *x, int *y, int side)
{
	if (side == RIGHT)
	{
		if (tmp->end != 1)
			(*x) += (ft_strlen(tmp->argu) + 1);
		else
		{
			(*x) = 0;
			(*y) = 0;
		}
		tmp->curse = 0;
		tmp = tmp->next;
		tmp->curse = 1;
	}
	else if (side == LEFT)
	{
		if (tmp->back->end != 1)
			(*x) -= (ft_strlen(tmp->back->argu) + 1);
		else
			(*x) = ft_lenstart();
		tmp->curse = 0;
		tmp = tmp->back;
		tmp->curse = 1;
		if ((*x) < 0 && (*y) > 0)
			ft_endline(x, y);
	}
}
