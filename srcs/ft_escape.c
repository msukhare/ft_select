/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_escape.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 16:35:04 by msukhare          #+#    #+#             */
/*   Updated: 2018/03/09 16:05:17 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void		ft_escape(char *error, int refresh)
{
	(g_term.begin_list) ? ft_dellist() : 0;
	(refresh == 1) ? ft_refresh(0, 0, 0) : 0;
	ft_vis_curs();
	if ((tcsetattr(0, TCSANOW, &g_term.termi)) < 0)
	{
		ft_putstr_fd("tcsetattr fail, hasn't been reinitialized\n", 2);
		exit(1);
	}
	(error) ? ft_putstr_fd(error, 2) : 0;
	exit(1);
}
