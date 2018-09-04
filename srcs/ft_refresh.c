/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_refresh.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 17:28:02 by msukhare          #+#    #+#             */
/*   Updated: 2018/03/08 15:07:14 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void		ft_refresh(int *x, int *y, int put)
{
	char	*clear;

	if (!(clear = tgetstr("cl", NULL)))
		ft_escape("tgetstr fail\n", 1);
	write(0, clear, ft_strlen(clear));
	if (put == 1)
	{
		ft_putlist();
		ft_putcurse(x, y);
	}
}
