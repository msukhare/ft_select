/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chang_curs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 14:34:24 by msukhare          #+#    #+#             */
/*   Updated: 2018/03/09 16:10:10 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void		ft_inv_curs(void)
{
	char	*to_do;

	if (!(to_do = tgetstr("vi", NULL)))
		ft_escape("tgetstr fail\n", 1);
	write(0, to_do, ft_strlen(to_do));
}

void		ft_vis_curs(void)
{
	char	*to_do;

	if (!(to_do = tgetstr("ve", NULL)))
		ft_escape("tgetstr fail\n", 1);
	write(0, to_do, ft_strlen(to_do));
}

int			ft_push(t_termo *old_termo)
{
	old_termo->c_lflag &= ~(ICANON);
	old_termo->c_lflag &= ~(ECHO);
	old_termo->c_cc[VMIN] = 1;
	old_termo->c_cc[VTIME] = 0;
	return (tcsetattr(0, TCSANOW, old_termo));
}
