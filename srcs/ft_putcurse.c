/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcurse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 17:37:14 by msukhare          #+#    #+#             */
/*   Updated: 2018/03/08 15:08:21 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void			ft_putcurse(int *x, int *y)
{
	char		*mv;
	char		*pos;
	t_term_size	term;

	if ((ioctl(0, TIOCGWINSZ, &term)) < 0)
		ft_escape("ioctl fail\n", 1);
	if ((*x) > term.ws_col)
	{
		(*x) -= term.ws_col;
		(*y)++;
	}
	if (!(mv = tgetstr("cm", NULL)))
		ft_escape("tgetstr fail\n", 1);
	if (!(pos = tgoto(mv, *x, *y)))
		ft_escape("togoto fail\n", 1);
	write(0, pos, ft_strlen(pos));
}
