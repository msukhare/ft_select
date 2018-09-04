/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readcmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 17:24:56 by msukhare          #+#    #+#             */
/*   Updated: 2018/03/09 14:50:29 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void		ft_readcmd(void)
{
	int		x;
	int		y;
	char	buff[5];
	int		ret;

	x = 0;
	y = 0;
	ft_refresh(&x, &y, 1);
	while ((ret = read(0, buff, 4)) >= 0)
	{
		buff[ret] = '\0';
		(!g_term.begin_list) ? ft_escape(NULL, 1) : 0;
		if (buff[0] == 127 || (buff[0] == 27 && buff[1] == 91 &&
				buff[2] == 51 && buff[3] == 126 && buff[4] == '\0'))
			ft_dellink(&x, &y);
		else if (buff[0] == 27 && ret > 1)
			ft_mv_curse(buff, &x, &y);
		else if (buff[0] == 32)
			ft_select(&x, &y);
		else if (buff[0] == 10)
			ft_return();
		else if (buff[0] == 27)
			ft_escape(NULL, 1);
		ft_bzero(buff, 4);
	}
}
