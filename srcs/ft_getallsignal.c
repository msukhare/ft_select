/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getallsignal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 10:19:01 by msukhare          #+#    #+#             */
/*   Updated: 2018/03/09 14:39:47 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void			ft_catch(int n)
{
	n = 0;
	ft_escape(NULL, 1);
}

void			ft_getallsignal(void)
{
	int			sig;

	sig = 1;
	while (sig < 32)
	{
		if (sig == 1 || sig == 2 || sig == 3 || sig == 4 || sig == 5 ||
				sig == 6 || sig == 7 || sig == 8 || sig == 9 || sig == 10 ||
				sig == 11 || sig == 12 || sig == 13 || sig == 14 || sig == 15 ||
				sig == 24 || sig == 25 || sig == 26 || sig == 27 || sig == 30 ||
				sig == 31)
			signal(sig, ft_catch);
		sig++;
	}
	signal(SIGTSTP, ft_catch_ctrz);
	signal(SIGCONT, ft_backto_fct);
	signal(SIGWINCH, ft_redimterm);
}
